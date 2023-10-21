cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
set(PROJECT_NAME frostEngine)
project(${PROJECT_NAME})
set(SOURCES
    src/main.cpp
    src/shader.cpp
    src/texture.cpp
    src/game.cpp
    src/resource_manager.cpp)
set(HEADERS
    src/shader.h
    src/texture.h
    src/game.h
    src/resource_manager.h)
    src/stb_image.h
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)
include_directories(external/glm)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)