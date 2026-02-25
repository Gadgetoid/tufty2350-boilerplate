cmake_minimum_required(VERSION 3.12)

set(PICO_PLATFORM rp2350-arm-s)
set(PICO_BOARD_HEADER_DIRS ${CMAKE_CURRENT_LIST_DIR})
set(PICO_BOARD pimoroni_tufty2350)

# Change your executable name to something creative!
set(NAME tufty2350-boilerplate) # <-- Name your project/executable here!

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

# Gooey boilerplate
project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/lib")
include_directories(${CMAKE_CURRENT_LIST_DIR}/lib)

include(picovector/picovector)
include(st7789/st7789)
include(powman/powman)
include(psram/psram)

# Add your source files
add_executable(${NAME}
    src/main.cpp # <-- Add source files here!
)

# Include required libraries
# This assumes `pimoroni-pico` is stored alongside your project
include(common/pimoroni_i2c)
include(common/pimoroni_bus)

target_compile_definitions(powman INTERFACE TUFTY=1)

# Use the first 320*240*4 bytes of PSRAM to store the ST7789 framebuffer
target_compile_definitions(st7789 INTERFACE ST7789_FRAMEBUFFER_IN_PSRAM=1)

# Don't forget to link the libraries you need!
target_link_libraries(${NAME}
    picovector
    powman
    st7789
    psram
    pico_stdlib
    pico_multicore
    pimoroni_i2c
    hardware_interp
)

# Configure the SD Card library for Presto
target_compile_definitions(${NAME} PRIVATE
  PICO_EMBED_XIP_SETUP=1
  PICO_CLOCK_AJDUST_PERI_CLOCK_WITH_SYS_CLOCK=1
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# Enable USB UART output only
pico_enable_stdio_uart(${NAME} 0)
pico_enable_stdio_usb(${NAME} 1)

# Set up files for the release packages
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_PACKAGE_FILE_NAME ${NAME})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)