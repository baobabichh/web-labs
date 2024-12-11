cmake_minimum_required(VERSION 3.8)

project(RouteGuide C CXX)

include(../grpc/examples/cpp/cmake/common.cmake)

include_directories(generated)

# Find absl package
find_package(absl CONFIG REQUIRED)


# Proto file
get_filename_component(rg_proto "../protos/person.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

# Generated sources
set(rg_proto_srcs "../${CMAKE_CURRENT_BINARY_DIR}/generated/protos/person.pb.cc")
set(rg_proto_hdrs "../${CMAKE_CURRENT_BINARY_DIR}/generated/protos/person.pb.h")
set(rg_grpc_srcs "../${CMAKE_CURRENT_BINARY_DIR}/generated/protos/person.grpc.pb.cc")
set(rg_grpc_hdrs "../${CMAKE_CURRENT_BINARY_DIR}/generated/protos/person.grpc.pb.h")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# rg_grpc_proto
add_library(rg_grpc_proto
  ${rg_grpc_srcs}
  ${rg_grpc_hdrs}
  ${rg_proto_srcs}
  ${rg_proto_hdrs})
target_link_libraries(rg_grpc_proto
  absl::absl_log
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

target_link_libraries(
  rg_grpc_proto
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF})

# add_executable(client "client.cc")
# target_link_libraries(client rg_grpc_proto absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_executable(image_service "image_service.cc")
target_link_libraries(image_service rg_grpc_proto absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})