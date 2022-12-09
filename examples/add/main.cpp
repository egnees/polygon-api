
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>

#include <iostream>

int main(int, char*[]) {
    auto session = polygon_api::GetPolygonSession("hello", "world", "i am", "egnees");
    std::cout << session->p.checker.name_ << '\n';
    return 0;
}