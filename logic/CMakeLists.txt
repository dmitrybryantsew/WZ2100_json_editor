cmake_minimum_required(VERSION 3.8)

project(logic LANGUAGES CXX)


set( SOURCES
        "Controllers/JsonDataController.cpp"
        "Controllers/mainController.cpp"
        "Controllers/editTableController.cpp"
        "Models/JsonDataModel.cpp"
        "Models/editTableModel.cpp"
        "connectionsNode.cpp"
        "connectionGraph.cpp"
        "Controllers/JsonDataController.hpp"
        "Controllers/mainController.hpp"
        "Controllers/editTableController.hpp"
        "Models/JsonDataModel.hpp"
        "Models/editTableModel.hpp"
        "connectionsNode.hpp"
        "connectionGraph.hpp"
    )


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${CMAKE_CURRENT_LIST_DIR}/Controllers/")
include_directories("${CMAKE_CURRENT_LIST_DIR}/Models/")
find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core )

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
