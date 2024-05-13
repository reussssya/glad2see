cmake_minimum_required(VERSION 3.15)
project(glad2see)

set(vendor ${PROJECT_SOURCE_DIR}/vendor)
#set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_AUTOMOC ON)

find_package(libmysqlclient REQUIRED)
find_package(spdlog REQUIRED)

find_package(Qt6 COMPONENTS Core Widgets)
qt6_add_resources(QT_RESOURCES resources.qrc)
file(GLOB discord "discordrpc.cpp" 
    "discordrpc.h" 
    "vendor/discord-rpc/include/*.cpp" 
    "vendor/discord-rpc/include/*.h"
)
file(GLOB windows "windows/*.cpp" "windows/*.h")
file(GLOB db "data/*.cpp" "data/*.h")
file(GLOB player "trackplayer.cpp" "trackplayer.h")
include_directories(${vendor})

add_executable(glad2see
    #WIN32
    ${QT_RESOURCES}
    data/img/trayIcon.ico
    resources.rc
    ${db}
    ${windows}
    main.cpp
    g2s.cpp
    g2s.h
    ${discord}
    ${player}
    

)

#target_link_options(glad2see PRIVATE "/MANIFESTUAC:level='requireAdministrator'" PRIVATE "/MANIFESTUAC:uiAccess='false'")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/include
    ${PROJECT_SOURCE_DIR}/vendor/glfw/include
)

target_link_libraries(${PROJECT_NAME} OpenGL32 
    ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll.lib
    libmysqlclient::libmysqlclient
    spdlog::spdlog
    Qt6::Core
    Qt6::Widgets
    Qt6::QWindowsIntegrationPlugin
)
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)