
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONOBJECT_H
#define POLYGON_API_JSONOBJECT_H

#include <polygon_api/polygon_api.h>
#include <json/JsonTemplate.h>


class JsonObject : public JsonTemplate {
public:
    explicit JsonObject(const std::vector<std::pair<std::string, std::shared_ptr<JsonTemplate>>>&);
    [[nodiscard]] std::string Serialize() const override;
    std::shared_ptr<JsonTemplate> Get(const std::string&);
private:
    std::map<std::string, std::shared_ptr<JsonTemplate>> data_;
};

#endif //POLYGON_API_JSONOBJECT_H
