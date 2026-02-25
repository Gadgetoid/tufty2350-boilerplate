if (NOT DEFINED PSRAM_ONCE)
    set (PSRAM_ONCE TRUE)

    add_library(psram INTERFACE)

    target_sources(psram INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/psram.c
    )

    target_include_directories(psram INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
    )
endif()