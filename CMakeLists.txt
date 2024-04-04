cmake_minimum_required (VERSION 3.8)

project ("NitroCppTest")

add_subdirectory(sourcecode/thirdparty/googletest-1.14.0/googletest)

include_directories(
    ${PROJECT_SOURCE_DIR}/sourcecode/thirdparty
    ${PROJECT_SOURCE_DIR}/sourcecode/app
    ${gtest_SOURCE_DIR}/include
)

# app sources
set(APP_SOURCES
    "sourcecode/app/app.cpp" 
    "sourcecode/app/app.h" 
)

set(CORE_SOURCES
    "sourcecode/app/solve.ixx" 
    "sourcecode/app/print.ixx" 
    "sourcecode/app/parse.ixx" 
    "sourcecode/app/common.ixx"
)

# Test sources
set(TEST_SOURCES
    "sourcecode/tests/unit_tests.cpp"
)

# Executable for the app
add_executable(${PROJECT_NAME} ${APP_SOURCES} ${CORE_SOURCES})

# Executable for the tests
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES} ${CORE_SOURCES})



# Link Google Test to the test executable
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${PROJECT_NAME}_test PROPERTY CXX_STANDARD 20)
endif()
