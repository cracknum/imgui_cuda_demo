
project(Widgets)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(source_files
        src/SceneView.cpp
        src/PropertyPanel.cpp
)

set(header_files
        include/SceneView.hpp
        include/PropertyPanel.hpp
)

add_library(${PROJECT_NAME} SHARED ${source_files} ${header_files})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        glm
        Elements
        imgui::imgui
        ImGuiHelper
)
target_compile_definitions(${PROJECT_NAME} PRIVATE WIDGETS_EXPORTS)