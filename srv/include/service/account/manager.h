#ifndef manager_header_h

#define manager_header_h

#include <string>
#include "error.h"
#include "data_store.h"
#include "simple_cache.h"
#include "account.h"

namespace tw { namespace test {

class GlobalManager
{
public:
    GlobalManager();
    ~GlobalManager();
    ErrorCode init(std::string config);
    shared_ptr<Account> accountAPI();

private:
    // each resource manager need to handler pool & thread-safe
    AccountDB *mAccount;
    /*
    DataStore m_store;
    SimpleCache m_cache;
    TokenManager m_token_manager;
    */
};
}}
#endif
