use MyCMS;
-- Primary key 
INSERT INTO User (UserID, Username, `Password`, `Role`, Email, FirstName, LastName, LastLogin)  
VALUES 
(1,'johndoe', 'hashed_password_here', 'NORMAL', 'johndoe@example.com', 'John', 'Doe', '2025-02-24 14:30:00');

-- foreign key 
INSERT INTO Contact (UserID, FirstName, LastName, DateOfBirth, Gender, Street, City, State, Zip, Country, CompanyID)  
VALUES 
(12, 'James', 'Anderson', '1985-09-22', 'M', '456 Maple Ave', 'Chicago', 'IL', '60601', 'USA', 3);

-- unique key 
INSERT INTO User (Username, `Password`, `Role`, Email, FirstName, LastName, LastLogin)  
VALUES 
('admin', 'hashed_password_here', 'NORMAL', 'johndoe@example.com', 'John', 'Doe', '2025-02-24 14:30:00');

-- data types 
INSERT INTO Contact (UserID, FirstName, LastName, DateOfBirth, Gender, Street, City, State, Zip, Country, CompanyID)  
VALUES 
(1, 'Emma', 'Williams', 'bagel', 'F', '789 Oak Street', 'Los Angeles', 'CA', '90001', 'USA', 2);
