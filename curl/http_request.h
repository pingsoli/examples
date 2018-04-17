#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <iostream>
#include <curl/curl.h>
#include <cstring>
#include <cstdio>
#include "json.hpp"

namespace usercenter {

enum class HttpMethod { GET = 0, PUT, POST, DELETE, PATCH, TEST };

std::string to_url_query_string(nlohmann::json&);

std::string
send_https_request(const std::string& url,
                   const std::string& data,
                   HttpMethod method);

} /* usercenter namespace */

#endif /* __HTTP_REQUEST_H__ */
