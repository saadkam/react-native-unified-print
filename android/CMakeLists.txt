cmake_minimum_required(VERSION 3.4.1)
project(UnifiedPrint)

set (CMAKE_VERBOSE_MAKEFILE ON)

add_library(
    react-native-unified-print    STATIC
    ../cpp/UnifiedPrintImpl.cpp
)

set_target_properties(
    react-native-unified-print PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_include_directories(
    react-native-unified-print    PUBLIC
    ../cpp
)

target_link_libraries(
    react-native-unified-print    jsi
    reactnative
    react_codegen_UnifiedPrintSpec
)
