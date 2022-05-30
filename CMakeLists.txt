cmake_minimum_required(VERSION 3.10)

project(toy)


set(TOY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
include_directories(${TOY_INCLUDE})
add_library(toy STATIC
  src/toyBaseListener.cpp 
  src/toyListener.cpp
  src/toyLexer.cpp
  src/toyParser.cpp 

)


add_executable(toyc
  src/main.cpp 
)

target_link_libraries( toyc 
  PRIVATE
    toy 
    /usr/local/lib/libantlr4-runtime.so
)

