#include <grpcpp/grpcpp.h>
#include "protos/image_service.grpc.pb.h"
#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

const std::string IMAGE_DIRECTORY = "../images/";

class ImageServiceImpl final : public image_service::ImageService::Service
{
public:
    ImageServiceImpl()
    {
        if (!fs::exists(IMAGE_DIRECTORY))
        {
            fs::create_directories(IMAGE_DIRECTORY);
        }
    }

    grpc::Status SetImage(grpc::ServerContext* context, const image_service::SetImageRequest* request, image_service::SetImageResponse* response) override
    {
        try
        {
            std::string file_path = IMAGE_DIRECTORY + request->user_id() + ".png";
            
            std::ofstream file(file_path, std::ios::binary);
            if (!file.is_open())
            {
                return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to open file for writing.");
            }
            file.write(request->image_data().data(), request->image_data().size());
            file.close();

            return grpc::Status::OK;
        }
        catch (const std::exception& e)
        {
            return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
        }
    }

    grpc::Status GetImage(grpc::ServerContext* context, const image_service::ImageRequest* request, image_service::ImageResponse* response) override
    {
        try
        {
            std::string file_path = IMAGE_DIRECTORY + request->user_id() + ".png";

            if (!fs::exists(file_path))
            {
                return grpc::Status(grpc::StatusCode::NOT_FOUND, "Image not found.");
            }

            std::ifstream file(file_path, std::ios::binary);
            if (!file.is_open())
            {
                return grpc::Status(grpc::StatusCode::INTERNAL, "Failed to open file for reading.");
            }

            std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            response->set_image_data(std::string(buffer.begin(), buffer.end()));

            return grpc::Status::OK;
        }
        catch (const std::exception& e)
        {
            return grpc::Status(grpc::StatusCode::INTERNAL, e.what());
        }
    }
};

void RunServer()
{
    std::string server_address("0.0.0.0:50051");
    ImageServiceImpl service;

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv)
{
    RunServer();
    return 0;
}