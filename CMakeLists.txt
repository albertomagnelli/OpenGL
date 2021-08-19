cmake_minimum_required(VERSION 3.20)
project("OpenGL Tutorials")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE OFF)

find_package( Freetype REQUIRED )
find_package( assimp REQUIRED )
set( OpenGL_GL_PREFERENCE LEGACY )
find_package( OpenGL REQUIRED )
find_package( glfw3 CONFIG REQUIRED )


include_directories( ${FREETYPE_INCLUDE_DIRS} )
include_directories( libs/libSOIL2 )
include_directories( libs/libglad/include)

set ( LINK_LIBS SOIL2 glfw glad ${CMAKE_DL_LIBS} ${OPENGL_gl_LIBRARY} ${FREETYPE_LIBRARIES} ${ASSIMP_LIBRARIES} )

add_subdirectory( libs )
add_subdirectory( tutorials )
add_subdirectory( examples )