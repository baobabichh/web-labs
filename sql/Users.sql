CREATE TABLE Users
(
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(100),
    Email VARCHAR(100) NOT NULL UNIQUE,
    Password VARCHAR(255) NOT NULL
);

CREATE INDEX Users_idx_email ON Users (Email);
CREATE INDEX Users_idx_email_password ON Users (Email, Password);