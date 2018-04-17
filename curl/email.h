#ifndef _EMAIL_H_
#define _EMAIL_H_
/*
#include <ctime>
#include <cstring>
#include <string>
#include <curl/curl.h>

class Email
{
public:
  Email(const std::string &to, 
        const std::string &from,
        const std::string &nameFrom,
        const std::string &subject,
        const std::string &body,
        const std::string &cc = "");

  CURLcode send(const std::string &url,
                const std::string &userName,
                const std::string &password);

private:
  struct StringData {
    std::string msg;
    size_t bytesleft;
    StringData(std::string &&m) : msg{ m }, bytesleft{ msg.size() } {}
    StringData(std::string &m) = delete;
  };


  static std::string _dateTimeNow();
  std::string _generateMessagaId() const;
  static size_t _payloadSource(void *ptr, size_t size, size_t nmemb, void *userp);
  std::string _setPayloadText();

  std::string _to;
  std::string _from;
  std::string _cc;
  std::string _nameFrom;
  std::string _subject;
  std::string _body;
};
*/

#endif /* _EMAIL_H_ */
