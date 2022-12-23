
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/polygon_api.h>

#include <utility>

namespace polygon_api {
    class Problem {
    public:
        enum AccessType {
            READ,
            WRITE,
            OWNER
        };
        Problem(std::shared_ptr<PolygonSession> session, cpr::Response api_response) : session_(std::move(session)) {}
        Problem(std::shared_ptr<PolygonSession> session, std::string exists_id) : session_(std::move(session)) {}
        Problem(std::shared_ptr<PolygonSession> session, std::string id, std::string owner, std::string name, bool deleted, bool favourite, AccessType access_type,
                std::string revision, std::string latest_package, bool modified) :
                session_(std::move(session)), id_(std::move(id)), owner_(std::move(owner)), name_(std::move(name)), deleted_(deleted),
                favourite_(favourite), access_type_(access_type), revision_(std::move(revision)),
                latest_package_(std::move(latest_package)), modified_(modified) {}
    private:
        std::string id_;
        std::string owner_;
        std::string name_;
        bool deleted_;
        bool favourite_;
        AccessType access_type_;
        std::string revision_;
        std::string latest_package_;
        bool modified_;

        std::shared_ptr<PolygonSession> session_;
    };
} // namespace polygon_api