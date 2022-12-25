
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONNUMBER_H
#define POLYGON_API_JSONNUMBER_H

#include <polygon_api/polygon_api.h>
#include <json/JsonTemplate.h>

class JsonNumber : public JsonTemplate {
public:
    explicit JsonNumber(int num) : num_(num) {}
    [[nodiscard]] std::string Serialize() const override {
        return std::to_string(num_);
    }
    [[nodiscard]] int Get() const {
        return num_;
    }
private:
    int num_;
};

#endif //POLYGON_API_JSONNUMBER_H
