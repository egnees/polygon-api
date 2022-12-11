
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>

#include <iostream>

int main(int, char*[]) {
    std::shared_ptr<polygon_api::PolygonSession> ptr = nullptr;
    try {
        ptr = polygon_api::GetPolygonSession("egnees", "fd8a13031775c9d12bedefad444381e3", "3", "4");
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
    if (ptr && ptr->IsAuthRawSuccess()) {
        std::cout << "success!";
    } else {
        std::cout << "fail!";
    }
    return 0;
}