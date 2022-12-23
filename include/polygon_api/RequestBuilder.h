
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#pragma once

#ifndef POLYGON_API_REQUESTBUILD_H
#define POLYGON_API_REQUESTBUILD_H

#include <polygon_api/BaseRequester.h>
#include <polygon_api/polygon_api.h>

namespace polygon_api {

class RequestBuilder : public std::enable_shared_from_this<RequestBuilder> {
    typedef std::vector<std::pair<std::string, std::string>> Records;
public:
    RequestBuilder(std::shared_ptr<BaseRequester>);
    RequestBuilder(std::shared_ptr<BaseRequester>, const std::initializer_list<cpr::Pair>&);

    std::shared_ptr<RequestBuilder> GetSharedPtr();

    std::shared_ptr<RequestBuilder> SetMethodName(const std::string&);
    std::shared_ptr<RequestBuilder> SetParams(const std::initializer_list<cpr::Parameter>&);
    std::shared_ptr<RequestBuilder> SetHeader(const std::initializer_list<cpr::Pair>&);
    std::shared_ptr<RequestBuilder> AddToHeader(const std::initializer_list<cpr::Pair>&);
    std::shared_ptr<RequestBuilder> AddToHeader(const std::string&, const std::string&);
    std::shared_ptr<RequestBuilder> SetPayload(const std::initializer_list<cpr::Pair>&);

    [[nodiscard]] cpr::Response Post() const;
    [[nodiscard]] cpr::Response Get() const;
private:
    std::string method_name_;

    Records params_;
    Records header_;
    Records payload_;

    std::shared_ptr<BaseRequester> requester_;
};

} // namespace polygon_api

#endif //POLYGON_API_REQUESTBUILD_H
