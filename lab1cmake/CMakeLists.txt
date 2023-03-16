# CMakeList.txt : CMake project for lab1cmake, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (lab1.1 "lab1cmake.cpp" "lab1cmake.h")
add_executable(lab1.2 "lab1.2.cpp")
add_executable(lab1.3 "lab1.3.cpp")
add_executable(lab1.4 "lab1.4.cpp")
add_executable(lab1.5 "lab1.5.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab1.1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
