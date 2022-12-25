
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 09.12.2022.
//

#pragma once

#include <polygon_api/Problem.h>
#include <polygon_api/Account.h>
#include <polygon_api/BaseRequester.h>
#include <polygon_api/ApiRequester.h>
#include <polygon_api/RawRequester.h>
#include <polygon_api/polygon_api.h>

namespace polygon_api {

const std::string kPolygonRawUrl = "https://polygon.codeforces.com/";
const std::string kPolygonApiUrl = "https://polygon.codeforces.com/api/";
const std::string kPolygonOrigin = "https://polygon.codeforces.com";
const std::string kPolygonFp = "a92fdda7ac4f88ec7f7a8b28231cdd04";

class PolygonSession : public std::enable_shared_from_this<PolygonSession> {
public:
    explicit PolygonSession(const Account &);

    static std::string ExtractCcidFromHTML(const std::string&, const std::string&);
    static std::string ExtractCcidFromURL(const std::string&);
    static std::string ExtractProblemIdFromHTML(const std::string&, const std::string&);

    [[nodiscard]] bool IsAuthRawSuccess() const;

    std::shared_ptr<Problem> CreateProblem(const std::string&);
    std::vector<std::shared_ptr<Problem>> GetProblemsList(const std::string&, const std::string&,
                                                          const std::string&, bool show_deleted = false);
    std::vector<std::shared_ptr<Problem>> GetProblemsList();
private:
    bool AuthRaw(const std::string&, const std::string&);

    [[nodiscard]] std::string GetCcid() const;

    void SetCcid(const std::string&);

    void UpdateCcidFromHTML(const std::string&, const std::string&);
    void UpdateCcidFromURL(const std::string&);

    std::shared_ptr<RequestBuilder> NewRawRequest();
    std::shared_ptr<RequestBuilder> NewRawRequest(const std::string&);

    std::shared_ptr<RequestBuilder> NewApiRequest();
    std::shared_ptr<RequestBuilder> NewApiRequest(const std::string&);

    std::shared_ptr<RawRequester> raw_requester_;
    std::shared_ptr<ApiRequester> api_requester_;

    bool logged_raw = false;

    std::string ccid_;

    Account account_;
};

} // namespace polygon_api
