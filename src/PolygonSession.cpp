
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/PolygonSession.h>
#include <polygon_api/RequestBuilder.h>
#include <polygon_api/RawRequester.h>

namespace polygon_api {

PolygonSession::PolygonSession(const Account &account)
                               : raw_requester_(std::make_shared<RawRequester>(kPolygonRawUrl)),
                               api_requester_(std::make_shared<ApiRequester>(kPolygonApiUrl, account.key_, account.secret_)),
                               account_(account) {
    logged_raw = AuthRaw(account_.login_, account_.password_);
}

std::shared_ptr<Problem> PolygonSession::CreateProblem(const std::string& name) {
    cpr::Response r = NewRawRequest("cp")->SetPayload({{"name", name},
                                                      {"submit", "Create"},
                                                      {"submitted", "true"},
                                                      {"ccid", GetCcid()}})->Post();
    std::string problem_id;
    try {
        problem_id = ExtractProblemIdFromHTML(r.text, name);
    } catch (...) {
        return nullptr;
    }
    return std::make_shared<Problem>(shared_from_this(), problem_id);
}

std::shared_ptr<RequestBuilder> PolygonSession::NewApiRequest() {
    return std::make_shared<RequestBuilder>(api_requester_);
}

std::shared_ptr<RequestBuilder> PolygonSession::NewApiRequest(const std::string& method_name) {
    return NewApiRequest()->SetMethodName(method_name);
}

std::shared_ptr<RequestBuilder> PolygonSession::NewRawRequest() {
    std::initializer_list<cpr::Pair> initial_header{
        {"origin", kPolygonOrigin},
        {"user-agent",
         "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.88 Safari/537.36"}};
    return std::make_shared<RequestBuilder>(raw_requester_, initial_header);
}

std::shared_ptr<RequestBuilder> PolygonSession::NewRawRequest(const std::string &method_name) {
    return NewRawRequest()->SetMethodName(method_name);
}

bool PolygonSession::AuthRaw(const std::string &login, const std::string &password) {
    auto p = NewRawRequest("login");
    cpr::Response first_response = p->Get();
    if (first_response.status_code != 200) {
        throw std::runtime_error("codeforces polygon unavailable, may be url " + kPolygonRawUrl + " changed?");
    }
    try {
        UpdateCcidFromHTML(first_response.text, R"(meta name="ccid" content=")");
    } catch (std::runtime_error& e) {
        throw std::runtime_error("something wrong with " + kPolygonRawUrl + "/login response" + e.what());
    }
    cpr::Response second_response = NewRawRequest("login")->SetParams({{"ccid", GetCcid()}})->SetPayload({
        {"ccid", GetCcid()},
        {"login", login},
        {"password", password},
        {"submit", "Login"},
        {"submitted", "true"},
        {"fp", kPolygonFp}
    })->Post();

    std::string URL = static_cast<std::string>(second_response.url);
    if (URL.find("problems") == std::string::npos) {
        return false;
    }

    try {
        UpdateCcidFromURL(URL);
    } catch (...) {};

    return true;
}

std::vector<std::shared_ptr<Problem>> PolygonSession::GetProblemsList(const std::string& id, const std::string& name,
                                                                      const std::string& owner, bool show_deleted) {
    cpr::Response response = NewApiRequest("problems.list")->Post();

    return {};
}

bool PolygonSession::IsAuthRawSuccess() const {
    return logged_raw;
}

std::string PolygonSession::GetCcid() const {
    return ccid_;
}

void PolygonSession::SetCcid(const std::string &ccid) {
    ccid_ = ccid;
}

void PolygonSession::UpdateCcidFromHTML(const std::string &text, const std::string& pattern) {
    SetCcid(ExtractCcidFromHTML(text, pattern));
}

void PolygonSession::UpdateCcidFromURL(const std::string &text) {
    SetCcid(ExtractCcidFromURL(text));
}

std::string PolygonSession::ExtractCcidFromHTML(const std::string &text, const std::string& pattern) {
    size_t pos = text.find(pattern);
    if (pos == std::string::npos) {
        throw std::runtime_error("there is no ccid in text");
    }
    pos += pattern.size();
    std::string ccid;
    try {
        while (text[pos] != '"') {
            ccid.push_back(text[pos]);
            ++pos;
        }
    } catch (...) {
        throw;
    }
    return ccid;
}

std::string PolygonSession::ExtractCcidFromURL(const std::string &text) {
    std::string_view pattern = "ccid=";
    size_t pos = text.find(pattern);
    if (pos == std::string::npos) {
        throw std::runtime_error("there is no ccid in text");
    }
    pos += pattern.size();
    std::string ccid;
    try {
        while (pos < text.size()) {
            ccid.push_back(text[pos]);
            ++pos;
        }
    } catch (...) {
        throw;
    }
    return ccid;
}

std::string PolygonSession::ExtractProblemIdFromHTML(const std::string& html, const std::string& problem_name) {
    auto pos = html.find(problem_name);
    if (pos == std::string::npos) {
        throw std::runtime_error("there is no such problem in html");
    }
    const std::string pat = "problemId=\"";
    while (pos > 0) {
        --pos;
        if (html.substr(pos, pat.size()) == pat) {
            break;
        }
    }
    if (html.substr(pos, pat.size()) != pat) {
        throw std::runtime_error("there is no such pattern in html");
    }
    pos += pat.size();
    std::string id;
    while ('0' <= html[pos] && html[pos] <= '9') {
        id.push_back(html[pos]);
        ++pos;
    }
    if (pos < html.size() && html[pos] == '\"') {
        return id;
    } else {
        throw std::runtime_error("there is no such pattern in html");
    }
}

} // namespace polygon_api
