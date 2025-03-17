

add_library(ball STATIC ball.cpp)
target_include_directories(ball PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(ball PUBLIC glm)

add_executable(hello-cmake main.cpp)
target_link_libraries(hello-cmake ball)
