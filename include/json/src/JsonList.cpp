
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#include <json/JsonList.h>

std::shared_ptr<JsonTemplate> JsonList::Get(size_t i) {
    if (i >= data_.size()) {
        throw std::runtime_error("outgoing list borders");
    }
    return data_[i];
}

size_t JsonList::Size() const {
    return data_.size();
}

std::string JsonList::Serialize() const {
    if (data_.empty()) {
        return "[]";
    }
    std::string res = "[\n";
    for (size_t i = 0; i < data_.size(); ++i) {
        res += data_[i]->Serialize();
        if (i + 1 < data_.size()) {
            res += ',';
        }
        res += '\n';
    }
    return res + "]";
}