cmake_minimum_required(VERSION 3.8)
project(our-chat CXX)

find_library(CARES_LIB NAMES cares PATHS /lib /usr/lib /usr/local/lib PATH_SUFFIXES x86_64-linux-gnu)

if(NOT CARES_LIB)
    message(FATAL_ERROR "c-ares library not found")
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)            # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Require the standard to be supported
set(CMAKE_CXX_EXTENSIONS OFF)         # Disable compiler-specific extensions

# include(../grpc/examples/cpp/cmake/common.cmake)

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

include_directories(generated_protos)
include_directories(../generated_protos/)
include_directories(../)

# Find absl package
find_package(absl CONFIG REQUIRED)

# Proto file
get_filename_component(rg_proto "protos/image_service.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

# Generated sources
set(rg_proto_srcs "../generated_protos/protos/image_service.pb.cc")
set(rg_proto_hdrs "../generated_protos/protos/image_service.pb.h")
set(rg_grpc_srcs "../generated_protos/protos/image_service.grpc.pb.cc")
set(rg_grpc_hdrs "../generated_protos/protos/image_service.grpc.pb.h")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)
if (NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
    # Do nothing
elseif (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
elseif (HAS_ANY AND HAS_STRING_VIEW)
    set(CMAKE_CXX_STANDARD 17)
else ()
    set(CMAKE_CXX_STANDARD 14)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cc)

# ##############################################################################
# If you include the drogon source code locally in your project, use this method
# to add drogon 
# add_subdirectory(drogon) 
# target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
#
# and comment out the following lines

find_package(Drogon CONFIG REQUIRED)

# target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../image_service)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../image_service/build/librg_grpc_proto.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../image_service/build/libmy_grpc_lib.so
    Drogon::Drogon
    gRPC::grpc++ protobuf::libprotobuf
)

# ##############################################################################

if (CMAKE_CXX_STANDARD LESS 17)
    message(FATAL_ERROR "c++17 or higher is required")
elseif (CMAKE_CXX_STANDARD LESS 20)
    message(STATUS "use c++17")
else ()
    message(STATUS "use c++20")
endif ()

aux_source_directory(controllers CTL_SRC)
aux_source_directory(filters FILTER_SRC)
aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)

drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views
                    ${CMAKE_CURRENT_BINARY_DIR})
# use the following line to create views with namespaces.
# drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views
#                     ${CMAKE_CURRENT_BINARY_DIR} TRUE)
# use the following line to create views with namespace CHANGE_ME prefixed
# and path namespaces.
# drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views
#                     ${CMAKE_CURRENT_BINARY_DIR} TRUE CHANGE_ME)

target_include_directories(${PROJECT_NAME}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                   ${CMAKE_CURRENT_SOURCE_DIR}/models
                                   ../image_service
                                   ../generated_protos)
target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
               ${CTL_SRC}
               ${FILTER_SRC}
               ${PLUGIN_SRC}
               ${MODEL_SRC})
# ##############################################################################
# uncomment the following line for dynamically loading views 
# set_property(TARGET ${PROJECT_NAME} PROPERTY ENABLE_EXPORTS ON)

# ##############################################################################

add_subdirectory(test)
