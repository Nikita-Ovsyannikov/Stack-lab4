set(target ${STACK_TESTS})

file(GLOB STACK_HEADERS "*.h*")
file(GLOB STACK_SOURCES "*.cpp")

add_executable(${target} ${STACK_SOURCES} ${STACK_HEADERS})
target_link_libraries(${target} gtest)
target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/gtest ${STACK_INCLUDE})
add_test(${target} ${target})