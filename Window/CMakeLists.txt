
project(Window)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(source_files
        src/Window.cpp
        src/OpenGLContext.cpp
        src/RenderContext.cpp
        src/UIContext.cpp
)

add_library(${PROJECT_NAME} SHARED ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        Widgets

)
target_compile_definitions(${PROJECT_NAME} PRIVATE WINDOW_EXPORTS)