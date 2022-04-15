cmake_minimum_required(VERSION 2.8.12...3.22.0)

project(termtick)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)

# Libraries

add_subdirectory(external/TermOx)
add_subdirectory(external/served)
add_subdirectory(external/restclient-cpp)

target_include_directories(${PROJECT_NAME}
	PUBLIC external/TermOx/include
	PUBLIC external/served/src
	PUBLIC external/restclient-cpp/include
)

target_link_directories(${PROJECT_NAME}
	PUBLIC external/TermOx/src
	PUBLIC external/served/src
	PUBLIC external/restclient-cpp/src
)

target_link_libraries(${PROJECT_NAME}
	TermOx
	served
	restclient-cpp
)
