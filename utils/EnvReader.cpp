
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 11.12.2022.
//

#include "EnvReader.h"

#include <fstream>
#include <string>

namespace EnvReader {

polygon_api::Account Read() {
    std::ifstream fin;
    try {
        fin.open(".env");
    } catch (...) {
        throw std::runtime_error("cant open file .env");
    }
    auto read_token = [&fin](std::string& dest, const std::string& token_name) {
        try {
            fin >> dest;
        } catch (...) {
            throw std::runtime_error("cant read token " + token_name);
        }
    };
    auto read_line_with_token = [&fin, read_token](std::string& dest, const std::string& token_name) {
        std::string token_def;
        std::string sign_eq;
        read_token(token_def, token_name + " definition");
        read_token(sign_eq, token_name + " sign equal");
        read_token(dest, token_name);
    };
    std::string login, password, key, secret;
    try {
        read_line_with_token(login, "login");
        read_line_with_token(password, "password");
        read_line_with_token(key, "key");
        read_line_with_token(secret, "secret");
    } catch(std::runtime_error& e) {
        throw std::runtime_error("unexpected format of .env file; " + std::string(e.what()));
    }

    return {login, password, key, secret};
}

} // namespace EnvReader