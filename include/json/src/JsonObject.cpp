
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#include <json/JsonObject.h>

std::shared_ptr<JsonTemplate> JsonObject::Get(const std::string &field) {
    if (data_.count(field)) {
        return data_[field];
    } else {
        throw std::runtime_error("no such field in json object");
    }
}

std::string JsonObject::Serialize() const {
    if (data_.empty()) {
        return "{}";
    }
    std::string res = "{\n";
    size_t ptr = 0;
    for (const auto& inner : data_) {
        res += inner.second->Serialize();
        ++ptr;
        if (ptr < data_.size()) {
            res += ',';
        }
        res += '\n';
    }
    return res + "}";
}

JsonObject::JsonObject(const std::vector<std::pair<std::string, std::shared_ptr<JsonTemplate>>>& data) {
    for (const auto& [name, value] : data) {
        data_.emplace(name, value);
    }
}
