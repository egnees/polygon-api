
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONSTRING_H
#define POLYGON_API_JSONSTRING_H

#include <polygon_api/polygon_api.h>
#include <json/JsonTemplate.h>

#include <utility>

class JsonString : public JsonTemplate {
public:
    explicit JsonString(std::string s) : s_(std::move(s)) {}
    [[nodiscard]] std::string Serialize() const override {
        return s_;
    }
    [[nodiscard]] std::string Get() const {
        return s_;
    }
private:
    std::string s_;
};

#endif //POLYGON_API_JSONSTRING_H
