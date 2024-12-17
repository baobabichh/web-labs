cmake_minimum_required(VERSION 3.8)

project(RouteGuide C CXX)

include(../grpc/examples/cpp/cmake/common.cmake)

find_package(Protobuf CONFIG REQUIRED)

include_directories(generated_protos)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../generated_protos/)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../)

# Find absl package
find_package(absl CONFIG REQUIRED)

# Proto file
get_filename_component(rg_proto "protos/image_service.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

# Generated sources
set(rg_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/../generated_protos/protos/image_service.pb.cc")
set(rg_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../generated_protos/protos/image_service.pb.h")
set(rg_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/../generated_protos/protos/image_service.grpc.pb.cc")
set(rg_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/../generated_protos/protos/image_service.grpc.pb.h")

include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# rg_grpc_proto
add_library(rg_grpc_proto
  ${rg_grpc_srcs}
  ${rg_grpc_hdrs}
  ${rg_proto_srcs}
  ${rg_proto_hdrs})

target_link_libraries(
  rg_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})


add_library(my_grpc_lib
  ${rg_grpc_srcs}
  ${rg_grpc_hdrs}
  ${rg_proto_srcs}
  ${rg_proto_hdrs}
  grpc_functions.cc)

target_link_libraries(
  my_grpc_lib
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

add_executable(image_client "image_client.cc")
target_link_libraries(image_client rg_grpc_proto my_grpc_lib absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_executable(image_service "image_service.cc")
target_link_libraries(image_service rg_grpc_proto my_grpc_lib absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})