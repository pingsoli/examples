#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <odb/core.hxx>

#pragma db object
class person
{
public:
  person(const std::string& first,
         const std::string& last,
         unsigned short age)
    : first_(first), last_(last), age_(age)
  {
  }

  const std::string& first() const
  {
    return first_;
  }

  const std::string& last() const
  {
    return last_;
  }

  unsigned short age() const
  {
    return age_;
  }

  void age(unsigned short age)
  {
    age_ = age;
  }

private:
  person() {}
  friend class odb::access;

  #pragma db id auto
  unsigned long id_;

  std::string first_;
  std::string last_;
  unsigned short age_;
};

#endif /* PERSON_H_ */
