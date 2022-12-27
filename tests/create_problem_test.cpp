
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 23.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>
#include <chrono>
#include <random>

#include <gtest/gtest.h>

#include "../utils/EnvReader.cpp"

TEST(create_problem_test, create_problem_works) {
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    auto problem = polygon_api::GetPolygonSession(EnvReader::Read("../../.env/env.txt"))->CreateProblem("test-problem-" + std::to_string(rnd() % 1000000));
    ASSERT_TRUE(problem);
}

TEST(create_problem_test, create_problem_twice) {
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    auto session = polygon_api::GetPolygonSession(EnvReader::Read("../../.env/env.txt"));
    auto problem_1 = session->CreateProblem("test-problem-" + std::to_string(rnd() % 1000000));
    auto problem_2 = session->CreateProblem("test-problem-" + std::to_string(rnd() % 1000000));
    ASSERT_TRUE(problem_1);
    ASSERT_TRUE(problem_2);
}

TEST(create_problem_test, create_one_problem_twice) {
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    auto session = polygon_api::GetPolygonSession(EnvReader::Read("../../.env/env.txt"));
    std::string problem_name = "test-problem-" + std::to_string(rnd() % 1000000);
    auto prob_1 = session->CreateProblem(problem_name);
    auto prob_11 = session->CreateProblem(problem_name);
    ASSERT_TRUE(prob_1);
    ASSERT_FALSE(prob_11);
}

TEST(create_problem_test, created_problem_info_correct) {
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    auto session = polygon_api::GetPolygonSession(EnvReader::Read("../../.env/env.txt"));
    std::string problem_name = "test-problem-" + std::to_string(rnd() % 1000000);
    auto prob_1 = session->CreateProblem(problem_name);
    ASSERT_EQ(prob_1->GetName(), problem_name);
}