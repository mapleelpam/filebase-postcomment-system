
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3)

PROJECT( "FileBasePostCommentSystem" )

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin CACHE PATH "Default executable path" FORCE)

SET(CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/CMake"
    "${CMAKE_SOURCE_DIR}/CMake/Packages"
    )

SET( PROTO_THRIFT "${CMAKE_SOURCE_DIR}/thrift/proto.thrift")

make_directory( ${CMAKE_SOURCE_DIR}/lib/ )
make_directory( ${CMAKE_SOURCE_DIR}/bin/ ) 

FIND_PACKAGE(Thrift REQUIRED) 
FIND_PACKAGE(Boost REQUIRED thread date_time program_options unit_test_framework filesystem regex system serialization)


execute_process( COMMAND ${THRIFT_COMPILER} -r -o ${CMAKE_CURRENT_SOURCE_DIR} --gen cpp ${PROTO_THRIFT})


#ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/project/pn-translator/ )
ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/srv/ )
ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/cli/ )



