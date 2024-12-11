#include "grpc_functions.h"

#include <iostream>

int main(int argc, char** argv) {
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <server_address> <user_id> <photo_path>" << std::endl;
        return 1;
    }

    std::string server_address = argv[1];
    std::string user_id = argv[2];
    std::string photo_path = argv[3];

    // Send the photo
    if (!SendPhotoToServer(server_address, user_id, photo_path))
    {
        return 1;
    }

    return 0;
}