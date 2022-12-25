
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#ifndef POLYGON_API_JSONBOOLEAN_H
#define POLYGON_API_JSONBOOLEAN_H

#include <json/JsonTemplate.h>

class JsonBoolean : public JsonTemplate {
public:
    explicit JsonBoolean(bool value) : value_(value) {}
    explicit JsonBoolean(const std::string& s) : value_(s == "true") {
        if (s != "true" && s != "false") {
            throw std::runtime_error("failed to construct json boolean: string is not true or false");
        }
    }
    [[nodiscard]] std::string Serialize() const override {
        return value_ ? "true" : "false";
    }
    [[nodiscard]] bool Get() const {
        return value_;
    }
private:
    bool value_;
};

#endif //POLYGON_API_JSONBOOLEAN_H
