project(FilterCalculator)
cmake_minimum_required(VERSION 3.14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

find_package(Qt5 COMPONENTS
        Widgets
        Qml
        Quick
        REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/qml/view.qrc ${CMAKE_CURRENT_SOURCE_DIR}/res/res.qrc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(FilterCalculator main.cpp ${SRC} ${QT_RESOURCES})
target_link_libraries(FilterCalculator
        Qt5::Widgets
        Qt5::Qml
        Qt5::Quick)
