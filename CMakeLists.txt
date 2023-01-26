cmake_minimum_required(VERSION 3.10.0)

set(Qt5_DIR C:/QtForVs/5.15.2/msvc2019_64/lib/cmake/Qt5)

find_package(Protobuf REQUIRED)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Sql Quick Gui REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS rustapi/includes/proto/rustplus.proto)

add_executable(glad2see
    data/database.cpp
    #data/database.h
    windows/mainwindow.cpp
    #windows/mainwindow.h
    #windows/joinwindow.h
    windows/joinwindow.cpp
    main.cpp
    rustapi/rustplus.cpp
    common.h
    ${PROTO_SRCS} 
    ${PROTO_HDRS}
)

target_compile_features(glad2see PRIVATE cxx_std_17)
target_link_libraries(glad2see Qt5::Widgets Qt5::Sql Qt5::Gui Qt5::Quick ${Protobuf_LIBRARIES})