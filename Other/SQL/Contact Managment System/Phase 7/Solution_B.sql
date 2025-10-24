-- Part A

use MyCMS;

CREATE TABLE Trush (
    username VARCHAR(50) PRIMARY KEY,
    FailedAttempts TINYINT,
    SuccessfulAttempt TINYINT
) ENGINE = BLACKHOLE;

-- Part B

CREATE TABLE Inventory (
    itemID INT PRIMARY KEY,
    item VARCHAR(255),
    Availability INT,
    primaryUser VARCHAR(50)
) ENGINE = MYISAM;

-- Part C

INSERT INTO Trush (UserID, FailedAttempts, SuccessfulAttempts) VALUES
(1, 2, 5),
(2, 0, 3),
(3, 4, 1);

INSERT INTO Inventory (item, Availability, primaryUser)
SELECT 'contact' AS item, COUNT(*) AS Availability, u.Username
FROM contact c
JOIN user u ON c.UserID = u.UserID
GROUP BY u.Username;

INSERT INTO Inventory (item, Availability, primaryUser)
SELECT 'email' AS item, COUNT(*) AS Availability, u.Username
FROM email e
JOIN contact c ON e.ContactID = c.ContactID
JOIN user u ON c.UserID = u.UserID
GROUP BY u.Username;

INSERT INTO Inventory (item, Availability, primaryUser)
SELECT 'meeting' AS item, COUNT(*) AS Availability, u.Username
FROM meeting m
JOIN user u ON m.UserID = u.UserID
GROUP BY u.Username;

-- Part D

SELECT 
    I.itemID,
    I.item,
    I.Availability,
    T.FailedAttempts,
    T.SuccessfulAttempts
FROM Inventory I
JOIN Trush T ON I.primaryUser = T.username;

-- But as the Trush table engine is BLACKHOLE, the select will return an empty result

-- Part E

DELIMITER $$

CREATE PROCEDURE DeleteUserData(IN target_username VARCHAR(50))
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE tbl_name VARCHAR(100);
    DECLARE user_id INT;
    DECLARE cur CURSOR FOR 
        SELECT item FROM Inventory WHERE primaryUser = target_username;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    -- Step 1: Get UserID
    SELECT UserID INTO user_id
    FROM user
    WHERE username = target_username;

    START TRANSACTION;

    -- Step 2: Loop through all tables in Inventory
    OPEN cur;
    read_loop: LOOP
        FETCH cur INTO tbl_name;
        IF done THEN
            LEAVE read_loop;
        END IF;

        -- Step 3: Build and execute DELETE statement
        SET @sql_text = CONCAT('DELETE FROM ', tbl_name, ' WHERE UserID = ?');
        PREPARE stmt FROM @sql_text;
        EXECUTE stmt USING @user_id;
        DEALLOCATE PREPARE stmt;
    END LOOP;
    CLOSE cur;

    -- Step 4: Clean up Inventory and User
    DELETE FROM Inventory WHERE primaryUser = target_username;
    DELETE FROM user WHERE username = target_username;

    COMMIT;
END$$

DELIMITER ;