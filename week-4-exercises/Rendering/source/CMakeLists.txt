add_executable(Renderer Renderer.cpp Shapes.cpp ImageUtils.cpp)
target_include_directories(Renderer PUBLIC ${CMAKE_SOURCE_DIR}/include)
