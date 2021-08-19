set(target SimpleRenderContext)

set( SimpleRenderContext_SOURCES main.cpp)

add_executable( ${target} ${SimpleRenderContext_SOURCES} )
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries( ${target} ${LINK_LIBS})