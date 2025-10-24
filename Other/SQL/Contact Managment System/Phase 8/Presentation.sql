-- Demostrating the database
SHOW TABLES;

DESC user;
DESC contact;
DESC contactnote;

SELECT * FROM user;
SELECT * FROM contact WHERE UserID = 1;
SELECT * FROM contact WHERE UserID = 2;

SELECT * FROM activitylog WHERE UserID = 2;

-- Running a demo of the project

-- 1. Create a user
INSERT INTO user (FirstName, LastName, Username, Email, Password)
VALUES ('Juan', 'Pérez', 'jperez', 'juan@example.com', '1e9d59ad9be1cb302e155d55b61c95b3b3db897da2ed9643b15f8802039ffc8c');

SET @last_user_id = LAST_INSERT_ID();

-- 2. Create contacts for that user
INSERT INTO contact (UserID, FirstName, LastName, DateOfBirth, Gender, Street, City, State, Zip, Country)
VALUES
	(@last_user_id, 'Emily', 'Johnson', '1988-08-12', 'F','742 Evergreen Terrace', 'Springfield', 'IL', '62704', 'United States');

SET @other_contact_id = LAST_INSERT_ID();

INSERT INTO contact (UserID, FirstName, LastName, DateOfBirth, Gender, Street, City, State, Zip, Country)
VALUES 
	(@last_user_id, 'Michael', 'Anderson', '1992-03-27', 'M', '1600 Pennsylvania Avenue NW', 'Washington', 'DC', '20500', 'United States');
  
SET @last_contact_id = LAST_INSERT_ID();

-- 3. Adding info about the contact: phone, email, tags
INSERT INTO phone (ContactID, PhoneNumber, PhoneType)
VALUES
  (@last_contact_id, '123-456-7890', 'Cell'),
  (@last_contact_id, '987-654-3210', 'Home');

INSERT INTO email (ContactID, EmailAddress, EmailType, IsPrimary)
VALUES
  (@last_contact_id, 'ana.lopez@example.com', 'Work',true);
  
INSERT INTO tag (TagName,TagColor)
VALUES ('Client', 'grey');

SET @last_tag_id = LAST_INSERT_ID();

INSERT INTO contacttagmapping (ContactID, TagID)
VALUES
  (@last_contact_id, @last_tag_id);

-- 4. Listing all the contacts for that user
SELECT c.ContactID, c.FirstName, c.LastName, c.DateOfBirth, c.Gender
FROM contact c
WHERE c.UserID = @last_user_id;

-- 5. Creating a contact note
INSERT INTO contactnote (ContactID, NoteTitle, NoteText)
VALUES
  (@last_contact_id, 'First Call', 'Ana showed interest in our services.');

-- 6. Create a meeting for a group of contacts
-- INSERT INTO contactgroup (GroupName, GroupDescription)
-- VALUES ('Reunión de seguimiento', 'Clientes importantes para reunión semanal');

-- SET @last_groupmapping_id = LAST_INSERT_ID();

-- INSERT INTO contactgroupmapping (ContactID, GroupID)
-- VALUES
--   (@other_contact_id, @last_groupmapping_id),
--   (@last_contact_id, @last_groupmapping_id);

INSERT INTO meeting (UserID, MeetingTitle, Description, MeetingDate, Location)
VALUES (@last_user_id, 'Seguimiento Semanal', 'Discutir avances y próximos pasos', '2025-05-10 10:00:00', 'Sala Zoom 123');

SET @last_meeting_id = LAST_INSERT_ID();

INSERT INTO meetingcontactmapping (ContactID, MeetingID)
VALUES
  (@other_contact_id, @last_meeting_id),
  (@last_contact_id, @last_meeting_id);