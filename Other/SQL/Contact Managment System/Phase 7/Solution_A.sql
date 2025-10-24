use MyCMS;

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
VALUES 
  ('Phone type: Cell', 3, 1),
  ('Phone type: Cell', 4, 2),
  ('Phone type: Cell', 2, 3);

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

-- PART E

START TRANSACTION;

-- Target user to delete
SET @target_username := 'alice';

-- Step 1: Delete from Inventory
DELETE FROM Inventory
WHERE primaryUser = @target_username;

-- Step 2: Delete from user table
DELETE FROM user
WHERE username = @target_username;

-- Step 3: Commit everything
COMMIT;