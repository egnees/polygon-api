
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include "../utils/EnvReader.cpp"

#include <iostream>

int main() {
    auto session = polygon_api::GetPolygonSession(EnvReader::Read());
    auto problemsList = session->GetProblemsList(0, "", "");
    std::cout << "You have " << problemsList.size() << " problems which names are:\n";
    for (const auto &problem : problemsList) {
        std::cout << problem->GetName() << '\n';
    }
    return 0;
}