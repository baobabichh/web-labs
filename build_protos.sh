./grpc/cmake/build/third_party/protobuf/protoc --cpp_out=generated_protos protos/image_serviice.proto 
./grpc/cmake/build/third_party/protobuf/protoc --cpp_out=generated_protos --grpc_out=generated_protos --plugin=protoc-gen-grpc=$(which grpc_cpp_plugin) protos/image_serviice.proto
