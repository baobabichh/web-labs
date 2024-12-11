#include <grpcpp/grpcpp.h>
#include "generated_protos/image_service.grpc.pb.h"
#include <fstream>
#include <iostream>
#include <string>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using image_service::ImageService;
using image_service::ImageRequest;
using image_service::ImageResponse;

class ImageServiceImpl final : public ImageService::Service
{
public:
    Status GetImage(ServerContext* context, const ImageRequest* request, ImageResponse* response) override {
        const std::string& user_id = request->user_id();
        
        std::ifstream image_file(user_id, std::ios::in | std::ios::binary);
        if (!image_file)
        {
            std::cerr << "Error: Unable to open file " << user_id << std::endl;
            return Status(grpc::StatusCode::NOT_FOUND, "File not found");
        }

        std::string image_data((std::istreambuf_iterator<char>(image_file)), std::istreambuf_iterator<char>());

        response->set_image_data(image_data);

        std::cout << "Served image: " << path_id << std::endl;
        return Status::OK;
    }
};

// Start the server.
void RunServer()
{
    const std::string server_address("0.0.0.0:50051");

    ImageServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv)
{
    RunServer();
    return 0;
}