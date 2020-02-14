cmake_minimum_required( VERSION 3.16 )
project( Typing-based-game
   VERSION 0.0.1
   DESCRIPTION "A Typing based game"
   LANGUAGES CXX
)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE )

set( CLANG_DEBUG_FLAGS "-o0 -g -Wall -Wextra -Weverything -Werror" )
set( CLANG_RELEASE_FLAGS "-o3" )

set( BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set( GLFW_BUILD_DOCS ON CACHE BOOL "" FORCE)

add_subdirectory( dependencies/linux/GLAD )
add_subdirectory( dependencies/linux/glfw )
add_subdirectory( dependencies/linux/glm )

add_executable( Typing-based-game )

set_target_properties( Typing-based-game
    PROPERTIES
        CXX_EXTENSIONS OFF
)

target_compile_definitions( Typing-based-game PRIVATE GLFW_INCLUDE_NONE )

target_compile_features( Typing-based-game 
    PRIVATE
        cxx_std_17
)

target_compile_options( Typing-based-game 
    PRIVATE
        $<$<PLATFORM_ID:UNIX>:-pthread>

        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:DEBUG>>:${CLANG_DEBUG_FLAGS}>
        $<$<AND:$<CXX_COMPILER_ID:Clang>,$<CONFIG:RELEASE>>:${CLANG_RELEASE_FLAGS}>
)

target_link_libraries( Typing-based-game
    PUBLIC
        glad
        glfw
        glm
)

target_sources( Typing-based-game
    PRIVATE
        "RPG/main.cpp"
        "RPG/Engine/GFX/Renderer.cpp"
        "RPG/Engine/Window.cpp"
)
