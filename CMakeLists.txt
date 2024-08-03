cmake_minimum_required(VERSION 3.10)

project(useragent CXX)

option(BUILD_TESTS "Create test target for useragent" ON)

set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

if(MSVC)
	#add_compile_options("/:bigobj  /:utf-8")
endif()

file(GLOB HEADER_FILES "src/*.h" "src/*.hpp")
file(GLOB SOURCE_FILES "src/*.cpp")

include_directories("src")

#add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_library(useragent ${SOURCE_FILES})

#target_include_directories(useragent
#  PUBLIC
#    $<INSTALL_INTERFACE:include>    
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#  PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}/src
#)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(useragent PUBLIC "useragent")
endif()

install(FILES ${HEADER_FILES} DESTINATION include)
install(TARGETS useragent RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

#message(STATUS ${BUILD_TESTS})

if(BUILD_TESTS)
  include_directories("src")
  file(GLOB TEST_SOURCE "test/*.cpp")
  add_executable(test_useragent_parse ${TEST_SOURCE})
  target_link_libraries(test_useragent_parse useragent)

  #add_executable(test_xpath "test/test_xpath.cpp")
  #add_executable(test_xpath_html "test/test_xpath_html.cpp")
  #add_executable(test_parserDom "test/test_parserDom.cpp")
  #target_link_libraries(test_xpath useragent)
  #target_link_libraries(test_xpath_html useragent)
  #target_link_libraries(test_parserDom useragent)
endif()
