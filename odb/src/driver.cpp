#include <memory>
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/mysql/database.hxx>

#include "person.h"
#include "person-odb.hxx"

using namespace std;
using namespace odb::core;

int main(int argc, char **argv)
{
  try
  {
    auto_ptr<database> db(new odb::mysql::database(argc, argv));
//
//    unsigned long john_id, jane_id, joe_id;
//
//    // Create a few persistent person objects
//    //
//    {
//      person john("John", "Doe", 33);
//      person jane("Jane", "Doe", 32);
//      person joe("Joe", "Dirt", 30);
//
//      transaction t(db->begin());
//
//      john_id = db->persist(john);
//      jane_id = db->persist(jane);
//      joe_id  = db->persist(joe);
//
//      t.commit();
//    }
  }
  catch (const odb::exception& e)
  {
    cerr << e.what() << endl;
    return 1;
  }

  cout << "hello world" << endl;

  return 0;
}
