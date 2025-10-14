
project(Render)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(source_files
        src/OpenGLFrameBuffer.cpp
        src/OpenGLVertexIndexBuffer.cpp
        src/Shader.cpp
)


add_library(${PROJECT_NAME} SHARED ${source_files})
target_include_directories(${PROJECT_NAME} PUBLIC include ${CONFIG_FILE_PATH})
target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        glfw
        glad::glad
        glm

)

target_compile_definitions(${PROJECT_NAME} PRIVATE RENDER_EXPORTS)