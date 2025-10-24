use MyCMS;

-- select * from User;

-- Updates Email
-- UPDATE User 
-- SET Email = 'newemail2025@example.com' 
-- WHERE UserID = 1;

-- select * from User;

-- Duplicate Key
-- INSERT INTO User (`UserID`, `Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`)
-- VALUES (1, 'johndoe', 'hashedpassword', 'NORMAL', 'newemail@example.com', 'John', 'Doe', '2025-02-21 16:45:00')
-- ON DUPLICATE KEY UPDATE 
-- `Username` = concat(`Username`, '_' , `LastActivity`);

-- select * from User;

-- Adds TimeStamp
-- ALTER TABLE User 
-- ADD COLUMN LastActivity TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP;

select * from User;