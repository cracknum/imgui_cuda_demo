cmake_minimum_required(VERSION 3.19...3.22)

set(CMAKE_TOOLCHAIN_FILE "F:/Workspace/github/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(OpenGLImgui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)


set(header_files
    include/Application.hpp
    include/RenderContext.hpp
    include/IWindow.hpp
    include/Window.hpp
    include/UIContext.hpp
    include/OpenGLContext.hpp
    include/PropertyPanel.hpp
)
set(source_files 
    src/Application.cpp
    src/RenderContext.cpp
    src/Window.cpp
    src/UIContext.cpp
    src/main.cpp
    src/OpenGLContext.cpp
    src/PropertyPanel.cpp
)

add_subdirectory(third_party)
configure_file(cmake/config.h.in config.h @ONLY)

add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui glfw glad::glad ImGuiHelper)
target_include_directories(${PROJECT_NAME} PRIVATE include ${CMAKE_CURRENT_BINARY_DIR})