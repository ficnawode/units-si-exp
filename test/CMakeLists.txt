set(NAME unit_tests)

add_executable(${NAME})

target_link_libraries(${NAME}
PUBLIC
    gtest 
    gtest_main
    
    units
)

target_include_directories(${NAME}
PRIVATE 
    include/
)

target_sources(${NAME}
PRIVATE
    src/unit_mismatch_test.cpp
    src/length_test.cpp
)

add_custom_target(${NAME}.run
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS ${NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    USES_TERMINAL
)

gtest_discover_tests(${NAME})