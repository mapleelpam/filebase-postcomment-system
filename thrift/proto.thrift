
namespace java tw.maple.generated
namespace cpp tw.maple.generated

typedef string UUID

service PostSystem
{
    UUID    newPost( 1: string user, 2: string content ),
    bool    deletePost( 1: UUID post_id ),

    UUID    newComment( 1: UUID post_id, 2: string comment ),
    bool    rmComment( 1: UUID post_id, 2: UUID comment ),

    string  getContent( 1: UUID post_id ),

    void    ping();
}

