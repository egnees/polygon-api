
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#include <polygon_api/polygon_api.h>

namespace polygon_api {

cpr::Response RawRequester::Get(const std::string &method_name, const cpr::Parameters &params_, const cpr::Header &header_) {
    cpr::Response response = cpr::Get(cpr::Url{endpoint_ + method_name}, header_, params_, cookies_);
    if (response.cookies.begin() != response.cookies.end()) {
        cookies_ = response.cookies;
    }
    return response;
}

cpr::Response RawRequester::Post(const std::string &method_name, const cpr::Parameters &params_,
                                 const cpr::Header &header_, const cpr::Payload &payload_) {
    cpr::Response response = cpr::Post(cpr::Url{endpoint_ + method_name}, header_, payload_, params_, cookies_);
    if (response.cookies.begin() != response.cookies.end()) {
        cookies_ = response.cookies;
    }
    return response;
}

} // namespace polygon_api
