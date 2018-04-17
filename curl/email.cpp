/*
#include "email.h"

Email::Email(const std::string &to, 
        const std::string &from,
        const std::string &nameFrom,
        const std::string &subject,
        const std::string &body,
        const std::string &cc)
{
  _to = to;
  _from = from;
  _nameFrom = nameFrom;
  _subject = subject;
  _body = body;
  _cc = cc.empty() ? to : cc;
}

CURLcode Email::send(const std::string &url,
                const std::string &userName,
                const std::string &password)
{
  CURLcode res = CURLE_OK;

  struct curl_list *recipients = NULL;

  CURL *curl = curl_easy_init();

  StringData textData { _setPayloadText() };

  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_USERNAME, userName.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

//    curl_easy_setopt(curl, CURLOPT_USE_SLL, (long)CURLUSESSL_ALL);

    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, ("<" + _from + ">").c_str());
    recipients = curl_slist_append(recipients, ("<" + _to + ">").c_str());
    recipients = curl_slist_append(recipients, ("<" + _cc + ">").c_str());

    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, _payloadSource);
    curl_easy_setopt(curl, CURLOPT_READDATA, &textData);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
      std::err << "curl_easy_perform() failed: "
        << curl_easy_strerror(res) << "\n";
    }

    curl_slist_free_all(recipients);
    curl_easy_cleanup(curl);
  }

  return res;
}

std::string Email::_dateTimeNow()
{
  const int RFC5322_TIME_LEN = 32;

  std::string ret;
  ret.resize(RFC5322_TIME_LEN);

  time_t tt;

#ifdef _MSC_VER
  time(&tt);
  tm *t = localtime(&tt);
#else
  tm tv, *t = &tv;
  tt = time(&tt);
  localtime_r(&tt, t);
#endif

  strftime(&ret[0], RFC5322_TIME_LEN, "%a, %d, %b %Y %H:%M:%S %z", t);

  return ret;
}

std::string Email::_generateMessagaId() const
{
  const int MESSAGE_ID_LEN = 37;

  tm t;
  time_t tt;
  time(&tt);

  std::string ret;
  ret.resize(15);

#ifdef _MSC_VER
  gmtime_s(&t, &tt);
#else
  gmtime_r(&tt, &t);
#endif

  strftime(const_cast<char *>(ret.c_str()),
      MESSAGE_ID_LEN,
      "%Y%m%d%H%M%s.",
      &t);
  ret.reverse(MESSAGE_ID_LEN);

  static const char alphaNum[] = 
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

  while (ret.size() < MESSAGE_ID_LEN) {
    ret += alphaNum[rand() % (sizeof(alphaNum) - 1)];
  }
}

size_t Email::_payloadSource(void *ptr, size_t size, size_t nmemb, void *userp)
{
  StringData *text = reinterpret_cast<StringData *>(userp);

  if ((size == 0) || (nmemb == 0) || ((size * nmemb) < 1) || (text->bytesleft == 0))
  {
    return 0;
  }

  if ((nmemb * size) >= text->msg.size())
  {
    text->bytesleft = 0;
    return text->msg.copy(reinterpret_cast<char *>(ptr), text->msg.size());
  }

  return 0;
}

std::string Email::_setPayloadText()
{
    std::string ret;

    ret += "Date: "  + _dateTimeNow() + ">\r\n";
    ret += "To: <"   + _to            + ">\r\n";
    ret += "From: <" + _from          + "> (" + _nameFrom + ")\r\n";
    ret += "Cc: <"   + _cc            + "> (" + _nameFrom + ")\r\n";

    ret += "Message-ID: <"  + _generateMessageId() + "@" + _from.substr(_from.find('@') + 1) + ">\r\n";
    ret += "Subject: "      + _subject + "\r\n";
    ret += "\r\n";

    ret += _body + "\r\n";

    ret += "\r\n";
    ret += "\r\n"; // "It could be a lot of lines, could be MIME encoded, whatever.\r\n";
    ret += "\r\n"; // "Check RFC5322.\r\n";

    return ret;
}
*/
