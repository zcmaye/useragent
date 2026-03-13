cmake_minimum_required(VERSION 3.10)

project(UserAgent CXX)

set(EXPORT_NAME UserAgent)

set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

include(GNUInstallDirs)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)

if(NOT DEFINED USERAGENT_PARENTPATH)
    set(USERAGENT_PARENTPATH ${CMAKE_CURRENT_SOURCE_DIR}/../)
endif()

if(NOT DEFINED USERAGENT_HEADERPATH)
    set(USERAGENT_HEADERPATH ${CMAKE_CURRENT_SOURCE_DIR}/../UserAgent/src/)
endif()

if(NOT DEFINED USERAGENT_SOURCEPATH)
    set(USERAGENT_SOURCEPATH ${CMAKE_CURRENT_SOURCE_DIR}/../UserAgent/src/)
endif()

option(BUILD_TESTS "Create test target for UserAgent" ON)
# Due historical reasons this value is kept off
option(BUILD_SHARED_LIBS "Build in shared lib mode" OFF)

if(MSVC)
	#add_compile_options("/:bigobj  /:utf-8")
endif()

file(GLOB HEADER_FILES "src/*.h" "src/*.hpp")
file(GLOB SOURCE_FILES "src/*.cpp")

#include_directories("src")
add_library(UserAgent ${SOURCE_FILES})

add_library(UserAgent::UserAgent ALIAS UserAgent)


if (BUILD_SHARED_LIBS)
    target_compile_definitions(UserAgent PUBLIC SqlBuilder_SHAREDLIB)
endif()

target_include_directories(UserAgent
  PRIVATE
    ${USERAGENT_HEADERPATH}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>    
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(UserAgent PUBLIC "UserAgent_STATICLIB")
endif()

set_target_properties(UserAgent PROPERTIES
    OUTPUT_NAME ${EXPORT_NAME}
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "${HEADER_FILES}"
)

install(TARGETS UserAgent
    EXPORT ${EXPORT_NAME}Targets DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT runtime
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT devel
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/UserAgent COMPONENT devel
)

install(EXPORT ${EXPORT_NAME}Targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}/
    FILE ${EXPORT_NAME}Targets.cmake
    NAMESPACE UserAgent::
    COMPONENT devel
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/UserAgent-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${EXPORT_NAME}Config.cmake
    @ONLY
)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/UserAgent-config-version.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${EXPORT_NAME}ConfigVersion.cmake
    @ONLY
)
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${EXPORT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${EXPORT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}/
)
include(CPackConfig)


if(BUILD_TESTS)
  include_directories("src")
  file(GLOB TEST_SOURCE "tests/*.cpp")
  add_executable(test_useragent_parse ${TEST_SOURCE})
  target_link_libraries(test_useragent_parse UserAgent)
endif()
