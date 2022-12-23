
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include <iostream>
#include <cassert>

#include "../utils/EnvReader.cpp"

int main() {
    std::shared_ptr<polygon_api::PolygonSession> success_auth = nullptr; // should be successful
    try {
        success_auth = polygon_api::GetPolygonSession(EnvReader::Read());
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    if (success_auth) {
        assert(success_auth->IsAuthRawSuccess());
        std::cout << "success, as expected!" << std::endl;
    } else {
        std::cout << "fail, unexpected!" << std::endl;
    }

    std::shared_ptr<polygon_api::PolygonSession> fail_auth = nullptr; // should fail

    try {
        fail_auth = polygon_api::GetPolygonSession("some_login", "password", "api_key", "api_secret");
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    if (fail_auth) {
        assert(fail_auth->IsAuthRawSuccess());
        std::cout << "success, unexpected!" << std::endl;
    } else {
        std::cout << "fail, as expected!" << std::endl;
    }

    return 0;
}