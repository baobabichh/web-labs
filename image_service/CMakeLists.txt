cmake_minimum_required(VERSION 3.8)

project(RouteGuide C CXX)

set(Protobuf_DIR "/usr/local/lib/cmake/protobuf")

find_package(Protobuf CONFIG REQUIRED)


find_package(Protobuf CONFIG REQUIRED)

include_directories(generated_protos)

# Find absl package
find_package(absl CONFIG REQUIRED)

# Proto file
get_filename_component(rg_proto "protos/image_serviice.proto" ABSOLUTE)
get_filename_component(rg_proto_path "${rg_proto}" PATH)

# Generated sources
set(rg_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/generated/protos/image_serviice.pb.cc")
set(rg_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/protos/image_serviice.pb.h")
set(rg_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/generated/protos/image_serviice.grpc.pb.cc")
set(rg_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/protos/image_serviice.grpc.pb.h")
add_custom_command(
      OUTPUT "${rg_proto_srcs}" "${rg_proto_hdrs}" "${rg_grpc_srcs}" "${rg_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${rg_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${rg_proto}"
      DEPENDS "${rg_proto}")

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

# add_executable(image_serviice "image_serviice.cc")
# target_link_libraries(image_serviice rg_grpc_proto absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})

add_executable(server "server.cc")
target_link_libraries(server rg_grpc_proto absl::flags_parse absl::absl_log absl::log_initialize absl::log_globals ${_REFLECTION} ${_GRPC_GRPCPP} ${_PROTOBUF_LIBPROTOBUF})