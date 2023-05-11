# Custom FindPortAudio module for CMake
# Looks for the PortAudio library and sets the necessary variables

# Set the default search paths
set(PORTAUDIO_SEARCH_PATHS /usr/local /usr /opt/local /sw /opt/csw /opt)

# Search for the PortAudio library
find_library(PORTAUDIO_LIBRARY
    NAMES portaudio
    PATHS ${PORTAUDIO_SEARCH_PATHS}
)

# Check if PortAudio was found
if (NOT PORTAUDIO_LIBRARY)
    message(FATAL_ERROR "PortAudio library not found!")
else()
    message(STATUS "Found PortAudio: ${PORTAUDIO_LIBRARY}")
endif()

# Set the include directory
find_path(PORTAUDIO_INCLUDE_DIR portaudio.h
    PATHS ${PORTAUDIO_SEARCH_PATHS}
    PATH_SUFFIXES include
)

# Check if the include directory was found
if (NOT PORTAUDIO_INCLUDE_DIR)
    message(FATAL_ERROR "PortAudio include directory not found!")
else()
    message(STATUS "Found PortAudio include directory: ${PORTAUDIO_INCLUDE_DIR}")
endif()

# Set the PortAudio library and include directory variables
set(PORTAUDIO_LIBRARIES ${PORTAUDIO_LIBRARY})
set(PORTAUDIO_INCLUDE_DIRS ${PORTAUDIO_INCLUDE_DIR})

