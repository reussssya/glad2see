cmake_minimum_required(VERSION 3.10.0)
project(glad2see)

set(vendor ${PROJECT_SOURCE_DIR}/vendor)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Sql Quick Qml Gui Multimedia MultimediaWidgets REQUIRED)


file(GLOB discord "discordrpc.cpp" "discordrpc.h" "vendor/discord-rpc/include/*.cpp" "vendor/discord-rpc/include/*.h")
file(GLOB windows "windows/*.cpp" "windows/*.h")
file(GLOB resources "newdesign/resources.rc")
file(GLOB db "data/*.cpp" "data/*.h")
file(GLOB player "trackplayer.cpp" "trackplayer.h")
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS} ${vendor})

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

qt5_add_resources(QT_RESOURCES newdesign/resources.qrc)
add_executable(glad2see
    #WIN32
    ${resources}
    ${db}
    ${windows}
    main.cpp
    g2s.cpp
    ${QT_RESOURCES}
    ${discord}
    ${player}
    newdesign/newdesign.ui

)

#target_link_options(glad2see PRIVATE "/MANIFESTUAC:level='requireAdministrator'" PRIVATE "/MANIFESTUAC:uiAccess='false'")

target_compile_features(glad2see PRIVATE cxx_std_17)
target_include_directories(glad2see PUBLIC ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/include)

target_link_libraries(glad2see Qt5::Widgets Qt5::Sql Qt5::Gui Qt5::Quick Qt5::Qml Qt5::Multimedia Qt5::MultimediaWidgets ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll.lib) 
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)
