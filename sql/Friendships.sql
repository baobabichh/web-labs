CREATE TABLE Friendships
(
    Id INT AUTO_INCREMENT PRIMARY KEY,
    UserID1 INT,
    UserID2 INT,
    Status INT, -- 1 - pending, 2 - done
    CreateTS TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (UserID1) REFERENCES Users(ID) ON DELETE CASCADE,
    FOREIGN KEY (UserID2) REFERENCES Users(ID) ON DELETE CASCADE
);

CREATE INDEX Friendship_idx_UserID1 on Friendships (UserID1);
CREATE INDEX Friendship_idx_UserID2 on Friendships (UserID2);