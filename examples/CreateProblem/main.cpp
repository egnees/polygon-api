
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 22.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include <iostream>
#include <cassert>

#include "../utils/EnvReader.cpp"

int main() {
    auto session = polygon_api::GetPolygonSession(EnvReader::Read());
    std::cout << (session->IsAuthRawSuccess() ?  "Auth successful\n" : "Failed to auth\n");
    auto problem = session->CreateProblem("abacab12a");
    if (problem) {
        std::cout << "Problem successfuly created\n";
    } else {
        std::cout << "Failed to create problem\n";
    }
    return 0;
}