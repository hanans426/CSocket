cmake_minimum_required(VERSION 3.14)
project("CSocket")

set(CMAKE_CXX_STANDARD 14)
#
#add_executable(${PROJECT_NAME}
#        src/Server.cpp src/Client.cpp include/Server.h include/Client.h include/socketUtil.h include/unixbase.h)
add_executable(server src/ServerMain.cpp src/Server.cpp include/Server.h include/socketUtil.h include/unixbase.h)
add_executable(client src/ClientMain.cpp src/Client.cpp include/Client.h include/socketUtil.h  include/unixbase.h)

#target_include_directories(${PROJECT_NAME}
#        PRIVATE
#        ${PROJECT_SOURCE_DIR}/include
#
#)

target_include_directories(server
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include

        )
target_include_directories(client
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include

        )

set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.13.1")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CTerminal.cpp  CatalogTree.cpp)

find_package(Qt5Widgets REQUIRED)

target_link_libraries(server Qt5::Widgets)
target_link_libraries(client Qt5::Widgets)

if(WIN32) # Check if we are on Windows
    message("compile on windows.")
    find_library(WS2_LIBRARY ws2_32)
elseif(UNIX)
    message("compile on UNIX")
    find_package(Threads REQUIRED)
else()
    message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
endif()

if(WIN32) # Check if we are on Windows
    target_link_libraries( ${PROJECT_NAME}
            PRIVATE
            ${WS2_LIBRARY}
            )
elseif(UNIX)
    target_link_libraries(server
            PRIVATE
            ${CMAKE_THREAD_LIBS_INIT}
            )
    target_link_libraries(client
            PRIVATE
            ${CMAKE_THREAD_LIBS_INIT}
            )
endif()

