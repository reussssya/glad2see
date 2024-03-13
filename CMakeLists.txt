cmake_minimum_required(VERSION 3.15)
project(glad2see)

set(vendor ${PROJECT_SOURCE_DIR}/vendor)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


file(GLOB discord "discordrpc.cpp" "discordrpc.h" "vendor/discord-rpc/include/*.cpp" "vendor/discord-rpc/include/*.h")
file(GLOB windows "windows/*.cpp" "windows/*.h")
file(GLOB imgui   "vendor/imgui/*.cpp" "vendor/imgui/*.h")
file(GLOB db "data/*.cpp" "data/*.h")
file(GLOB player "trackplayer.cpp" "trackplayer.h")
include_directories(${vendor})

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message("Configuring for x86 architecture")
    set(CMAKE_VS_PLATFORM_TOOLSET "v142")
    set(CMAKE_GENERATOR_PLATFORM "Win32")
endif()

# Условие для x64 архитектуры
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message("Configuring for x64 architecture")
    set(CMAKE_VS_PLATFORM_TOOLSET "v142")
    set(CMAKE_GENERATOR_PLATFORM "x64")
endif()

add_executable(glad2see
    #WIN32
    ${imgui}
    ${db}
    ${windows}
    main.cpp
    ${discord}
    ${player}
    

)

#target_link_options(glad2see PRIVATE "/MANIFESTUAC:level='requireAdministrator'" PRIVATE "/MANIFESTUAC:uiAccess='false'")

target_compile_features(glad2see PRIVATE cxx_std_17)
target_include_directories(glad2see PUBLIC ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/include ${PROJECT_SOURCE_DIR}/vendor/mysql-connector/include)

target_link_libraries(glad2see OpenGL32 ${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll.lib ${PROJECT_SOURCE_DIR}/vendor/mysql-connector/lib64/vs14/*.lib)
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/discord-rpc/lib/x86_64/discord_game_sdk.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)
#[[
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/imgui/lib64/libcrypto-3-x64.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/imgui/lib64/libssl-3-x64.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)

add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/imgui/lib64/mysqlcppconn-9-vs14.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)
add_custom_command(TARGET glad2see
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${PROJECT_SOURCE_DIR}/vendor/imgui/lib64/mysqlcppconn8-2-vs14.dll" "${CMAKE_CURRENT_BINARY_DIR}/Debug"
    COMMENT "Copy dll file to ${CMAKE_CURRENT_BINARY_DIR} directory" VERBATIM
)
#]]