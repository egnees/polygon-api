
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <gtest/gtest.h>

TEST(sub_test, sub_test_1_2) {
    ASSERT_EQ(polygon_api::add(1, -2), -1);
}
