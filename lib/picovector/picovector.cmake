if (NOT DEFINED PICOVECTOR_ONCE)
  set (PICOVECTOR_ONCE TRUE)

  add_library(picovector INTERFACE)

  include(${CMAKE_CURRENT_LIST_DIR}/../pngdec/pngdec.cmake)
  include(${CMAKE_CURRENT_LIST_DIR}/../jpegdec/jpegdec.cmake)

  list(APPEND SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/picovector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/shape.cpp
    ${CMAKE_CURRENT_LIST_DIR}/font.cpp
    ${CMAKE_CURRENT_LIST_DIR}/pixel_font.cpp
    ${CMAKE_CURRENT_LIST_DIR}/image.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brush.cpp
    ${CMAKE_CURRENT_LIST_DIR}/color.cpp
    ${CMAKE_CURRENT_LIST_DIR}/primitive.cpp
    ${CMAKE_CURRENT_LIST_DIR}/algorithms/geometry.cpp
    ${CMAKE_CURRENT_LIST_DIR}/algorithms/dda.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brushes/pattern.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brushes/color.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brushes/image.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/blur.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/dither.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/monochrome.cpp
    ${CMAKE_CURRENT_LIST_DIR}/filters/onebit.cpp
  )

  target_sources(picovector INTERFACE
    ${SOURCES}
  )

  target_include_directories(picovector INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(picovector INTERFACE pngdec jpegdec)

  target_compile_definitions(picovector INTERFACE PICO=1)

  set_source_files_properties(
    ${SOURCES}
    PROPERTIES COMPILE_FLAGS
    "-Wno-unused-variable"
  )

  if(DEFINED PICO_BOARD)
    set_source_files_properties(
      ${SOURCES}
      PROPERTIES COMPILE_OPTIONS
      "-O2;-fgcse-after-reload;-floop-interchange;-fpeel-loops;-fpredictive-commoning;-fsplit-paths;-ftree-loop-distribute-patterns;-ftree-loop-distribution;-ftree-vectorize;-ftree-partial-pre;-funswitch-loops"
    )
  endif()
endif()