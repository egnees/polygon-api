
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 11.12.2022.
//

#ifndef POLYGON_API_ACCOUNT_H
#define POLYGON_API_ACCOUNT_H

#include <polygon_api/polygon_api.h>

namespace polygon_api {

struct Account {
    std::string login_;
    std::string password_;
    std::string key_;
    std::string secret_;

    Account(std::string login, std::string password, std::string key, std::string secret)
            : login_(std::move(login)), password_(std::move(password)), key_(std::move(key)), secret_(std::move(secret)) {}
};

} // namespace polygon_api

#endif //POLYGON_API_ACCOUNT_H
