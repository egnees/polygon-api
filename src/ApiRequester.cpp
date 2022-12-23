
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#include <polygon_api/ApiRequester.h>

#include <chrono>
#include <random>
#include <algorithm>

namespace polygon_api {

typedef std::vector<std::pair<std::string, std::string>> Records;

Records ApiRequester::ExtendWithApiPayload(
        Records payload, const std::string &method_name) {
    payload.emplace_back("apiKey", key_);
    payload.emplace_back("time", std::to_string(std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count()));
    payload.emplace_back("apiSig", MakeApiSig(payload, method_name));
    return payload;
}

std::string ApiRequester::MakeApiSig(
        Records params, const std::string &method_name) {
    std::mt19937 rand(std::chrono::system_clock::now().time_since_epoch().count());
    std::string random_6_chars;
    for (int i = 0; i < 6; ++i) {
        random_6_chars.push_back(rand() % 26 + 'a');
    }

    std::string api_sig = random_6_chars + "/" + method_name + "?";
    std::sort(params.begin(), params.end());
    for (const auto &[name, value] : params) {
        api_sig += "&";
        api_sig += name;
        api_sig += "=";
        api_sig += value;
    }
    api_sig += "#";
    api_sig += secret_;
    return random_6_chars + encoder_.hash(api_sig);
}

cpr::Response ApiRequester::Post(const std::string &method_name,
                                 const Records &params,
                                 const Records &header,
                                 const Records &payload) {
    Records extended_payload = ExtendWithApiPayload(payload, method_name);
    return BaseRequester::Post(method_name,
                BaseRequester::GetParamsFromRecords(params),
                BaseRequester::GetHeaderFromRecords(header),
                BaseRequester::GetPayloadFromRecords(extended_payload));
}

cpr::Response ApiRequester::Get(const std::string &method_name,
                                const Records &params,
                                const Records &header) {
    Records extended_payload = ExtendWithApiPayload(params, method_name);
    return BaseRequester::Post(method_name,
                              BaseRequester::GetParamsFromRecords(params),
                              BaseRequester::GetHeaderFromRecords(header),
                              BaseRequester::GetPayloadFromRecords(extended_payload));
}

} // namespace polygon_api