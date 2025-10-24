
-- A. Access control:

	-- Creating two users:

		CREATE USER 'admin_user'@'%' IDENTIFIED BY 'adminpassword';
		CREATE USER 'normal_user'@'%' IDENTIFIED BY 'normalpassword';

	-- Assigning priveleges:

		-- Admin user: as an admin user it will be granted all the privileges to all the tables on the database "mycms"
		
			GRANT ALL PRIVILEGES ON mycms.* TO 'admin_user'@'%';

		-- Normal user: For a regular user only viewing, inserting and updating privileges will be assigned. This may us think about implementing a logical erase of the data.

			GRANT SELECT, INSERT, UPDATE ON MyCMS.User TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Company TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Contact TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ContactNickname TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Phone TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Email TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Picture TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ActivityType TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ActivityLog TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ContactNote TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.GroupTable TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ContactGroupMapping TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Tag TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.ContactTagMapping TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.Meeting TO 'normal_user'@'%';
			GRANT SELECT, INSERT, UPDATE ON MyCMS.MeetingContactMapping TO 'normal_user'@'%';

	-- Accessible tasks example:

		-- Admin user: as the admin user it has privileges for all the tasks, here some examples:

			-- Creating a new table:

				CREATE TABLE MyCMS.SampleTable (
				    id INT PRIMARY KEY,
				    name VARCHAR(100)
				);

			-- Reading data from a table:

				SELECT * FROM MyCMS.User;

			-- Adding a new row to a table:

				INSERT INTO MyCMS.User (id, first_name, last_name)
				VALUES (200, 'Alice', 'Admin');

			-- Modifying existing data:

				UPDATE MyCMS.User
				SET last_name = 'Superadmin'
				WHERE id = 200;

			-- Removing rows:

				DELETE FROM MyCMS.User
				WHERE id = 200;

			-- Deleting a table:

				DROP TABLE MyCMS.SampleTable;

			-- Modifying a table structure:

				ALTER TABLE MyCMS.Company
				ADD COLUMN founded_year INT;

			-- Granting privileges to other user:

				GRANT SELECT ON MyCMS.Contact TO 'normal_user'@'%';

		-- Regular user: the regular user has some privileges as viewing, inserting and updating.

			-- Reading data from a table:

				SELECT * FROM MyCMS.Contact;

			-- Adding a new row to a table:

				INSERT INTO MyCMS.Contact (id, first_name, last_name)
				VALUES (301, 'Bob', 'User');

			-- Modifying existing data:

				UPDATE MyCMS.Contact
				SET last_name = 'Patterson'
				WHERE id = 301;

	-- Out of privileges examples:

		-- Admin user: given that the admin user have all the privileges over the database there are not actions out of its privileges.

		-- Regular user:

			-- Removing records:

				DELETE FROM MyCMS.Contact WHERE id = 301;

			-- Removing a table:

				DROP TABLE MyCMS.Contact;

			-- Changing a table structure:

				ALTER TABLE MyCMS.User ADD COLUMN nickname VARCHAR(50);

			-- Creating a table:

				CREATE TABLE MyCMS.TestTable (
				    id INT PRIMARY KEY,
				    name VARCHAR(100)
				);

			-- Granting privileges to other user:

				GRANT SELECT ON MyCMS.Contact TO 'other_user'@'%';

-- B. Inference control:

	-- Before doing the task in this part of the assignment we create a role "administrator", given that in the task we are ask to grant access to a group of user, and in MySQL a way to do this is by creating a rol that will act as a group:

	-- Creating a role:

		CREATE ROLE 'administrator';

	-- Assigning the role to as user (adding the user to the group):

		GRANT 'administrator' TO 'admin_user'@'%';

	-- Now we continue with the first tasks.

	-- Creating a summarized view: we create a view to know how many contacts the database have and what is the average age of the contacts.

		CREATE OR REPLACE VIEW MyCMS.SummarizedView AS
		SELECT
			(SELECT COUNT(*) FROM MyCMS.Contact) AS TotalContacts,
		 	(SELECT AVG(TIMESTAMPDIFF(YEAR, DateOfBirth, CURDATE())) FROM MyCMS.Contact) AS AverageContactAge;

	-- Granting privileges to the view:

		GRANT SELECT ON MyCMS.SummarizedView TO 'administrator';

	-- Accesing and quering: now we access as the admin_user and perform a query to the view.

		-- mysql -u admin_user -padminpassword

		SELECT * FROM MyCMS.SummarizedView;

-- C. Flow Control:

	-- Altering the login table:

	-- We use the 'user' table to manage the logins and we have the "Password" field that will store the password, first we created it as a VARCHAR(255), planing to save a SHA256, but we realized that only 64 characters are necesary and it is more efficient to have a CHAR field type given that the password will always have the same length.

		ALTER TABLE MyCMS.User
		MODIFY COLUMN Password CHAR(64) NOT NULL;

	-- Inserting new users:

		INSERT INTO MyCMS.User (Username, Password, Role, Email, FirstName, LastName)
		VALUES 
		  ('alice', SHA2('alice_password', 256), 'ADMIN', 'alice@example.com', 'Alice', 'Smith'),
		  ('bob', SHA2('bob_password', 256), 'NORMAL', 'bob@example.com', 'Bob', 'Jones'),
		  ('charlie', SHA2('charlie_password', 256), 'NORMAL', 'charlie@example.com', 'Charlie', 'Brown');

	-- Procedure to authenticate:

DELIMITER //

CREATE PROCEDURE MyCMS.AuthenticateUser (
    IN inUsername VARCHAR(50),
    IN inPassword VARCHAR(255)
)
BEGIN
    DECLARE hashedPassword CHAR(64);
    DECLARE storedPassword CHAR(64) DEFAULT NULL;

    -- Handler for when no row is found (SQLSTATE '02000')
    DECLARE CONTINUE HANDLER FOR SQLSTATE '02000'
    BEGIN
        SET storedPassword = NULL;
    END;

    -- Compute SHA-256 hash of the provided password
    SET hashedPassword = SHA2(inPassword, 256);
    
    -- Attempt to fetch the stored hashed password for the given username
    SELECT Password 
      INTO storedPassword
      FROM MyCMS.User
     WHERE Username = inUsername
     LIMIT 1;
    
    -- Check if a user exists and if the hashed passwords match
    IF storedPassword IS NULL THEN
        SELECT 'Access Rejected: Username not found' AS Message;
    ELSEIF storedPassword = hashedPassword THEN
        SELECT 'Access Granted' AS Message;
    ELSE
        SELECT 'Access Rejected: Incorrect Password' AS Message;
    END IF;
    
END //

DELIMITER ;

-- CALL MyCMS.AuthenticateUser('alice', 'alice_password');