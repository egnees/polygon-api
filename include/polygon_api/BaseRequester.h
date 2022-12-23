
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#pragma once

#include <polygon_api/polygon_api.h>

#include <utility>

#ifndef POLYGON_API_BASEREQUESTER_H
#define POLYGON_API_BASEREQUESTER_H

namespace polygon_api {

class BaseRequester {
    typedef std::vector<std::pair<std::string, std::string>> Records;
public:
    explicit BaseRequester(std::string endpoint) : endpoint_(std::move(endpoint)) {}
    virtual cpr::Response Get(const std::string&,
                              const Records&,
                              const Records&) = 0;
    virtual cpr::Response Post(const std::string&,
                               const Records&,
                               const Records&,
                               const Records&) = 0;

protected:
    std::string endpoint_;

    cpr::Response Get(const std::string&,
                      const cpr::Parameters&,
                      const cpr::Header&);

    cpr::Response Post(const std::string&,
                       const cpr::Parameters&,
                       const cpr::Header&,
                       const cpr::Payload&);

    static cpr::Parameters GetParamsFromRecords(const Records&);
    static cpr::Header GetHeaderFromRecords(const Records&);
    static cpr::Payload GetPayloadFromRecords(const Records&);

    cpr::Cookies cookies_;
};

} // namespace polygon api

#endif //POLYGON_API_BASEREQUESTER_H
