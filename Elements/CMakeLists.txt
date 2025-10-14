
project(Elements)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(source_files
        src/Camera.cpp
        src/Mesh.cpp
        src/Light.cpp
)

add_library(${PROJECT_NAME} SHARED ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        glm
        Render
        assimp::assimp
)
target_compile_definitions(${PROJECT_NAME} PRIVATE ELEMENTS_EXPORTS)