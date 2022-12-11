
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#pragma once

#include <polygon_api/polygon_api.h>

#ifndef POLYGON_API_BASEREQUESTER_H
#define POLYGON_API_BASEREQUESTER_H

namespace polygon_api {

class BaseRequester {
public:
    BaseRequester(const std::string& endpoint) : endpoint_(endpoint) {}
    virtual cpr::Response Get(const std::string&, const cpr::Parameters&, const cpr::Header&) = 0;
    virtual cpr::Response Post(const std::string&, const cpr::Parameters&, const cpr::Header&, const cpr::Payload&) = 0;

protected:
    std::string endpoint_;
};

} // namespace polygon api

#endif //POLYGON_API_BASEREQUESTER_H
