cmake_minimum_required(VERSION 3.14)

project(AltRepoApi LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(AltRepoApi SHARED
  AltRepoApi_global.h
  altrepoapi.cpp
  altrepoapi.h
  binarypackages.h
  binarypackages.cpp
  jsonhttploader.h
  jsonhttploader.cpp
)

target_link_libraries(AltRepoApi PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(AltRepoApi PRIVATE ALTREPOAPI_LIBRARY)
