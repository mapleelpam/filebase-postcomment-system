
namespace java tw.maple.generated
namespace cpp tw.maple.generated

typedef string UUID
typedef string URL

#
# Exceptions
# (note that internal server errors will raise a TApplicationException, courtesy of Thrift)
#

/** A specific column was requested that does not exist. */
exception NotFoundException {
    1: required string why
}

exception InvalidRequestException {
    1: required string why
}

exception UnavailableException {
    1: required string why
}

exception TimedOutException {
    1: required string why
}

exception AuthenticationException {
    1: required string why
}

exception AuthorizationException {
    1: required string why
}


enum DataFormat
{
    TEXT,
    IMAGE,
    AUDIO,
    VIDEO,
}

service TokenService
{
    string getToken(1: string userId, 2: i32 default_expire_time = 30), // minutes

    void removeToken(1: string token)
        throws (1: NotFoundException nfe),

    void checkToken(1: string token)
        throws (1: NotFoundException nfe),

    string getURL(1: string token, 2: string itemKey="")
        throws (1: NotFoundException nfe),
}

service RepositoryService
{
    void userLogin( 1: string repo_name, 2: string username="anonymouse", 3: string password="anonymouse")
        throws (1:AuthenticationException ire,
                2:UnavailableException ue),
    byte    getUserPermissionMask()
        throws (1:AuthenticationException authnx),

    UUID addTextData( 1: string content, 2: string categories = "default", 3: i32 default_expire_time = 0 /*zero for presistent, minutes*/ )
        throws (1:AuthenticationException authnx,
                2:UnavailableException ue,
                3:TimedOutException te),
    void modifyTextData( 1: string repo_name, 2: UUID instance_id, 3: string new_content )
        throws (1:AuthenticationException authnx,
                2:NotFoundException nfe,
                3:UnavailableException ue,
                4:TimedOutException te),

    URL getTextURL( 1: string repo_name, 2: UUID instance_id )
        throws (1:AuthenticationException authnx,
                2:NotFoundException ne,
                3:UnavailableException ue,
                4:TimedOutException te),
}
