cmake_minimum_required(VERSION 3.26)
project(Password_Hash_Algorithm)

set(CMAKE_CXX_STANDARD 23)

add_executable(Password_Hash_Algorithm main.cpp)

include_directories(/opt/homebrew/Cellar/openssl@3/3.2.0/include/)

target_link_libraries(Password_Hash_Algorithm /opt/homebrew/Cellar/openssl@3/3.2.0/lib/libcrypto.3.dylib)




