#include "http_request.h"

using json = nlohmann::json;
using namespace usercenter;

typedef struct {
  const char* buf;
  int len;
  int pos;
} readarg_t;

static size_t
write_callback(char *ptr, size_t size, size_t nmemb, std::string *data)
{
  data->append((char *)ptr, size * nmemb);
  return size * nmemb;
}

static size_t
read_callback(void* ptr, size_t size, size_t nmemb, void* stream)
{
  readarg_t* rarg = (readarg_t *)stream;
  int len = rarg->len - rarg->pos;
  if (len > size * nmemb)
    len = size * nmemb;

  memcpy(ptr, rarg->buf + rarg->pos, len);
  rarg->pos += len;
  return len;
}

void add_http_header(CURL* curl)
{
  struct curl_slist* chunk = nullptr;

  chunk = curl_slist_append(chunk, "merchId: xxxxx_xxx_app");
  chunk = curl_slist_append(chunk, "key: xxxxxxxxxxxxxxxxxxxxxxxxx");
  chunk = curl_slist_append(chunk, "version: 1.5.0");

  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
}

void add_https_verify(CURL* curl)
{
  // Allowing SSL insecure connections
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_SSLCERT,   "client.pem");
  curl_easy_setopt(curl, CURLOPT_SSLKEY,    "key.pem");
  curl_easy_setopt(curl, CURLOPT_KEYPASSWD, "xxxxx.xxxx");
}

CURL* create_comm_request()
{
  CURL* curl = nullptr;

  curl = curl_easy_init();
  if (curl)
  {
    add_https_verify(curl);
    add_http_header(curl);

    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
  }

  return curl;
}

std::string
send_http_test_request(const std::string& url, const std::string& data)
{
  CURL* curl = nullptr;
  CURLcode res;
  std::string response_text = "";

  curl = create_comm_request();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_text);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
      std::cout << "curl_easy_perform() failed: "
        << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  return response_text;
}

std::string
send_http_put_request(const std::string& url, const std::string& data)
{
  CURL* curl;
  CURLcode res;
  std::string response_text = "";

  readarg_t read;
  read.buf = data.c_str();
  read.pos = 0;
  read.len = data.size();

  curl = create_comm_request();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Http PUT
    curl_easy_setopt(curl, CURLOPT_PUT, 1L);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
    curl_easy_setopt(curl, CURLOPT_READDATA, &read);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_text);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
      std::cout << "curl_easy_perform() failed: "
        << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  return response_text;
}

std::string
send_http_post_request(const std::string& url, const std::string& data)
{
  CURL* curl;
  CURLcode res;
  std::string response_text = "";

  curl = create_comm_request();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, data.size());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_text);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
      std::cout << "curl_easy_perform() failed: "
        << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  return response_text;
}

std::string
usercenter::send_https_request(const std::string& url,
                   const std::string& data,
                   HttpMethod method)
{
  std::string res = "";

  switch (method)
  {
  case HttpMethod::GET:
    break;

  case HttpMethod::PUT:
    res = send_http_put_request(url, data);
    break;

  case HttpMethod::POST:
    res = send_http_post_request(url, data);
    break;

  default: /* test */
//    res = send_http_test_request(url, data);
    break;
  }
  return res;
}

std::string 
usercenter::to_url_query_string(json& j)
{
  std::ostringstream oss;

  if (j.is_null())
    return "";

  for (json::iterator it = j.begin(); it != j.end(); ++it)
  {
    oss << "&" << it.key() << "=";
    if ((*it).is_string())
    {
      // Remove the double quote in the string
      std::string str = it.value();
      oss << str;
    }
    else
    {
      oss << it.value();
    }
  }

  return oss.str().replace(0, 1, "?");
}
