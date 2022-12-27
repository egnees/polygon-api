
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 27.12.2022.
//

#include <polygon_api/Problem.h>
#include <json/JsonObject.h>
#include <json/JsonParser.h>

namespace polygon_api {
Problem::Problem(std::shared_ptr<PolygonSession> session, const std::shared_ptr<JsonObject>& jsonProblem) {
    try {
        session_ = std::move(session);
        id_ = As<JsonNumber>(jsonProblem->Get("id"))->Get();
        owner_ = As<JsonString>(jsonProblem->Get("owner"))->Get();
        name_ = As<JsonString>(jsonProblem->Get("name"))->Get();
        deleted_ = As<JsonBoolean>(jsonProblem->Get("deleted"))->Get();
        favourite_ = As<JsonBoolean>(jsonProblem->Get("favourite"))->Get();
        {
            std::string access_type = As<JsonString>(jsonProblem->Get("accessType"))->Get();
            if (!access_type_map_.count(access_type)) {
                throw std::runtime_error("there is no such access type as " + access_type);
            }
            access_type_ = access_type_map_[As<JsonString>(jsonProblem->Get("accessType"))->Get()];
        }
        revision_ = As<JsonNumber>(jsonProblem->Get("revision"))->Get();
        try {
            latest_package_ = As<JsonNumber>(jsonProblem->Get("latestPackage"))->Get();
        } catch (...) {}
        modified_ = As<JsonBoolean>(jsonProblem->Get("modified"))->Get();
    } catch (...) {}
}

int Problem::GetId() const {
    return id_;
}

std::string Problem::GetOwner() const {
    return owner_;
}

std::string Problem::GetName() const {
    return name_;
}

bool Problem::IsDeleted() const {
    return deleted_;
}

bool Problem::IsFavourite() const {
    return favourite_;
}

Problem::AccessType Problem::GetAccessType() const {
    return access_type_;
}

int Problem::GetRevision() const {
    return revision_;
}

int Problem::GetLatestPackage() const {
    return latest_package_;
}

bool Problem::IsModified() const {
    return modified_;
}

} // namespace polygon_api