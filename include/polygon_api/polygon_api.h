
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/export.h>
#include <cpr/cpr.h>

#include <string>
#include <vector>
#include <algorithm>
#include <utility>

namespace polygon_api {

POLYGON_API_EXPORT struct Account;

POLYGON_API_EXPORT class SHA512;
POLYGON_API_EXPORT class BaseRequester;
POLYGON_API_EXPORT class RawRequester;
POLYGON_API_EXPORT class ApiRequester;
POLYGON_API_EXPORT class PolygonSession;
POLYGON_API_EXPORT class RequestBuilder;
POLYGON_API_EXPORT class BaseRequester;
POLYGON_API_EXPORT class Problem;
POLYGON_API_EXPORT class Checker;

POLYGON_API_EXPORT std::shared_ptr<PolygonSession> GetPolygonSession(const std::string&, const std::string&,
                                                                         const std::string&, const std::string&);

POLYGON_API_EXPORT std::shared_ptr<PolygonSession> GetPolygonSession(const Account&);
} // namespace polygon_api
