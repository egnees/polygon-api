
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#pragma once

#ifndef POLYGON_API_APIREQUESTER_H
#define POLYGON_API_APIREQUESTER_H

#include <polygon_api/BaseRequester.h>

#include <polygon_api/SHA512.h>

namespace polygon_api {

class ApiRequester : public BaseRequester {
    typedef std::vector<std::pair<std::string, std::string>> Records;
public:
    ApiRequester(const std::string& endpoint, const std::string& key, const std::string& secret)
    : BaseRequester(endpoint), key_(key), secret_(secret), encoder_() {}

    cpr::Response Get(const std::string&, const Records&, const Records&) override;
    cpr::Response Post(const std::string&, const Records&, const Records&, const Records&) override;

private:
    Records ExtendWithApiPayload(Records, const std::string&);
    std::string MakeApiSig(Records, const std::string&);

    std::string key_;
    std::string secret_;

    SHA512 encoder_;
};

} // namespace polygon_api

#endif //POLYGON_API_APIREQUESTER_H
