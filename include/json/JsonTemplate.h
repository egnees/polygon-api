
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 25.12.2022.
//

#pragma once

#ifndef POLYGON_API_JSONTEMPLATE_H
#define POLYGON_API_JSONTEMPLATE_H

#include <polygon_api/polygon_api.h>

class JsonTemplate {
public:
    virtual std::string Serialize() const = 0;
};

#endif //POLYGON_API_JSONTEMPLATE_H
