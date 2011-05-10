
# ProgrameNode Translator 
# Copyright 2011 mapleellpam@gmail.com.  All rights reserved.

# Author: mapleelpam at gmail.com - Kai-Feng Chou - maple

PROJECT( fdbd)


SET( PROTP_THRIFT_SRC ${CMAKE_SOURCE_DIR}/gen-cpp/PostSystem.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_constants.cpp ${CMAKE_SOURCE_DIR}/gen-cpp/proto_types.cpp )

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/
    ${THRIFT_INCLUDE_DIR}
    )

ADD_EXECUTABLE( fdbd
    ${CMAKE_SOURCE_DIR}/srv/main.cpp
    ${PROTP_THRIFT_SRC} 
    )

TARGET_LINK_LIBRARIES( fdbd
    ${THRIFT_LIBS}
    ${Boost_LIBRARIES}
    )
