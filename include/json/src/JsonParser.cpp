
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//
#include <json/JsonParser.h>

void JsonParser::Skip() {
    while (ptr_ < s_.size() && (s_[ptr_] == ' ' || s_[ptr_] == '\n')) {
        ++ptr_;
    }
}

std::shared_ptr<JsonTemplate> JsonParser::Parse() {
    Skip();
    if (ptr_ == s_.size()) {
        throw std::runtime_error("json format error");
    }
    if (s_[ptr_] == '{') {
        return ParseObject();
    } else if (s_[ptr_] == '[') {
        return ParseList();
    } else if ('0' <= s_[ptr_] && s_[ptr_] <= '9') {
        return ParseNumber();
    } else if (s_[ptr_] == '\"'){
        return ParseString();
    } else if (s_[ptr_] == 'f' || s_[ptr_] == 't') {
        return ParseBoolean();
    } else {
        throw std::runtime_error("json format error");
    }
}

std::shared_ptr<JsonList> JsonParser::ParseList() {
    std::vector<std::shared_ptr<JsonTemplate>> list;
    ++ptr_;
    Skip();
    try {
        while (true) {
            list.push_back(Parse());
            Skip();
            if (s_[ptr_] == ']') {
                break;
            }
            if (s_[ptr_] != ',') {
                throw std::runtime_error("json format error");
            }
            ++ptr_;
        }
    } catch (...) {
        throw std::runtime_error("json format error");
    }
    ++ptr_;
    return std::make_shared<JsonList>(list);
}

std::shared_ptr<JsonObject> JsonParser::ParseObject() {
    std::vector<std::pair<std::string, std::shared_ptr<JsonTemplate>>> list;
    ++ptr_;
    try {
        while (true) {
            Skip();
            if (s_[ptr_] == '}') {
                break;
            }
            Skip();
            std::string name = ParseString()->Get();
            Skip();
            if (s_[ptr_] != ':') {
                throw std::runtime_error("json format error");
            }
            ++ptr_;
            list.emplace_back(name, Parse());
            Skip();
            if (s_[ptr_] == '}') {
                break;
            }
            if (s_[ptr_] != ',') {
                throw std::runtime_error("json format error");
            }
            ++ptr_;
        }
    } catch (...) {
        throw std::runtime_error("json format error");
    }
    ++ptr_;
    return std::make_shared<JsonObject>(list);
}

std::shared_ptr<JsonNumber> JsonParser::ParseNumber() {
    int number = 0;
    while (ptr_ < s_.size() && '0' <= s_[ptr_] && s_[ptr_] <= '9') {
        number *= 10;
        number += s_[ptr_] - '0';
        ++ptr_;
    }
    return std::make_shared<JsonNumber>(number);
}

std::shared_ptr<JsonString> JsonParser::ParseString() {
    ++ptr_;
    std::string res;
    while (ptr_ < s_.size() && s_[ptr_] != '\"') {
        res.push_back(s_[ptr_]);
        ++ptr_;
    }
    if (ptr_ == s_.size()) {
        throw std::runtime_error("json format error");
    }
    ++ptr_;
    return std::make_shared<JsonString>(res);
}

std::shared_ptr<JsonBoolean> JsonParser::ParseBoolean() {
    if (s_.substr(ptr_, 5) == "false") {
        ptr_ += 5;
        return std::make_shared<JsonBoolean>(false);
    } else if (s_.substr(ptr_, 4) == "true") {
        ptr_ += 4;
        return std::make_shared<JsonBoolean>(true);
    } else {
        throw std::runtime_error("json format error: cant parse json boolean");
    }
}
