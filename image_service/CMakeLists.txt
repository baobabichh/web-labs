cmake_minimum_required(VERSION 3.8)

project(RouteGuide C CXX)

set(CMAKE_CXX_STANDARD 17)            # Use C++17 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)   # Require the standard to be supported
set(CMAKE_CXX_EXTENSIONS OFF)         # Disable compiler-specific extensions

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

include_directories(generated_protos)
include_directories(../generated_protos/)
include_directories(../)

# Proto file
get_filename_component(rg_proto "protos/image_service.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

# Generated sources
set(rg_proto_srcs "../generated_protos/protos/image_service.pb.cc")
set(rg_proto_hdrs "../generated_protos/protos/image_service.pb.h")
set(rg_grpc_srcs "../generated_protos/protos/image_service.grpc.pb.cc")
set(rg_grpc_hdrs "../generated_protos/protos/image_service.grpc.pb.h")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# rg_grpc_proto Shared Library
add_library(rg_grpc_proto SHARED
  ${rg_grpc_srcs}
  ${rg_grpc_hdrs}
  ${rg_proto_srcs}
  ${rg_proto_hdrs})

target_link_libraries(
  rg_grpc_proto
  gRPC::grpc++)

# my_grpc_lib Shared Library
add_library(my_grpc_lib SHARED
  ${rg_grpc_srcs}
  ${rg_grpc_hdrs}
  ${rg_proto_srcs}
  ${rg_proto_hdrs}
  grpc_functions.cc)

target_link_libraries(
  my_grpc_lib
  gRPC::grpc++)

# Executable for image_client
add_executable(image_client "image_client.cc")
target_link_libraries(image_client rg_grpc_proto my_grpc_lib gRPC::grpc++)

# Executable for image_service
add_executable(image_service "image_service.cc")
target_link_libraries(image_service rg_grpc_proto my_grpc_lib gRPC::grpc++)
