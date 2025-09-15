cmake_minimum_required(VERSION 3.15)
project(YTDownloader CXX)

# Find Python with development headers + libaries
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

add_executable(YTDownloader src/main.cpp src/app.rc)

# Tell compiler where Python headers are
target_include_directories(YTDownloader PRIVATE ${Python3_INCLUDE_DIRS})


# Link against Python runtime
target_link_libraries(YTDownloader PRIVATE ${Python3_LIBRARIES})

# Optional: print out what CMake found
message(STATUS "Python include dirs: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python libraries: ${Python3_LIBRARIES}")
message(STATUS "Python version: ${Python3_VERSION}")
message(STATUS "Python executable: ${Python3_EXECUTABLE}")
message(STATUS "Python library: ${Python3_LIBRARY}")