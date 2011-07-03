#ifndef error_header_h

#define error_header_h

namespace tw { namespace test {

enum ErrorCode {
    SUCCESS,
    LOGIN_FAIL,
    CANT_FOUND_REPO,
    CANT_FOUND_TOKEN,
    URL_EXPIRE,
    URL_FORMAT_ERROR,
};

}}
#endif
