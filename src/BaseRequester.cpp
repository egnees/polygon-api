
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/BaseRequester.h>

namespace polygon_api {

cpr::Header BaseRequester::GetHeaderFromRecords(const Records &records) {
    cpr::Header header;
    for (const auto &[name, value] : records) {
        header.emplace(name, value);
    }
    return header;
}

cpr::Parameters BaseRequester::GetParamsFromRecords(const Records &records) {
    cpr::Parameters params;
    for (const auto &[name, value] : records) {
        params.Add({name, value});
    }
    return params;
}

cpr::Payload BaseRequester::GetPayloadFromRecords(const Records &records) {
    std::vector<cpr::Pair> pairs;
    pairs.reserve(records.size());
    for (const auto &[name, value] : records) {
        pairs.emplace_back(name, value);
    }
    return {pairs.begin(), pairs.end()};
}

cpr::Response BaseRequester::Get(const std::string &method_name, const cpr::Parameters &params, const cpr::Header &header) {
    cpr::Response response = cpr::Get(cpr::Url{endpoint_ + method_name}, header, params, cookies_);
    if (response.cookies.begin() != response.cookies.end()) {
        cookies_ = response.cookies;
    }
    return response;
}

cpr::Response BaseRequester::Post(const std::string &method_name, const cpr::Parameters &params,
                                  const cpr::Header &header, const cpr::Payload &payload) {
    cpr::Response response = cpr::Post(cpr::Url{endpoint_ + method_name}, header, payload, params, cookies_);
    if (response.cookies.begin() != response.cookies.end()) {
        cookies_ = response.cookies;
    }
    return response;
}

} // namespace polygon_api