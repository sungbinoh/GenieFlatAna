# Specify the source files for the library
set(SOURCES
  Particle.C
  Event.C
)

set(HDRFILES
  Particle.h
  Event.h
)

# Create the shared library
add_library(DataFormats SHARED ${SOURCES})

# Specify output directory for the shared library
set_target_properties(DataFormats PROPERTIES
  PUBLIC_HEADER "${HDRFILES}"
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)

# Link the library with ROOT
target_link_libraries(DataFormats PUBLIC ${ROOT_LIBRARIES})

install(TARGETS DataFormats
    EXPORT PDSPTreeAnalyzer-targets
    PUBLIC_HEADER DESTINATION include/DataFormats COMPONENT Development)
