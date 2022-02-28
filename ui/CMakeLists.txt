cmake_minimum_required(VERSION 3.8)

project(main_entrance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES "src/main.cpp"
            "src/mainwindow.cpp"
            "src/mainwindow.hpp"
            "src/edge.hpp"
            "src/edge.cpp"
            "src/node.hpp"
            "src/node.cpp"
            "src/researchWidget.hpp"
            "src/researchWidget.cpp"
            "src/mainwindow.ui"
            "src/resources.qrc"
            "src/editTableWidget.hpp"
            "src/editTableWidget.cpp "
            "src/editTableWidget.ui"
            "src/emitterObject.hpp"
            "src/emitterObject.cpp"
            )

include_directories("../logic")
include_directories("../logic/Controllers")



find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets logic)
