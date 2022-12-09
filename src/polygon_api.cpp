
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <cpr/cpr.h>

namespace polygon_api {
    std::shared_ptr<PolygonSession> GetPolygonSession(const std::string& login, const std::string& password,
                                                                         const std::string& key, const std::string& secret) {
        return std::make_shared<PolygonSession>(login, password, key, secret);
    }
}
