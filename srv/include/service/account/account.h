#ifndef account_header_h

#define account_header_h

#include <string>
#include <map>
#include <boost/shared_ptr.hpp>

#include "error.h"

namespace tw { namespace test {

using boost::shared_ptr;
typedef AccountInfo std::map<std::string, std::string>;

class AccountDB
{
public:
    AccountDB() {};
    virtual ~AccountDB() {};
    virtual ErrorCode init() = 0;
    virtual shared_ptr<AccountInfo> getUserInfo(std::string &userId) = 0;
    virtual ErrorCode deleteUser(std::string &userId) = 0;
    virtual shared_ptr<Account> instance() = 0;
};

class Account
{
public:
    Account(shared_ptr<AccountDB> db);
    ~Account();
    ErrorCode checkUser(std::string &userId, std::string &passwd);
    ErrorCode checkRepo(std::string &repo);

private:
    shared_ptr<AccountInfo> mInfo;
    std::string mUserId;
    bool logined;
};

class DummyAccountDB : public AccountDB
{
public:
    DummyAccountDB();
    ~DummyAccountDB();
    ErrorCode init();
    shared_ptr<AccountInfo> getUserInfo(std::string &userId);
    ErrorCode deleteUser(std::string &userId);
    Account instance();

private:
    std::map<std::string, shared_ptr<AccountInfo> > mDB;
};

}}
#endif
