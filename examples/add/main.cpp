
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>

#include <iostream>

int main(int, char*[]) {
    auto sum = polygon_api::add(1, 1);
    std::cout << sum << std::endl;
    return 0;
}