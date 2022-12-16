cmake_minimum_required(VERSION 3.1.0)

project(glad2see VERSION 1.0.0 LANGUAGES CXX)

set(Qt5_DIR C:/QtForVs/5.15.2/msvc2019_64/lib/cmake/Qt5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

add_executable(glad2see
    data/database.cpp
    data/database.h
    windows/mainwindow.cpp
    windows/mainwindow.h
    windows/regwindow.h
    windows/regwindow.cpp
    main.cpp
    main.h
    common.h
)

target_link_libraries(glad2see Qt5::Widgets Qt5::Sql)