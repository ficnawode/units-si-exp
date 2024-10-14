set(NAME units)

add_library(${NAME} INTERFACE)

target_link_libraries(${NAME} INTERFACE
    Microsoft.GSL::GSL
)

target_include_directories(${NAME} INTERFACE
    include/
)

target_sources(${NAME}
PRIVATE
    include/units/Dimension.hpp
    include/units/Quantity.hpp
)
