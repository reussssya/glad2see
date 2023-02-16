cmake_minimum_required(VERSION 3.10.0)

set(Qt5_DIR C:/QtForVs/5.15.2/msvc2019_64/lib/cmake/Qt5)

find_package(Protobuf REQUIRED)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Sql Quick Qml Gui REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS})

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS api/rustapi/rustapi.proto)

add_executable(glad2see
    data/database.cpp
    #data/database.h
    windows/mainwindow.cpp
    #windows/mainwindow.h
    #windows/joinwindow.h
    windows/joinwindow.cpp
    main.cpp
    api/rustapi/rustplus.cpp
    common.h
    api/rustapi/includes/easyws/easywsclient.cpp
    ${PROTO_SRCS} 
    ${PROTO_HDRS}
    ${QT_RESOURCES}
)

qt5_add_resources(QT_RESOURCES newdesign/main.qrc)
target_compile_features(glad2see PRIVATE cxx_std_17)
target_link_libraries(glad2see Qt5::Widgets Qt5::Sql Qt5::Gui Qt5::Quick Qt5::Qml ${Protobuf_LIBRARIES})