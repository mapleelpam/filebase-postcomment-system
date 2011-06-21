
# ProgrameNode Translator 
# Copyright 2011 mapleellpam@gmail.com.  All rights reserved.

# Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

PROJECT( repo_cli )


SET( PROTP_THRIFT_SRC ${CMAKE_SOURCE_DIR}/gen-cpp/RepositoryService.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_constants.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_types.cpp )

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/gen-cpp/
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( repo_cli
    ${CMAKE_CURRENT_SOURCE_DIR}/repo_cli.cpp
    ${PROTP_THRIFT_SRC} 
    )

TARGET_LINK_LIBRARIES( repo_cli
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )
