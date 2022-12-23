
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include "../utils/EnvReader.cpp"

int main() {
    auto session = polygon_api::GetPolygonSession(EnvReader::Read());
    session->GetProblemsList("", "", "");
    return 0;
}