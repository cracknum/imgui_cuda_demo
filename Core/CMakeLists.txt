
project(Core)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(source_files
        src/Application.cpp
)

set(header_files
        include/Application.hpp
        include/CoreExport.h
)

add_library(${PROJECT_NAME} SHARED ${source_files} ${header_files})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(
        ${PROJECT_NAME} PUBLIC
        Window
        )
target_compile_definitions(${PROJECT_NAME} PRIVATE CORE_EXPORTS)