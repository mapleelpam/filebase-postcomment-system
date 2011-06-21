/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include "proto_types.h"

namespace tw { namespace maple { namespace generated {

int _kErrorCodeValues[] = {
  ErrorCode::SUCCESS,
  ErrorCode::LOGIN_FAIL,
  ErrorCode::CANT_FOUND_REPO,
  ErrorCode::CANT_FOUND_UUID
};
const char* _kErrorCodeNames[] = {
  "SUCCESS",
  "LOGIN_FAIL",
  "CANT_FOUND_REPO",
  "CANT_FOUND_UUID"
};
const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kErrorCodeValues, _kErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kDataFormatValues[] = {
  DataFormat::TEXT,
  DataFormat::IMAGE,
  DataFormat::AUDIO,
  DataFormat::VIDEO
};
const char* _kDataFormatNames[] = {
  "TEXT",
  "IMAGE",
  "AUDIO",
  "VIDEO"
};
const std::map<int, const char*> _DataFormat_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDataFormatValues, _kDataFormatNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* URL_Response::ascii_fingerprint = "D6FD826D949221396F4FFC3ECCD3D192";
const uint8_t URL_Response::binary_fingerprint[16] = {0xD6,0xFD,0x82,0x6D,0x94,0x92,0x21,0x39,0x6F,0x4F,0xFC,0x3E,0xCC,0xD3,0xD1,0x92};

uint32_t URL_Response::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->address);
          this->__isset.address = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->error = (ErrorCode::type)ecast0;
          this->__isset.error = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t URL_Response::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("URL_Response");
  xfer += oprot->writeFieldBegin("address", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->address);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("error", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->error);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}}} // namespace
