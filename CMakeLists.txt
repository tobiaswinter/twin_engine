cmake_minimum_required(VERSION 3.9)
project(twin_engine)

set(CMAKE_PREFIX_PATH "$ENV{QT_SDK_PATH}/lib/cmake")
MESSAGE("$ENV{QT_SDK_PATH}/lib/cmake")

set(CMAKE_CXX_STANDARD 11)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Turn on automatic invocation of the MOC
set(CMAKE_AUTOMOC ON)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Make this a GUI application on Windows
if (WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
endif ()

# Find the Qt library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

# Add the Qt5 for linking
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Core)

target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++ -static)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Widgets>
        $<TARGET_FILE:Qt5::Core>
        $<TARGET_FILE:Qt5::Gui>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

