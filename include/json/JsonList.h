
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONLIST_H
#define POLYGON_API_JSONLIST_H

#include <polygon_api/polygon_api.h>
#include <json/JsonTemplate.h>

class JsonList : public JsonTemplate {
public:
    JsonList(const std::vector<std::shared_ptr<JsonTemplate>>& data) : data_(data) {}
    std::string Serialize() const override;
    std::shared_ptr<JsonTemplate> Get(size_t);
    size_t Size() const;
private:
    std::vector<std::shared_ptr<JsonTemplate>> data_;
};

#endif //POLYGON_API_JSONLIST_H
