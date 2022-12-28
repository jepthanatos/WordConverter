# Enable the export of compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Set the install prefix to the current working directory
set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Check the operating system
if(WIN32)
  # Set the C compiler on Windows
  set(CMAKE_C_COMPILER "G:/Programs/MSYS2/ucrt64/bin/x86_64-w64-mingw32-gcc.exe")

  # Set the C++ compiler on Windows
  set(CMAKE_CXX_COMPILER "G:/Programs/MSYS2/ucrt64/bin/x86_64-w64-mingw32-g++.exe")

  # Set the source and build directories on Windows
  set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

  # Set the generator to MinGW Makefiles on Windows
  set(CMAKE_GENERATOR "MinGW Makefiles")
else()
  # Set the C compiler on Linux
  set(CMAKE_C_COMPILER "/usr/bin/gcc-8")

  # Set the C++ compiler on Linux
  set(CMAKE_CXX_COMPILER "/usr/bin/g++-8")

  # Set the source and build directories on Linux
  set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

  # Set the generator to Unix Makefiles on Linux
  set(CMAKE_GENERATOR "Unix Makefiles")
endif()

cmake_minimum_required(VERSION 3.12)
project(WordConverter VERSION 0.0.9)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_libraries(stdc++fs)

enable_testing()
include(CTest)

add_subdirectory(tests)
add_subdirectory(src)
