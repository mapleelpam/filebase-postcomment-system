
# ProgrameNode Translator 
# Copyright 2011 mapleellpam@gmail.com.  All rights reserved.

# Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

PROJECT( repod)


SET( PROTP_THRIFT_SRC ${CMAKE_SOURCE_DIR}/gen-cpp/RepositoryService.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_constants.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_types.cpp )

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/gen-cpp
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( repod
    ${CMAKE_SOURCE_DIR}/srv/repo_srv.cpp
    ${PROTP_THRIFT_SRC} 
    )

TARGET_LINK_LIBRARIES( repod
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )
