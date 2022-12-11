
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/polygon_api.h>

namespace polygon_api {

const std::string kPolygonRawUrl = "https://polygon.codeforces.com/";
const std::string kPolygonOrigin = "https://polygon.codeforces.com";
const std::string kPolygonFp = "a92fdda7ac4f88ec7f7a8b28231cdd04";

class PolygonSession {
public:
    PolygonSession(std::string, std::string, std::string, std::string);

    static std::string ExtractCcidFromHTML(const std::string&, const std::string&);
    static std::string ExtractCcidFromURL(const std::string&);

    [[nodiscard]] bool IsAuthRawSuccess() const;
private:
    bool AuthRaw(const std::string&, const std::string&);

    [[nodiscard]] std::string GetCcid() const;

    void SetCcid(const std::string&);

    void UpdateCcidFromHTML(const std::string&, const std::string&);
    void UpdateCcidFromURL(const std::string&);

    std::shared_ptr<RequestBuilder> NewRawRequest();
    std::shared_ptr<RequestBuilder> NewRawRequest(const std::string&);

    std::shared_ptr<RawRequester> raw_requester_;

    bool logged_raw = false;

    std::string ccid_;

    std::string login_;
    std::string password_;
    std::string key_;
    std::string secret_;
};

} // namespace polygon_api
