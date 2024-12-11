#include <string>
#include <vector>

bool SendPhotoToServer(const std::string& server_address, const std::string& user_id, const std::string& photo_path);
bool SendPhotoDataToServer(const std::string& server_address, const std::string& user_id, const std::vector<char>& photo_data);