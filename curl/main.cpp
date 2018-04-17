#include <iostream>
#include <string>
#include <exception>
#include "md5.h"
#include "http_request.h"
#include "json.hpp"

using json = nlohmann::json;

/*
 * NOTE: only check the bool, string, number type
 */
void check_json_type(json& j)
{
  for (json::iterator e = j.begin(); e != j.end(); ++e)
  {
    if ((*e).is_boolean())
      std::cout << "BOOL: " << e.key() << " : " << e.value() << std::endl;

    if ((*e).is_number())
      std::cout << "NUMBER: " << e.key() << " : " << e.value() << std::endl;

    if ((*e).is_string())
      std::cout << "STRING: " << e.key() << " : " << e.value() << std::endl;
  }
}

int main(int argc, char **argv)
{
  std::string login_url    = "https://example.com/login";
  std::string register_url = "https://example.com/register";

  json login_user;
  login_user["account"]   = "12345678";
  login_user["password"]  = "123456";
  login_user["isEncrted"] = false;

  json new_account;
  new_account["account"]      = "12345678";
  new_account["password"]     = "123456";
  new_account["isEncrted"]    = false;
  new_account["productType"]  = 1;
  new_account["registerType"] = "mobile";
  new_account["userType"]     = 0;

  try
  {
    std::string str = "{";
    json j = json::parse(str);

    if (j.is_null())
      std::cout << "NULL" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }

//  std::string login_query_params = usercenter::to_url_query_string(login_user);
//  login_url += login_query_params;
//
//  std::string register_query_params = usercenter::to_url_query_string(new_account);
//  std::string response_text = "";
//
//  // Login
//  response_text = usercenter::send_https_request(login_url,
//                                "",
//                                usercenter::HttpMethod::PUT);
//
//  json j = json::parse(response_text);
//  std::cout << std::setw(2) << j << std::endl;

  // Register an account
//  response_text = usercenter::send_https_request(register_url,
//                                register_query_params.substr(1),
//                                usercenter::HttpMethod::POST);
//
//  std::cout << response_text << std::endl;

  return 0;
}
