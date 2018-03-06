///////////////////////////////////////////////////////////////////////////////
//
// json object is std::map<string_ley, value>
// json array is std::vector<value>
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include <string>

#include <cppcms/json.h>

std::string to_url_query_string(cppcms::json::object& v)
{
  if (v.empty()) return "";

  std::ostringstream oss;

  for (const auto& p : v)
  {
    oss << '&' << p.first << '=';

    if (p.second.type() == cppcms::json::json_type::is_string)
    {
      std::string str = p.second.get_value<std::string>();
      oss << str;
    }
    else
    {
      oss << p.second;
    }
  }

  return oss.str().replace(0, 1, "?");
}

int main(int argc, char** argv)
{
///////////////////////////////////////////////////////////////////////////////
//
// cppcms testing example
//
//  cppcms::json::value obj;
//
//  obj["name"] = "pingsoli";
//  obj["password"] = "123455";
//  obj["isEncrted"] = false;
//
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////

  cppcms::json::object obj;

  obj.emplace("name",      "pingsoli");
  obj.emplace("password",  "123456");
  obj.emplace("isEncrted", false);
  obj.emplace("userType",  1);

  std::cout << to_url_query_string(obj) << std::endl;

///////////////////////////////////////////////////////////////////////////////

//  try
//  {
//    std::string json_str;
//
//    json_str = "{\"account\": \"1234566\",\"password\": \"test\",\"isEncrted\": true}";
//    json_str = "";
//
//    std::stringstream   json_s(json_str);
//    cppcms::json::value jv;
//
//    if (jv.load(json_s, false))
//    {
//      std::cout << jv["account"] << std::endl;
//      std::cout << jv["password"] << std::endl;
//      std::cout << jv["isEncrted"] << std::endl;
//    }
//    else
//    {
//      std::cout << "load error" << std::endl;
//    }
//  }
//  catch (const std::exception& e)
//  {
//    std::cerr << "Exception: " << e.what() << std::endl;
//  }

///////////////////////////////////////////////////////////////////////////////

  return 0;
}
