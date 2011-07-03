/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#include "proto_types.h"

namespace tw { namespace maple { namespace generated {

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

const char* NotFoundException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t NotFoundException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t NotFoundException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t NotFoundException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("NotFoundException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* InvalidRequestException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t InvalidRequestException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t InvalidRequestException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t InvalidRequestException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("InvalidRequestException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* UnavailableException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t UnavailableException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t UnavailableException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t UnavailableException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("UnavailableException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* TimedOutException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t TimedOutException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t TimedOutException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t TimedOutException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("TimedOutException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* AuthenticationException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t AuthenticationException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t AuthenticationException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t AuthenticationException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("AuthenticationException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* AuthorizationException::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t AuthorizationException::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t AuthorizationException::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_why = false;

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
          xfer += iprot->readString(this->why);
          isset_why = true;
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

  if (!isset_why)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t AuthorizationException::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("AuthorizationException");
  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

}}} // namespace
