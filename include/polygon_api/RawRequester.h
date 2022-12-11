
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#ifndef POLYGON_API_RAWPOLYGONREQUESTER_H
#define POLYGON_API_RAWPOLYGONREQUESTER_H

#include <polygon_api/BaseRequester.h>

namespace polygon_api {

POLYGON_API_EXPORT class RawRequester : public BaseRequester {
public:
    RawRequester(const std::string &endpoint) : BaseRequester(endpoint), cookies_() {}
    cpr::Response Get(const std::string&, const cpr::Parameters&, const cpr::Header&) override;
    cpr::Response Post(const std::string&, const cpr::Parameters&, const cpr::Header&, const cpr::Payload&) override;
private:
    cpr::Cookies cookies_;
};

} // namespace polygon_api

#endif //POLYGON_API_RAWPOLYGONREQUESTER_H
