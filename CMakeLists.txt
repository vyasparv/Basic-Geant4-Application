#Minimum version of cmake required for compiling project
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

#Name of project
project(G4fisica)

option(WITH_GEANT4_UIVIS "Build with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# The name of the excecutable we will use and the files that will be linked to it
add_executable(fisica fisica.cc ${sources} ${headers})

# The Geant4 libraries that will be linked to our excecutable
target_link_libraries(fisica ${Geant4_LIBRARIES})

#Linking the executable with project
add_custom_target(G4fisica DEPENDS fisica)

# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
install(TARGETS G4fisica DESTINATION bin)

