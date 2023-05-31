cmake_minimum_required(VERSION 3.7)
project(Waffle)

include_directories(Handlers)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../imgui)

set(SOURCE_FILES
        src/Waffle.cpp
        src/Waffle.h
        Handlers/Exception/Exceptions.h
        src/Components/WaffleButton.cpp
        src/Components/WaffleButton.h
        src/Components/WaffleComponent.cpp
        src/Components/WaffleComponent.h
        src/Components/WaffleComponents.h
        ../imgui/backends/imgui_impl_glfw.cpp
        ../imgui/backends/imgui_impl_opengl3.cpp
        ../imgui/imgui.cpp
        ../imgui/imgui_demo.cpp
        ../imgui/imgui_draw.cpp
        ../imgui/imgui_tables.cpp
        ../imgui/imgui_widgets.cpp
        src/Window/WaffleWindow.cpp
        src/Window/WaffleWindow.h
)

set(TARGET_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/../imgui
)

set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_library(Waffle ${SOURCE_FILES})

target_link_libraries(Waffle OpenGL::GL)
target_link_libraries(Waffle glfw)
target_include_directories(Waffle PUBLIC ${TARGET_DIRS})

