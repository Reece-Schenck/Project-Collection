DELIMITER $$

CREATE PROCEDURE ChangePassword(
    IN p_username VARCHAR(255), 
    IN p_password VARCHAR(255), 
    IN p_newpassword VARCHAR(255)
)
BEGIN
    DECLARE KnowsOldPassword INT DEFAULT 0;

    -- Check if the provided username and password match
    SELECT COUNT(*) 
    INTO KnowsOldPassword
    FROM user
    WHERE username = p_username 
      AND password = SHA2(p_password, 256);

    -- If old password matches, update to the new password
    IF KnowsOldPassword > 0 THEN
        UPDATE user 
        SET password = SHA2(p_newpassword, 256)
        WHERE username = p_username;

        SELECT 'The password has been updated successfully.' AS Message;
    ELSE
        SELECT 'The provided password is not valid.' AS Message;
    END IF;
END $$

DELIMITER ;
