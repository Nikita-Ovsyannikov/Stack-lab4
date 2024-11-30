set(target ${STACK_CUSTOM_PROJECT})
project(${target})

file(GLOB STACK_HEADERS "*.h*")

add_custom_target(${target} SOURCES ${STACK_HEADERS})