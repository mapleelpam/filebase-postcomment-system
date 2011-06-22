/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef RepositoryService_H
#define RepositoryService_H

#include <TProcessor.h>
#include "proto_types.h"

namespace tw { namespace maple { namespace generated {

class RepositoryServiceIf {
 public:
  virtual ~RepositoryServiceIf() {}
  virtual void userLogin(const std::string& repo_name, const std::string& username, const std::string& password) = 0;
  virtual int8_t getUserPermissionMask() = 0;
  virtual void addTextData(UUID& _return, const std::string& content, const std::string& categories, const int32_t default_expire_time) = 0;
  virtual void modifyTextData(const std::string& repo_name, const UUID& instance_id, const std::string& new_content) = 0;
  virtual void getTextURL(URL& _return, const std::string& repo_name, const UUID& instance_id) = 0;
};

class RepositoryServiceNull : virtual public RepositoryServiceIf {
 public:
  virtual ~RepositoryServiceNull() {}
  void userLogin(const std::string& /* repo_name */, const std::string& /* username */, const std::string& /* password */) {
    return;
  }
  int8_t getUserPermissionMask() {
    int8_t _return = 0;
    return _return;
  }
  void addTextData(UUID& /* _return */, const std::string& /* content */, const std::string& /* categories */, const int32_t /* default_expire_time */) {
    return;
  }
  void modifyTextData(const std::string& /* repo_name */, const UUID& /* instance_id */, const std::string& /* new_content */) {
    return;
  }
  void getTextURL(URL& /* _return */, const std::string& /* repo_name */, const UUID& /* instance_id */) {
    return;
  }
};

typedef struct _RepositoryService_userLogin_args__isset {
  _RepositoryService_userLogin_args__isset() : repo_name(false), username(false), password(false) {}
  bool repo_name;
  bool username;
  bool password;
} _RepositoryService_userLogin_args__isset;

class RepositoryService_userLogin_args {
 public:

  RepositoryService_userLogin_args() : repo_name(""), username("anonymouse"), password("anonymouse") {
  }

  virtual ~RepositoryService_userLogin_args() throw() {}

  std::string repo_name;
  std::string username;
  std::string password;

  _RepositoryService_userLogin_args__isset __isset;

