
namespace java tw.maple.generated
namespace cpp tw.maple.generated

typedef string UUID
typedef string URL

enum ErrorCode
{
	SUCCESS,
	LOGIN_FAIL,
	CANT_FOUND_REPO,
	CANT_FOUND_UUID,
}

struct URL_Response
{
	1: URL			address,
	2: ErrorCode	error,
}

service PostSystem
{
    UUID    newPost( 1: string user, 2: string content ),
    bool    deletePost( 1: UUID post_id ),

    UUID    newComment( 1: UUID post_id, 2: string comment ),
    bool    rmComment( 1: UUID post_id, 2: UUID comment ),

    string  getContent( 1: UUID post_id ),

    void    ping();
}

enum DataFormat
{
    TEXT,
    IMAGE,
    AUDIO,
    VIDEO,
}


service RepositoryService
{
    bool    userLogin( 1: string repo_name, 2: string username="anonymouse", 3: string password="anonymouse"),
    byte    getUserPermissionMask(),

    UUID    addTextData( 1: string content, 2: string categories = "default", 3: i32 default_expire_time = 0 /*zero for presistent, minutes*/ ),
    bool    modifyTextData( 1: string repo_name, 2: UUID instance_id, 3: string new_content ),

    URL_Response	getTextURL( 1: string repo_name, 2: UUID instance_id ),
   // URL_Response	getTextURL( 1: string repo_name, 2: UUID instance_id ),
}
