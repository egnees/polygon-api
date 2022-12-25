
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#include <json/JsonParser.h>

#include <gtest/gtest.h>

using namespace std::string_literals;

TEST(json_parser_test, parse_string) {
    JsonParser parser("\"hello\"");
    auto res = parser.Parse();
    ASSERT_TRUE(Is<JsonString>(res));
    ASSERT_EQ(As<JsonString>(res)->Get(), "hello");
}

TEST(json_parser_test, parse_number) {
    JsonParser parser("553535");
    auto res = parser.Parse();
    ASSERT_TRUE(Is<JsonNumber>(res));
    ASSERT_EQ(As<JsonNumber>(res)->Get(), 553535);
}

TEST(json_parser_test, parse_boolean) {
    JsonParser parser("true");
    auto res = parser.Parse();
    ASSERT_TRUE(Is<JsonBoolean>(res));
    ASSERT_EQ(As<JsonBoolean>(res)->Get(), true);
}

TEST(json_parser_test, parse_object_simple) {
    JsonParser parser("{"
                      "     \"hello\" : 555"
                      "}");
    std::shared_ptr<JsonTemplate> res;
    ASSERT_NO_THROW(res = parser.Parse());
    ASSERT_TRUE(Is<JsonObject>(res));
    ASSERT_NO_THROW(As<JsonObject>(res)->Get("hello"));
    ASSERT_TRUE(Is<JsonNumber>(As<JsonObject>(res)->Get("hello")));
    ASSERT_EQ(As<JsonNumber>(As<JsonObject>(res)->Get("hello"))->Get(), 555);
}

TEST(json_parser_test, parse_list_simple) {
    JsonParser parser("[ 1, 2, \"HA\", false, 3 ]");
    std::shared_ptr<JsonTemplate> res;
    ASSERT_NO_THROW(res = parser.Parse());

    ASSERT_TRUE(Is<JsonList>(res));
    std::shared_ptr<JsonList> list = As<JsonList>(res);

    ASSERT_EQ(list->Size(), 5);

    ASSERT_TRUE(Is<JsonNumber>(list->Get(0)));
    ASSERT_EQ(As<JsonNumber>(list->Get(0))->Get(), 1);

    ASSERT_TRUE(Is<JsonNumber>(list->Get(1)));
    ASSERT_EQ(As<JsonNumber>(list->Get(1))->Get(), 2);

    ASSERT_TRUE(Is<JsonString>(list->Get(2)));
    ASSERT_EQ(As<JsonString>(list->Get(2))->Get(), "HA");

    ASSERT_TRUE(Is<JsonBoolean>(list->Get(3)));
    ASSERT_EQ(As<JsonBoolean>(list->Get(3))->Get(), false);

    ASSERT_TRUE(Is<JsonNumber>(list->Get(4)));
    ASSERT_EQ(As<JsonNumber>(list->Get(4))->Get(), 3);
}

TEST(json_parser_test, parse_polygon_answer) {
    std::string answer{R"({
                  "status": "OK",
                  "result": [
                    {
                      "id": 257076,
                      "owner": "m3owp1mp",
                      "name": "test-problem371453",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257075,
                      "owner": "m3owp1mp",
                      "name": "test-problem414345",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257074,
                      "owner": "m3owp1mp",
                      "name": "test-problem535896",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257073,
                      "owner": "m3owp1mp",
                      "name": "test-problem997991",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257068,
                      "owner": "m3owp1mp",
                      "name": "test-problem466705",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257067,
                      "owner": "m3owp1mp",
                      "name": "test-problem91465",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257066,
                      "owner": "m3owp1mp",
                      "name": "test-problem616225",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257065,
                      "owner": "m3owp1mp",
                      "name": "test-problem675379",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257064,
                      "owner": "m3owp1mp",
                      "name": "abacab12ax",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257010,
                      "owner": "m3owp1mp",
                      "name": "test-problem397290",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257009,
                      "owner": "m3owp1mp",
                      "name": "test-problem686879",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257008,
                      "owner": "m3owp1mp",
                      "name": "test-problem742907",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257007,
                      "owner": "m3owp1mp",
                      "name": "test-problem390185",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257005,
                      "owner": "m3owp1mp",
                      "name": "test-problem17016",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257004,
                      "owner": "m3owp1mp",
                      "name": "test-problem148593",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257003,
                      "owner": "m3owp1mp",
                      "name": "test-problem977649",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 257002,
                      "owner": "m3owp1mp",
                      "name": "test-problem645094",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256999,
                      "owner": "m3owp1mp",
                      "name": "test-problem915735",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256997,
                      "owner": "m3owp1mp",
                      "name": "test-problem374728",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256996,
                      "owner": "m3owp1mp",
                      "name": "test-problem783336",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256995,
                      "owner": "m3owp1mp",
                      "name": "test-problem151370",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256994,
                      "owner": "m3owp1mp",
                      "name": "test-problem594926",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256993,
                      "owner": "m3owp1mp",
                      "name": "test-problem231488",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256988,
                      "owner": "m3owp1mp",
                      "name": "abacab12a",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256987,
                      "owner": "m3owp1mp",
                      "name": "abacaba",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256986,
                      "owner": "m3owp1mp",
                      "name": "xxx101251010xxx",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256985,
                      "owner": "m3owp1mp",
                      "name": "xxx101251010",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256984,
                      "owner": "m3owp1mp",
                      "name": "xxx1012510",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256983,
                      "owner": "m3owp1mp",
                      "name": "xxx10125",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256982,
                      "owner": "m3owp1mp",
                      "name": "xxx1012",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256977,
                      "owner": "m3owp1mp",
                      "name": "xxx10",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256975,
                      "owner": "m3owp1mp",
                      "name": "xxx5",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256974,
                      "owner": "m3owp1mp",
                      "name": "xxx2",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256973,
                      "owner": "m3owp1mp",
                      "name": "xxx1",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 256828,
                      "owner": "m3owp1mp",
                      "name": "xxx",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "OWNER",
                      "revision": 0,
                      "modified": false
                    },
                    {
                      "id": 69927,
                      "owner": "mmirzayanov",
                      "name": "example-a-plus-b",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "READ",
                      "revision": 8,
                      "latestPackage": 4,
                      "modified": false
                    },
                    {
                      "id": 208585,
                      "owner": "geranazavr555",
                      "name": "a-plus-b-graders",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "READ",
                      "revision": 7,
                      "latestPackage": 7,
                      "modified": false
                    },
                    {
                      "id": 69933,
                      "owner": "mmirzayanov",
                      "name": "example-interactive-binary-search",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "READ",
                      "revision": 26,
                      "latestPackage": 26,
                      "modified": false
                    },
                    {
                      "id": 69943,
                      "owner": "mmirzayanov",
                      "name": "example-almost-upper-bound",
                      "deleted": false,
                      "favourite": false,
                      "accessType": "READ",
                      "revision": 38,
                      "latestPackage": 38,
                      "modified": false
                    }
                  ]
                })"};
    JsonParser parser(answer);
    std::shared_ptr<JsonTemplate> res;
    EXPECT_NO_THROW(res = parser.Parse());
}