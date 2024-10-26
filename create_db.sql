create database our_chat;
use our_chat;

-- Switch to the MySQL database
USE mysql;

-- Create the user with a specified password
CREATE USER 'our_chat_user'@'%' IDENTIFIED BY '12qwaszx';

-- Grant all privileges on the specific database to the user
GRANT ALL PRIVILEGES ON our_chat.* TO 'our_chat_user'@'%';

-- Apply changes
FLUSH PRIVILEGES;