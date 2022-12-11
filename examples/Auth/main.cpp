
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>

#include <iostream>

#include "../utils/EnvReader.cpp"

int main(int, char*[]) {
    std::shared_ptr<polygon_api::PolygonSession> ptr = nullptr;
    try {
        auto ac = EnvReader::Read();
        ptr = polygon_api::GetPolygonSession(ac);
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    if (ptr) {
        std::cout << "success!" << std::endl;
    } else {
        std::cout << "fail!" << std::endl;
    }
    return 0;
}