#include <grpcpp/grpcpp.h>
#include "protos/image_service.grpc.pb.h"
#include <fstream>
#include <iostream>

class ImageServiceClient
{
public:
    ImageServiceClient(std::shared_ptr<grpc::Channel> channel)
        : _stub(image_service::ImageService::NewStub(channel)) {}

    bool SendPhoto(const std::string& user_id, const std::string& photo_path)
    {
        // Read the photo from the file
        std::ifstream file(photo_path, std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open the photo file: " << photo_path << std::endl;
            return false;
        }

        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        std::cout << "buffer.size() : " << buffer.size() << "\n";

        return SendPhotoData(user_id, buffer);
    }

    bool SendPhotoData(const std::string& user_id, const std::vector<char>& buffer)
    {
        image_service::SetImageRequest request;
        request.set_user_id(user_id);
        request.set_image_data(std::string(buffer.begin(), buffer.end()));

        image_service::SetImageResponse response;
        grpc::ClientContext context;

        grpc::Status status = _stub->SetImage(&context, request, &response);

        if (status.ok())
        {
            std::cout << "Photo sent successfully for user_id: " << user_id << std::endl;
            return true;
        }
        else
        {
            std::cerr << "Failed to send photo: " << status.error_message() << std::endl;
            return false;
        }
    }

    bool GetPhotoData(const std::string& user_id, std::vector<char>& buffer)
    {
        image_service::SetImageRequest request;
        request.set_user_id(user_id);
        request.set_image_data(std::string(buffer.begin(), buffer.end()));

        image_service::SetImageResponse response;
        grpc::ClientContext context;

        grpc::Status status = _stub->SetImage(&context, request, &response);

        if (status.ok())
        {
            std::cout << "Photo sent successfully for user_id: " << user_id << std::endl;
            return true;
        }
        else
        {
            std::cerr << "Failed to send photo: " << status.error_message() << std::endl;
            return false;
        }
    }

private:
    std::unique_ptr<image_service::ImageService::Stub> _stub;
};

// Function to send a photo
bool SendPhotoToServer(const std::string& server_address, const std::string& user_id, const std::string& photo_path)
{
    ImageServiceClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    return client.SendPhoto(user_id, photo_path);
}

bool SendPhotoDataToServer(const std::string& server_address, const std::string& user_id, const std::vector<char>& photo_data)
{
    ImageServiceClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    return client.SendPhotoData(user_id, photo_data);
}

bool GetPhotoDataOfUser(const std::string& server_address, const std::string& user_id, std::vector<char>& photo_data)
{

}
