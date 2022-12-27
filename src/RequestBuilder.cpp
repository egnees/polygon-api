
//
// Created by Sergei Yakovlev <3gnees@gmail.com> on 10.12.2022.
//

#include <polygon_api/polygon_api.h>
#include <polygon_api/RequestBuilder.h>

#include <utility>

namespace polygon_api {

RequestBuilder::RequestBuilder(std::shared_ptr<BaseRequester> requester) : requester_(std::move(requester)) {}

RequestBuilder::RequestBuilder(std::shared_ptr<BaseRequester> requester, const std::initializer_list<cpr::Pair>& header)
        : requester_(std::move(requester)) {
    for (const auto& [key, value] : header) {
        header_.push_back({key, value});
    }
}

std::shared_ptr<RequestBuilder> RequestBuilder::GetSharedPtr() {
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::SetMethodName(const std::string &name) {
    method_name_ = name;
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::SetParams(const std::initializer_list<cpr::Parameter>& initial_list) {
    params_.clear();
    for (const auto &[key, value] : initial_list) {
        params_.push_back({key, value});
    }
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::AddToHeader(const std::string &key, const std::string& value) {
    header_.push_back({key, value});
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::AddToHeader(const std::initializer_list<cpr::Pair> &initial_list) {
    for (const cpr::Pair& p : initial_list) {
        header_.push_back({p.key, p.value});
    }
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::SetHeader(const std::initializer_list<cpr::Pair>& initial_list) {
    header_.clear();
    for (const cpr::Pair& p : initial_list) {
        header_.push_back({p.key, p.value});
    }
    return shared_from_this();
}

std::shared_ptr<RequestBuilder> RequestBuilder::SetPayload(const std::initializer_list<cpr::Pair>& initial_list) {
    payload_.clear();
    for (const cpr::Pair& p : initial_list) {
        payload_.push_back({p.key, p.value});
    }
    return shared_from_this();
}

cpr::Response RequestBuilder::Post() const {
    return requester_->Post(method_name_, params_, header_, payload_);
}

cpr::Response RequestBuilder::Get() const {
    return requester_->Get(method_name_, params_, header_);
}

std::shared_ptr<RequestBuilder> RequestBuilder::AddToPayload(const std::string &key, const std::string &value) {
    payload_.emplace_back(key, value);
    return shared_from_this();
}

}

