cmake_minimum_required(VERSION 3.22.1)

# Set the C++ standard we will use

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_C_COMPILER /usr/bin/gcc-13)
set(CMAKE_CXX_COMPILER /usr/bin/g++-13) 

# Add the path of the cmake files to the CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(BitcoinExchanges)

include_directories(
        ${PROJECT_SOURCE_DIR}/inc/ 
)
file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        ) 
# Add project executable

add_executable(BitcoinExchanges ${all_SRCS})



include(FetchContent)


FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(curl URL https://curl.se/download/curl-8.5.0.tar.gz)
FetchContent_MakeAvailable(curl)

target_link_libraries(BitcoinExchanges  nlohmann_json::nlohmann_json)
target_link_libraries(BitcoinExchanges  CURL::libcurl)
 

