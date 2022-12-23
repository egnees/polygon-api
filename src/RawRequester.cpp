
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/RawRequester.h>

namespace polygon_api {

typedef std::vector<std::pair<std::string, std::string>> Records;

cpr::Response RawRequester::Get(const std::string &method_name, const Records &params, const Records &header) {
    return BaseRequester::Get(method_name,
                              BaseRequester::GetParamsFromRecords(params),
                              BaseRequester::GetHeaderFromRecords(header));
}

cpr::Response RawRequester::Post(const std::string &method_name,
                                 const Records &params,
                                 const Records &header,
                                 const Records &payload) {
    return BaseRequester::Post(method_name,
                              BaseRequester::GetParamsFromRecords(params),
                              BaseRequester::GetHeaderFromRecords(header),
                              BaseRequester::GetPayloadFromRecords(payload));
}

} // namespace polygon_api
