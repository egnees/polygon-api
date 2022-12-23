
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#ifndef POLYGON_API_RAWPOLYGONREQUESTER_H
#define POLYGON_API_RAWPOLYGONREQUESTER_H

#include <polygon_api/BaseRequester.h>

namespace polygon_api {

class RawRequester : public BaseRequester {
    typedef std::vector<std::pair<std::string, std::string>> Records;
public:
    explicit RawRequester(const std::string &endpoint) : BaseRequester(endpoint) {}

    cpr::Response Get(const std::string&, const Records&, const Records&) override;
    cpr::Response Post(const std::string&, const Records&, const Records&, const Records&) override;
};

} // namespace polygon_api

#endif //POLYGON_API_RAWPOLYGONREQUESTER_H
