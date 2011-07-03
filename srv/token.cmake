
PROJECT(tokend)


SET( PROTP_THRIFT_SRC ${CMAKE_SOURCE_DIR}/gen-cpp/TokenService.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_constants.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_types.cpp )

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/gen-cpp
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( tokend
    ${CMAKE_SOURCE_DIR}/srv/token_srv.cpp
    ${CMAKE_SOURCE_DIR}/srv/token_dispatch.cpp
    ${PROTP_THRIFT_SRC}
    )

TARGET_LINK_LIBRARIES( tokend
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )
