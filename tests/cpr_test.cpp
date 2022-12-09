
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#include <gtest/gtest.h>
#include <cpr/cpr.h>

TEST(cpr_test, cpr_included) {
    cpr::Response r = cpr::Get(cpr::Url{"vk.com"});
    ASSERT_EQ(r.status_code, 200);
}
