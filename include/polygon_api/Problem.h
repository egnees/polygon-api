
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include <utility>

namespace polygon_api {
    class Problem {
    public:
        enum AccessType {
            READ,
            WRITE,
            OWNER
        };
        Problem(std::shared_ptr<PolygonSession> session, int id, std::string owner, std::string name, bool deleted,
                bool favourite, AccessType access_type, int revision, int latest_package, bool modified) :
                session_(std::move(session)), id_(id), owner_(std::move(owner)), name_(std::move(name)), deleted_(deleted),
                favourite_(favourite), access_type_(access_type), revision_(revision),
                latest_package_(latest_package), modified_(modified) {}
        Problem(std::shared_ptr<PolygonSession>, const std::shared_ptr<JsonObject>&);

        // Getters
        [[nodiscard]] int GetId() const;
        [[nodiscard]] std::string GetOwner() const;
        [[nodiscard]] std::string GetName() const;
        [[nodiscard]] bool IsDeleted() const;
        [[nodiscard]] bool IsFavourite() const;
        [[nodiscard]] AccessType GetAccessType() const;
        [[nodiscard]] int GetRevision() const;
        [[nodiscard]] int GetLatestPackage() const;
        [[nodiscard]] bool IsModified() const;

        // Setters
        // todo
    private:
        int id_{};
        std::string owner_;
        std::string name_;
        bool deleted_{};
        bool favourite_{};
        AccessType access_type_;
        int revision_{};
        int latest_package_{};
        bool modified_{};

        std::map<std::string, AccessType> access_type_map_ = {{"READ", AccessType::READ},
                                                              {"WRITE", AccessType::WRITE},
                                                              {"OWNER", AccessType::OWNER}};

        std::shared_ptr<PolygonSession> session_;
    };
} // namespace polygon_api