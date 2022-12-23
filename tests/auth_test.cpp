
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 13.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>

#include <gtest/gtest.h>

#include "../utils/EnvReader.cpp"

TEST(auth_test, full_auth_works) {
    auto session = polygon_api::GetPolygonSession(EnvReader::Read("../../env.txt"));
    ASSERT_TRUE(session != nullptr);
    ASSERT_TRUE(session->IsAuthRawSuccess());
}

TEST(auth_test, twice_auth_works) {
    auto session1 = polygon_api::GetPolygonSession(EnvReader::Read("../../env.txt"));
    ASSERT_TRUE(session1 != nullptr);
    ASSERT_TRUE(session1->IsAuthRawSuccess());

    auto session2 = polygon_api::GetPolygonSession(EnvReader::Read("../../env.txt"));
    ASSERT_TRUE(session2 != nullptr);
    ASSERT_TRUE(session2->IsAuthRawSuccess());
}