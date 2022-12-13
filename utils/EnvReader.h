
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 11.12.2022.
//

#ifndef POLYGON_API_ENVREAD_H

#include <polygon_api/Account.h>

namespace EnvReader {

polygon_api::Account Read();

polygon_api::Account Read(const std::string&);

} //namespace EnvReader

#define POLYGON_API_ENVREAD_H

#endif //POLYGON_API_ENVREAD_H
