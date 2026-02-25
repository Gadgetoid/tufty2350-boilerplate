if (NOT DEFINED POWMAN_ONCE)
    set (POWMAN_ONCE TRUE)

    add_library(powman INTERFACE)

    target_sources(powman INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/powman.c
        ${CMAKE_CURRENT_LIST_DIR}/rosc.c
    )

    target_include_directories(powman INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
    )

    target_link_libraries(powman INTERFACE hardware_powman hardware_gpio)

    set_source_files_properties(
        ${CMAKE_CURRENT_LIST_DIR}/bindings.c
        PROPERTIES COMPILE_FLAGS
        "-Wno-discarded-qualifiers"
)
endif()