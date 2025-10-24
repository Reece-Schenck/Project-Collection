SET @start_time = SYSDATE(6);

SET FOREIGN_KEY_CHECKS = 0;  -- Disable foreign key checks

INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('admin', 'ef92b778bafe771e89245b89ecbc70ec1e5e14bba5b7b43eaf5f6a2e5d0b62d1', 'ADMIN', 'admin@mycms.com', 'Admin', 'User', '2025-02-22 09:00:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('jsmith', 'a3f5b1d6e7c8f9b0a1b2c3d4e5f60718293a4b5c6d7e8f90123456789abcdef0', 'NORMAL', 'jsmith@mycms.com', 'John', 'Smith', '2025-02-21 16:45:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES    
    ('amiller', 'b1c2d3e4f5061728394a5b6c7d8e9f00112233445566778899aabbccddeeff00', 'NORMAL', 'amiller@mycms.com', 'Alice', 'Miller', '2025-02-20 11:30:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES    
    ('bjohnson', '0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef', 'NORMAL', 'bjohnson@mycms.com', 'Bob', 'Johnson', '2025-02-19 14:20:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES    
    ('cwalker', 'fedcba9876543210fedcba9876543210fedcba9876543210fedcba9876543210', 'NORMAL', 'cwalker@mycms.com', 'Carol', 'Walker', '2025-02-18 08:15:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('dlee', 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa', 'NORMAL', 'dlee@mycms.com', 'David', 'Lee', '2025-02-17 12:00:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('eroberts', 'bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb', 'NORMAL', 'eroberts@mycms.com', 'Emma', 'Roberts', '2025-02-16 17:30:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('fclark', 'cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc', 'NORMAL', 'fclark@mycms.com', 'Frank', 'Clark', '2025-02-15 09:45:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('gmartin', 'dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd', 'NORMAL', 'gmartin@mycms.com', 'Grace', 'Martin', '2025-02-14 11:15:00');
    
INSERT INTO `MyCMS`.`User` 
    (`Username`, `Password`, `Role`, `Email`, `FirstName`, `LastName`, `LastLogin`) 
VALUES
    ('hscott', 'eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee', 'NORMAL', 'hscott@mycms.com', 'Henry', 'Scott', '2025-02-13 10:30:00');


INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('Tech Innovators Inc', 'Technology', '123 Tech Ave', 'San Francisco', 'CA', '94107', 'USA', '415-555-0100', 'info@techinnovators.com', 'www.techinnovators.com');
    
INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('HealthPlus Corp', 'Healthcare', '456 Wellness Blvd', 'Los Angeles', 'CA', '90017', 'USA', '323-555-0200', 'contact@healthplus.com', 'www.healthplus.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('Green Energy Solutions', 'Energy', '789 Green Way', 'Austin', 'TX', '73301', 'USA', '512-555-0300', 'support@greenenergy.com', 'www.greenenergy.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('EduLearn Inc', 'Education', '101 Learning St', 'Boston', 'MA', '02108', 'USA', '617-555-0400', 'hello@edulearn.com', 'www.edulearn.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('FinSecure LLC', 'Finance', '202 Money Rd', 'New York', 'NY', '10005', 'USA', '212-555-0500', 'services@finsecure.com', 'www.finsecure.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('AutoDrive Motors', 'Automotive', '303 Car Ln', 'Detroit', 'MI', '48226', 'USA', '313-555-0600', 'sales@autodrive.com', 'www.autodrive.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('Fashion Forward', 'Retail', '404 Style Blvd', 'New York', 'NY', '10001', 'USA', '212-555-0700', 'info@fashionforward.com', 'www.fashionforward.com');
    
INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('Foodies Delight', 'Food & Beverage', '505 Gourmet Ave', 'Chicago', 'IL', '60616', 'USA', '312-555-0800', 'order@foodiesdelight.com', 'www.foodiesdelight.com');
    
INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('BuildRight Construction', 'Construction', '606 Builder St', 'Seattle', 'WA', '98101', 'USA', '206-555-0900', 'contact@buildright.com', 'www.buildright.com');
    
    INSERT INTO `MyCMS`.`Company`
    (`CompanyName`, `Industry`, `Street`, `City`, `State`, `Zip`, `Country`, `Phone`, `Email`, `Website`)
VALUES
    ('TravelQuest', 'Travel', '707 Adventure Rd', 'Orlando', 'FL', '32801', 'USA', '407-555-1000', 'support@travelquest.com', 'www.travelquest.com');


INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (1, 'Alice', 'Doe', '1980-02-01', 'F', '111 Main St', 'New York', 'NY', '10001', 'USA',  1);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (2, 'Bob', 'Smith', '1975-07-10', 'M', '222 Oak St', 'Los Angeles', 'CA', '90001', 'USA',  2);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (3, 'Charlie', 'Brown', '1990-03-15', 'M', '333 Pine St', 'Chicago', 'IL', '60601', 'USA',  3);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (4, 'Diana', 'Prince', '1988-04-20', 'F', '444 Cedar St', 'Boston', 'MA', '02108', 'USA',  4);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (5, 'Edward', 'Norton', '1982-12-05', 'M', '555 Maple Ave', 'Detroit', 'MI', '48226', 'USA',  5);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (6, 'Fiona', 'Apple', '1995-09-09', 'F', '666 Birch Rd', 'Austin', 'TX', '73301', 'USA',  6);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (7, 'George', 'Clooney', '1961-05-06', 'M', '777 Walnut St', 'San Francisco', 'CA', '94107', 'USA',  7);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (8, 'Helen', 'Mirren', '1945-07-26', 'F', '888 Spruce St', 'Seattle', 'WA', '98101', 'USA',  8);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (9, 'Ian', 'McKellen', '1939-05-25', 'M', '999 Elm St', 'Chicago', 'IL', '60616', 'USA',  9);
    
INSERT INTO `MyCMS`.`Contact`
    (`UserID`, `FirstName`, `LastName`, `DateOfBirth`, `Gender`, `Street`, `City`, `State`, `Zip`, `Country`, `CompanyID`)
VALUES
    (10, 'Jane', 'Doe', '1985-11-30', 'Other', '1010 Ash Ave', 'Orlando', 'FL', '32801', 'USA', 10);

INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (1, 'Ally');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (1, 'Ali');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (2, 'Bobby');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (3, 'Chuck');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (4, 'Di');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (4, 'D');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (5, 'Eddie');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (5, 'Ed');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (6, 'Fi');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (7, 'Geo');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (8, 'Leni');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (9, 'Mack');
    
INSERT INTO `MyCMS`.`ContactNickname`
    (`ContactID`, `Nickname`)
VALUES
    (10, 'Janie');

INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (1, '603-751-2124', 'Cell', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (1, '603-750-0027', 'Home', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (2, '651-751-2125', 'Home', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (3, '521-751-2126', 'Work', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (4, '501-751-2127', 'Fax', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (5, '401-751-2128', 'Cell', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (6, '307-751-2129', 'Home', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (7, '701-751-2130', 'Work', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (8, '201-751-2131', 'Fax', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (9, '410-751-2132', 'Cell', '+1');
    
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (10, '710-751-2133', 'Home', '+1');

INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (1, 'contact1@example.com', 'Personal', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (2, 'contact2@example.com', 'Work', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (3, 'contact3@example.com', 'Other', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (4, 'contact4@example.com', 'Personal', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (5, 'contact5@example.com', 'Work', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (6, 'contact6@example.com', 'Other', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (7, 'contact7@example.com', 'Personal', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (8, 'contact8@example.com', 'Work', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (9, 'contact9@example.com', 'Other', 1);
    
INSERT INTO `MyCMS`.`Email`
    (`ContactID`, `EmailAddress`, `EmailType`, `IsPrimary`)
VALUES
    (10, 'contact10@example.com', 'Personal', 1);

INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact1_pic1.jpg', '2025-02-21 10:00:00', 'Profile picture', 1);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact2_pic1.jpg', '2025-02-20 09:30:00', 'Office event', 2);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact3_pic1.jpg', '2025-02-19 12:00:00', 'Profile picture', 3);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact4_pic1.jpg', '2025-02-18 14:00:00', 'Profile picture', 4);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact5_pic1.jpg', '2025-02-17 10:30:00', 'Profile picture', 5);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact6_pic1.jpg', '2025-02-16 16:00:00', 'Profile picture', 6);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact7_pic1.jpg', '2025-02-15 09:15:00', 'Profile picture', 7);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact8_pic1.jpg', '2025-02-14 11:30:00', 'Profile picture', 8);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact9_pic1.jpg', '2025-02-13 08:45:00', 'Profile picture', 9);
    
INSERT INTO `MyCMS`.`Picture`
    (`ImagePath`, `UploadedDate`, `Description`, `Contact_ContactID`)
VALUES
    ('images/contact10_pic1.jpg', '2025-02-12 13:30:00', 'Profile picture', 10);

INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Login', 'User logged in', '2025-02-22 08:00:00', '2025-02-22 08:00:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Logout', 'User logged out', '2025-02-22 08:05:00', '2025-02-22 08:05:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Create', 'Created a record', '2025-02-22 09:00:00', '2025-02-22 09:00:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Update', 'Updated a record', '2025-02-22 10:00:00', '2025-02-22 10:00:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Delete', 'Deleted a record', '2025-02-22 11:00:00', '2025-02-22 11:00:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('View', 'Viewed a record', '2025-02-22 12:00:00', '2025-02-22 12:00:00');
    
INSERT INTO `MyCMS`.`ActivityType`
    (`TypeName`, `Description`, `CreatedAt`, `UpdatedAt`)
VALUES
    ('Upload', 'Uploaded a file', '2025-02-22 14:00:00', '2025-02-22 14:00:00');

INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (1, 1, '2025-02-22 08:10:00', 'User logged in');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (1, 3, '2025-02-22 08:15:00', 'Created a new contact');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (2, 1, '2025-02-22 09:00:00', 'User logged in')
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (2, 6, '2025-02-22 09:10:00', 'Viewed a company profile');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (3, 2, '2025-02-22 10:30:00', 'User logged out');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (4, 4, '2025-02-22 11:00:00', 'Updated user settings');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (5, 5, '2025-02-12 12:00:00', 'Deleted a contact record');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (7, 7, '2025-02-22 13:45:00', 'Uploaded a document');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (8, 7, '2025-02-25 13:45:00', 'Uploaded a document');
    
INSERT INTO `MyCMS`.`ActivityLog`
    (`UserID`, `ActivityTypeID`, `Timestamp`, `Description`)
VALUES
    (10, 1, '2025-02-22 16:30:00', 'User logged in');

INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (1, 'Follow-up Meeting', 'Schedule a follow-up meeting with Alice.', '2025-02-20 08:00:00', '2025-02-21 09:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (1, 'Urgent Request', 'Alice requested additional documentation.', '2025-02-21 10:15:00', '2025-02-21 11:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (2, 'Project Update', 'Bob needs an update on project status.', '2025-02-19 12:30:00', '2025-02-19 13:45:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (3, 'Client Inquiry', 'Charlie asked about new service offerings.', '2025-02-18 09:45:00', '2025-02-18 10:20:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (4, 'Invoice Issue', 'Diana reported an issue with an invoice.', '2025-02-17 11:10:00', '2025-02-17 12:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (5, 'Training Session', 'Edward signed up for the training program.', '2025-02-16 14:00:00', '2025-02-16 14:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (6, 'Follow-up Email', 'Fiona needs a follow-up email.', '2025-02-15 08:15:00', '2025-02-15 08:45:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (7, 'Meeting Notes', 'George attended a company meeting.', '2025-02-14 10:30:00', '2025-02-14 11:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (8, 'Documentation Request', 'Helen requested access to documents.', '2025-02-13 09:20:00', '2025-02-13 10:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (9, 'Feedback Received', 'Ian provided feedback on the new policy.', '2025-02-12 16:45:00', '2025-02-12 17:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (10, 'Contract Review', 'Jane is reviewing the new contract terms.', '2025-02-11 15:30:00', '2025-02-11 16:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactNote`
    (`ContactID`, `NoteTitle`, `NoteText`, `CreatedDate`, `LastModified`, `Status`)
VALUES
    (10, 'Updated Contact Info', 'Jane updated her phone number.', '2025-02-10 14:20:00', '2025-02-10 15:00:00', 'ACTIVE');

INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Business Partners', 'Contacts related to business partnerships.', '2025-02-01 08:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Clients', 'Clients of the company.', '2025-02-02 09:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('VIP Clients', 'High-value clients with special privileges.', '2025-02-03 10:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Suppliers', 'Suppliers and vendors for the company.', '2025-02-04 11:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Employees', 'Internal employees and staff.', '2025-02-05 12:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Investors', 'People who have invested in the company.', '2025-02-06 13:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Consultants', 'External consultants and advisors.', '2025-02-07 14:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Marketing Team', 'Marketing team members.', '2025-02-08 15:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Developers', 'Software development team.', '2025-02-09 16:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`GroupTable`
    (`GroupName`, `Description`, `CreatedDate`, `Status`)
VALUES
    ('Board Members', 'Board of directors and executives.', '2025-02-10 17:00:00', 'ACTIVE');

INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (1, 1, '2025-02-11 08:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (1, 3, '2025-02-12 08:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (2, 2, '2025-02-13 09:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (3, 5, '2025-02-14 09:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (4, 4, '2025-02-15 10:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (5, 6, '2025-02-16 10:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (6, 7, '2025-02-17 11:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (7, 8, '2025-02-18 11:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (8, 9, '2025-02-19 12:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (9, 10, '2025-02-20 12:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (10, 2, '2025-02-21 13:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (10, 6, '2025-02-22 13:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (2, 4, '2025-02-23 14:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (3, 6, '2025-02-24 14:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactGroupMapping`
    (`ContactID`, `GroupID`, `DateAdded`, `MappingStatus`)
VALUES
    (5, 8, '2025-02-25 15:00:00', 'ACTIVE');

INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('VIP', 'High-value contact.', '2025-02-01 08:00:00', 'Gold');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Lead', 'Potential customer or client.', '2025-02-02 09:00:00', 'Blue');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Supplier', 'Supplier contact.', '2025-02-03 10:00:00', 'Green');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Investor', 'Investors in the company.', '2025-02-04 11:00:00', 'Silver');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Employee', 'Internal employee.', '2025-02-05 12:00:00', 'Red');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Consultant', 'External consultant or advisor.', '2025-02-06 13:00:00', 'Orange');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Marketing', 'Marketing-related contact.', '2025-02-07 14:00:00', 'Purple');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Developer', 'Software developer contact.', '2025-02-08 15:00:00', 'Teal');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Board Member', 'Part of the board of directors.', '2025-02-09 16:00:00', 'Brown');
    
INSERT INTO `MyCMS`.`Tag`
    (`TagName`, `Description`, `CreatedDate`, `TagColor`)
VALUES
    ('Customer', 'Current paying customer.', '2025-02-10 17:00:00', 'Yellow');

INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (1, 1, '2025-02-11 08:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (1, 2, '2025-02-12 08:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (2, 3, '2025-02-13 09:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (3, 5, '2025-02-14 09:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (4, 4, '2025-02-15 10:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (5, 6, '2025-02-16 10:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (6, 7, '2025-02-17 11:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (7, 8, '2025-02-18 11:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (8, 9, '2025-02-19 12:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (9, 10, '2025-02-20 12:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (10, 2, '2025-02-21 13:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (10, 4, '2025-02-22 13:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (2, 5, '2025-02-23 14:00:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (3, 6, '2025-02-24 14:30:00', 'ACTIVE');
    
INSERT INTO `MyCMS`.`ContactTagMapping`
    (`ContactID`, `TagID`, `CreatedTime`, `Status`)
VALUES
    (5, 7, '2025-02-25 15:00:00', 'ACTIVE');

INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (1, 'Project Kickoff', 'Initial meeting to discuss project details.', 'Conference Room A', '2025-03-01 10:00:00', '2025-02-20 08:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (2, 'Marketing Strategy', 'Discussing marketing plans for Q2.', 'Online - Zoom', '2025-03-02 14:00:00', '2025-02-21 09:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (3, 'Investor Update', 'Quarterly investor update meeting.', 'Boardroom', '2025-03-03 16:00:00', '2025-02-22 10:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (4, 'Tech Team Sync', 'Weekly development team stand-up.', 'Engineering Lab', '2025-03-04 09:30:00', '2025-02-23 11:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (5, 'Customer Feedback', 'Meeting with customers to collect feedback.', 'Client Office', '2025-03-05 13:00:00', '2025-02-24 12:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (6, 'Partnership Discussion', 'Discussing potential business partnerships.', 'Main Office', '2025-03-06 11:00:00', '2025-02-25 13:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (7, 'Annual General Meeting', 'Company-wide annual update.', 'Main Auditorium', '2025-03-07 10:00:00', '2025-02-26 14:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (8, 'Training Session', 'Employee training on new software.', 'Training Room 2', '2025-03-08 15:00:00', '2025-02-27 15:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (9, 'Supplier Negotiation', 'Negotiation with key suppliers.', 'Supplier HQ', '2025-03-09 12:30:00', '2025-02-28 16:00:00');
    
INSERT INTO `MyCMS`.`Meeting`
    (`UserID`, `MeetingTitle`, `Description`, `Location`, `MeetingDate`, `CreatedDate`)
VALUES
    (10, 'Board Meeting', 'Strategic planning meeting for executives.', 'Boardroom', '2025-03-10 17:00:00', '2025-03-29 17:00:00');

INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (1, 1, 'Accepted', '2025-02-25 08:30:00');

INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (1, 2, 'Pending', NULL);
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (2, 3, 'Accepted', '2025-02-26 09:15:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (2, 4, 'Declined', '2025-02-26 10:00:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (3, 5, 'Accepted', '2025-02-27 11:20:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (3, 6, 'Pending', NULL);
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (4, 7, 'Accepted', '2025-02-28 12:45:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (5, 8, 'Pending', NULL);
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (5, 9, 'Accepted', '2025-03-01 14:10:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (6, 10, 'Accepted', '2025-03-02 15:30:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (6, 1, 'Pending', NULL);
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (7, 2, 'Accepted', '2025-03-03 16:00:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (8, 3, 'Accepted', '2025-03-04 09:30:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (8, 4, 'Declined', '2025-03-04 10:20:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (9, 5, 'Accepted', '2025-03-05 11:45:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (9, 6, 'Pending', NULL);
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (10, 7, 'Accepted', '2025-03-06 13:10:00');
    
INSERT INTO `MyCMS`.`MeetingContactMapping`
    (`MeetingID`, `ContactID`, `InvitationStatus`, `ResponseDate`)
VALUES
    (10, 8, 'Accepted', '2025-03-06 14:30:00');
    
SET FOREIGN_KEY_CHECKS = 1;  -- Re-enable foreign key checks

SET @end_time = SYSDATE(6);
SELECT TIMESTAMPDIFF(MICROSECOND, @start_time, @end_time) / 1000000 AS execution_time_seconds;