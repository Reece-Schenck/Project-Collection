DELIMITER $$

CREATE TRIGGER DeleteUserContents
BEFORE DELETE ON user
FOR EACH ROW
BEGIN
    -- Delete associated contacts
    DELETE FROM contact WHERE UserID = OLD.UserID;

    -- Delete contact notes
    DELETE FROM contactnote WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);

    -- Delete contact’s phone numbers
    DELETE FROM phone WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);

    -- Delete contact’s emails
    DELETE FROM email WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);

    -- Delete activity logs
    DELETE FROM activitylog WHERE UserID = OLD.UserID;

    -- Delete meeting participation records
    DELETE FROM meetingcontactmapping WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);

    -- Delete contact group mappings
    DELETE FROM contactgroupmapping WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);

    -- Delete contact tag mappings
    DELETE FROM contacttagmapping WHERE ContactID IN (SELECT ContactID FROM contact WHERE UserID = OLD.UserID);
END $$

DELIMITER ;
