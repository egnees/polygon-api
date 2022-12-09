
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <polygon_api/polygon_api.h>

#include <gtest/gtest.h>

TEST(add_test, add_test_1_1) {
    ASSERT_EQ(polygon_api::add(1, 1), 2);
}

TEST(sub_test, add_test_1__1) {
    ASSERT_EQ(polygon_api::add(1, -1), 0);
}