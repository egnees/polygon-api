
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/export.h>
#include <polygon_api/PolygonSession.h>

namespace polygon_api {
    POLYGON_API_EXPORT std::shared_ptr<PolygonSession> GetPolygonSession(const std::string&, const std::string&,
                                                                         const std::string&, const std::string&);
}
