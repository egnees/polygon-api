
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/export.h>
#include <cpr/cpr.h>

#include <polygon_api/Account.h>
#include <polygon_api/RawRequester.h>
#include <polygon_api/RequestBuilder.h>
#include <polygon_api/BaseRequester.h>
#include <polygon_api/PolygonSession.h>
#include <polygon_api/Problem.h>
#include <polygon_api/Checker.h>

#include <string>
#include <vector>
#include <algorithm>
#include <utility>

namespace polygon_api {

POLYGON_API_EXPORT struct Account;

POLYGON_API_EXPORT class PolygonSession;
POLYGON_API_EXPORT class Problem;
POLYGON_API_EXPORT class Checker;
POLYGON_API_EXPORT class BaseRequester;
POLYGON_API_EXPORT class RawRequester;
POLYGON_API_EXPORT class RequestBuilder;
POLYGON_API_EXPORT class BaseRequester;

POLYGON_API_EXPORT std::shared_ptr<PolygonSession> GetPolygonSession(const std::string&, const std::string&,
                                                                         const std::string&, const std::string&);

POLYGON_API_EXPORT std::shared_ptr<PolygonSession> GetPolygonSession(const Account&);
} // namespace polygon_api
