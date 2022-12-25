
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONPARSER_H
#define POLYGON_API_JSONPARSER_H

#include <polygon_api/polygon_api.h>

#include <json/JsonList.h>
#include <json/JsonNumber.h>
#include <json/JsonString.h>
#include <json/JsonObject.h>
#include <json/JsonBoolean.h>

class JsonParser {
public:
    explicit JsonParser(std::string text) : s_(std::move(text)) {}
    std::shared_ptr<JsonTemplate> Parse();
private:
    std::shared_ptr<JsonList> ParseList();
    std::shared_ptr<JsonObject> ParseObject();
    std::shared_ptr<JsonNumber> ParseNumber();
    std::shared_ptr<JsonString> ParseString();
    std::shared_ptr<JsonBoolean> ParseBoolean();

    void Skip();

    std::string s_;
    size_t ptr_{};
};

template<typename T>
std::shared_ptr<T> As(std::shared_ptr<JsonTemplate> p) {
    try {
        return std::dynamic_pointer_cast<T>(p);
    } catch (...) {
        throw std::runtime_error("dynamic cast error");
    }
}

template<typename T>
bool Is(std::shared_ptr<JsonTemplate> p) {
    return As<T>(p) != nullptr;
}

#endif //POLYGON_API_JSONPARSER_H
