
PROJECT(tokend)


SET( PROTP_THRIFT_SRC ${CMAKE_SOURCE_DIR}/gen-cpp/TokenService.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_constants.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_types.cpp )

INCLUDE_DIRECTORIES(
#    ${CMAKE_SOURCE_DIR}/gen-cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( tokend
    ${CMAKE_SOURCE_DIR}/srv/src/token_srv.cpp
    ${CMAKE_SOURCE_DIR}/srv/src/service/token/tokenmanager.cpp
    ${PROTP_THRIFT_SRC}
    )

TARGET_LINK_LIBRARIES( tokend
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )
