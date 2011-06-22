#ifndef error_header_h

#define error_header_h

namespace tw { namespace test {

enum {
    SUCCESS,
    LOGIN_FAIL,
    CANT_FOUND_REPO,
    CANT_FOUND_UUID,
} ErrorCode;

}}
#endif