  bool operator == (const RepositoryService_userLogin_args & rhs) const
  {
    if (!(repo_name == rhs.repo_name))
      return false;
    if (!(username == rhs.username))
      return false;
    if (!(password == rhs.password))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_userLogin_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_userLogin_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RepositoryService_userLogin_pargs {
 public:


  virtual ~RepositoryService_userLogin_pargs() throw() {}

  const std::string* repo_name;
  const std::string* username;
  const std::string* password;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_userLogin_result__isset {
  _RepositoryService_userLogin_result__isset() : ire(false), ue(false) {}
  bool ire;
  bool ue;
} _RepositoryService_userLogin_result__isset;

class RepositoryService_userLogin_result {
 public:

  RepositoryService_userLogin_result() {
  }

  virtual ~RepositoryService_userLogin_result() throw() {}

  AuthenticationException ire;
  UnavailableException ue;

  _RepositoryService_userLogin_result__isset __isset;

  bool operator == (const RepositoryService_userLogin_result & rhs) const
  {
    if (!(ire == rhs.ire))
      return false;
    if (!(ue == rhs.ue))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_userLogin_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_userLogin_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_userLogin_presult__isset {
  _RepositoryService_userLogin_presult__isset() : ire(false), ue(false) {}
  bool ire;
  bool ue;
} _RepositoryService_userLogin_presult__isset;

class RepositoryService_userLogin_presult {
 public:


  virtual ~RepositoryService_userLogin_presult() throw() {}

  AuthenticationException ire;
  UnavailableException ue;

  _RepositoryService_userLogin_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class RepositoryService_getUserPermissionMask_args {
 public:

  RepositoryService_getUserPermissionMask_args() {
  }

  virtual ~RepositoryService_getUserPermissionMask_args() throw() {}


  bool operator == (const RepositoryService_getUserPermissionMask_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const RepositoryService_getUserPermissionMask_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_getUserPermissionMask_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RepositoryService_getUserPermissionMask_pargs {
 public:


  virtual ~RepositoryService_getUserPermissionMask_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_getUserPermissionMask_result__isset {
  _RepositoryService_getUserPermissionMask_result__isset() : success(false), authnx(false) {}
  bool success;
  bool authnx;
} _RepositoryService_getUserPermissionMask_result__isset;

class RepositoryService_getUserPermissionMask_result {
 public:

  RepositoryService_getUserPermissionMask_result() : success(0) {
  }

  virtual ~RepositoryService_getUserPermissionMask_result() throw() {}

  int8_t success;
  AuthenticationException authnx;

  _RepositoryService_getUserPermissionMask_result__isset __isset;

  bool operator == (const RepositoryService_getUserPermissionMask_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(authnx == rhs.authnx))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_getUserPermissionMask_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_getUserPermissionMask_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_getUserPermissionMask_presult__isset {
  _RepositoryService_getUserPermissionMask_presult__isset() : success(false), authnx(false) {}
  bool success;
  bool authnx;
} _RepositoryService_getUserPermissionMask_presult__isset;

class RepositoryService_getUserPermissionMask_presult {
 public:


  virtual ~RepositoryService_getUserPermissionMask_presult() throw() {}

  int8_t* success;
  AuthenticationException authnx;

  _RepositoryService_getUserPermissionMask_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RepositoryService_addTextData_args__isset {
  _RepositoryService_addTextData_args__isset() : content(false), categories(false), default_expire_time(false) {}
  bool content;
  bool categories;
  bool default_expire_time;
} _RepositoryService_addTextData_args__isset;

class RepositoryService_addTextData_args {
 public:

  RepositoryService_addTextData_args() : content(""), categories("default"), default_expire_time(0) {
  }

  virtual ~RepositoryService_addTextData_args() throw() {}

  std::string content;
  std::string categories;
  int32_t default_expire_time;

  _RepositoryService_addTextData_args__isset __isset;

  bool operator == (const RepositoryService_addTextData_args & rhs) const
  {
    if (!(content == rhs.content))
      return false;
    if (!(categories == rhs.categories))
      return false;
    if (!(default_expire_time == rhs.default_expire_time))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_addTextData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_addTextData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RepositoryService_addTextData_pargs {
 public:


  virtual ~RepositoryService_addTextData_pargs() throw() {}

  const std::string* content;
  const std::string* categories;
  const int32_t* default_expire_time;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_addTextData_result__isset {
  _RepositoryService_addTextData_result__isset() : success(false), authnx(false), ue(false), te(false) {}
  bool success;
  bool authnx;
  bool ue;
  bool te;
} _RepositoryService_addTextData_result__isset;

class RepositoryService_addTextData_result {
 public:

  RepositoryService_addTextData_result() : success("") {
  }

  virtual ~RepositoryService_addTextData_result() throw() {}

  UUID success;
  AuthenticationException authnx;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_addTextData_result__isset __isset;

  bool operator == (const RepositoryService_addTextData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(authnx == rhs.authnx))
      return false;
    if (!(ue == rhs.ue))
      return false;
    if (!(te == rhs.te))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_addTextData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_addTextData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_addTextData_presult__isset {
  _RepositoryService_addTextData_presult__isset() : success(false), authnx(false), ue(false), te(false) {}
  bool success;
  bool authnx;
  bool ue;
  bool te;
} _RepositoryService_addTextData_presult__isset;

class RepositoryService_addTextData_presult {
 public:


  virtual ~RepositoryService_addTextData_presult() throw() {}

  UUID* success;
  AuthenticationException authnx;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_addTextData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RepositoryService_modifyTextData_args__isset {
  _RepositoryService_modifyTextData_args__isset() : repo_name(false), instance_id(false), new_content(false) {}
  bool repo_name;
  bool instance_id;
  bool new_content;
} _RepositoryService_modifyTextData_args__isset;

class RepositoryService_modifyTextData_args {
 public:

  RepositoryService_modifyTextData_args() : repo_name(""), instance_id(""), new_content("") {
  }

  virtual ~RepositoryService_modifyTextData_args() throw() {}

  std::string repo_name;
  UUID instance_id;
  std::string new_content;

  _RepositoryService_modifyTextData_args__isset __isset;

  bool operator == (const RepositoryService_modifyTextData_args & rhs) const
  {
    if (!(repo_name == rhs.repo_name))
      return false;
    if (!(instance_id == rhs.instance_id))
      return false;
    if (!(new_content == rhs.new_content))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_modifyTextData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_modifyTextData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RepositoryService_modifyTextData_pargs {
 public:


  virtual ~RepositoryService_modifyTextData_pargs() throw() {}

  const std::string* repo_name;
  const UUID* instance_id;
  const std::string* new_content;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_modifyTextData_result__isset {
  _RepositoryService_modifyTextData_result__isset() : authnx(false), nfe(false), ue(false), te(false) {}
  bool authnx;
  bool nfe;
  bool ue;
  bool te;
} _RepositoryService_modifyTextData_result__isset;

class RepositoryService_modifyTextData_result {
 public:

  RepositoryService_modifyTextData_result() {
  }

  virtual ~RepositoryService_modifyTextData_result() throw() {}

  AuthenticationException authnx;
  NotFoundException nfe;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_modifyTextData_result__isset __isset;

  bool operator == (const RepositoryService_modifyTextData_result & rhs) const
  {
    if (!(authnx == rhs.authnx))
      return false;
    if (!(nfe == rhs.nfe))
      return false;
    if (!(ue == rhs.ue))
      return false;
    if (!(te == rhs.te))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_modifyTextData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_modifyTextData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_modifyTextData_presult__isset {
  _RepositoryService_modifyTextData_presult__isset() : authnx(false), nfe(false), ue(false), te(false) {}
  bool authnx;
  bool nfe;
  bool ue;
  bool te;
} _RepositoryService_modifyTextData_presult__isset;

class RepositoryService_modifyTextData_presult {
 public:


  virtual ~RepositoryService_modifyTextData_presult() throw() {}

  AuthenticationException authnx;
  NotFoundException nfe;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_modifyTextData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _RepositoryService_getTextURL_args__isset {
  _RepositoryService_getTextURL_args__isset() : repo_name(false), instance_id(false) {}
  bool repo_name;
  bool instance_id;
} _RepositoryService_getTextURL_args__isset;

class RepositoryService_getTextURL_args {
 public:

  RepositoryService_getTextURL_args() : repo_name(""), instance_id("") {
  }

  virtual ~RepositoryService_getTextURL_args() throw() {}

  std::string repo_name;
  UUID instance_id;

  _RepositoryService_getTextURL_args__isset __isset;

  bool operator == (const RepositoryService_getTextURL_args & rhs) const
  {
    if (!(repo_name == rhs.repo_name))
      return false;
    if (!(instance_id == rhs.instance_id))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_getTextURL_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_getTextURL_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RepositoryService_getTextURL_pargs {
 public:


  virtual ~RepositoryService_getTextURL_pargs() throw() {}

  const std::string* repo_name;
  const UUID* instance_id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_getTextURL_result__isset {
  _RepositoryService_getTextURL_result__isset() : success(false), authnx(false), ne(false), ue(false), te(false) {}
  bool success;
  bool authnx;
  bool ne;
  bool ue;
  bool te;
} _RepositoryService_getTextURL_result__isset;

class RepositoryService_getTextURL_result {
 public:

  RepositoryService_getTextURL_result() : success("") {
  }

  virtual ~RepositoryService_getTextURL_result() throw() {}

  URL success;
  AuthenticationException authnx;
  NotFoundException ne;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_getTextURL_result__isset __isset;

  bool operator == (const RepositoryService_getTextURL_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(authnx == rhs.authnx))
      return false;
    if (!(ne == rhs.ne))
      return false;
    if (!(ue == rhs.ue))
      return false;
    if (!(te == rhs.te))
      return false;
    return true;
  }
  bool operator != (const RepositoryService_getTextURL_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RepositoryService_getTextURL_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RepositoryService_getTextURL_presult__isset {
  _RepositoryService_getTextURL_presult__isset() : success(false), authnx(false), ne(false), ue(false), te(false) {}
  bool success;
  bool authnx;
  bool ne;
  bool ue;
  bool te;
} _RepositoryService_getTextURL_presult__isset;

class RepositoryService_getTextURL_presult {
 public:


  virtual ~RepositoryService_getTextURL_presult() throw() {}

  URL* success;
  AuthenticationException authnx;
  NotFoundException ne;
  UnavailableException ue;
  TimedOutException te;

  _RepositoryService_getTextURL_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RepositoryServiceClient : virtual public RepositoryServiceIf {
 public:
  RepositoryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  RepositoryServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void userLogin(const std::string& repo_name, const std::string& username, const std::string& password);
  void send_userLogin(const std::string& repo_name, const std::string& username, const std::string& password);
  void recv_userLogin();
  int8_t getUserPermissionMask();
  void send_getUserPermissionMask();
  int8_t recv_getUserPermissionMask();
  void addTextData(UUID& _return, const std::string& content, const std::string& categories, const int32_t default_expire_time);
  void send_addTextData(const std::string& content, const std::string& categories, const int32_t default_expire_time);
  void recv_addTextData(UUID& _return);
  void modifyTextData(const std::string& repo_name, const UUID& instance_id, const std::string& new_content);
  void send_modifyTextData(const std::string& repo_name, const UUID& instance_id, const std::string& new_content);
  void recv_modifyTextData();
  void getTextURL(URL& _return, const std::string& repo_name, const UUID& instance_id);
  void send_getTextURL(const std::string& repo_name, const UUID& instance_id);
  void recv_getTextURL(URL& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RepositoryServiceProcessor : virtual public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<RepositoryServiceIf> iface_;
  virtual bool process_fn(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (RepositoryServiceProcessor::*)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_userLogin(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getUserPermissionMask(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addTextData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_modifyTextData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTextURL(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RepositoryServiceProcessor(boost::shared_ptr<RepositoryServiceIf> iface) :
    iface_(iface) {
    processMap_["userLogin"] = &RepositoryServiceProcessor::process_userLogin;
    processMap_["getUserPermissionMask"] = &RepositoryServiceProcessor::process_getUserPermissionMask;
    processMap_["addTextData"] = &RepositoryServiceProcessor::process_addTextData;
    processMap_["modifyTextData"] = &RepositoryServiceProcessor::process_modifyTextData;
    processMap_["getTextURL"] = &RepositoryServiceProcessor::process_getTextURL;
  }

  virtual bool process(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~RepositoryServiceProcessor() {}
};

class RepositoryServiceMultiface : virtual public RepositoryServiceIf {
 public:
  RepositoryServiceMultiface(std::vector<boost::shared_ptr<RepositoryServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RepositoryServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RepositoryServiceIf> > ifaces_;
  RepositoryServiceMultiface() {}
  void add(boost::shared_ptr<RepositoryServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void userLogin(const std::string& repo_name, const std::string& username, const std::string& password) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->userLogin(repo_name, username, password);
    }
  }

  int8_t getUserPermissionMask() {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        return ifaces_[i]->getUserPermissionMask();
      } else {
        ifaces_[i]->getUserPermissionMask();
      }
    }
  }

  void addTextData(UUID& _return, const std::string& content, const std::string& categories, const int32_t default_expire_time) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->addTextData(_return, content, categories, default_expire_time);
        return;
      } else {
        ifaces_[i]->addTextData(_return, content, categories, default_expire_time);
      }
    }
  }

  void modifyTextData(const std::string& repo_name, const UUID& instance_id, const std::string& new_content) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      ifaces_[i]->modifyTextData(repo_name, instance_id, new_content);
    }
  }

  void getTextURL(URL& _return, const std::string& repo_name, const UUID& instance_id) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->getTextURL(_return, repo_name, instance_id);
        return;
      } else {
        ifaces_[i]->getTextURL(_return, repo_name, instance_id);
      }
    }
  }

};

}}} // namespace

#endif
