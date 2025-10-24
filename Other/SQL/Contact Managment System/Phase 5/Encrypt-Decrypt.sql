SET @start_time = SYSDATE(6);

SET FOREIGN_KEY_CHECKS = 0;  -- Disable foreign key checks

-- Insert Encrypted Data
INSERT INTO `MyCMS`.`Phone`
    (`ContactID`, `PhoneNumber`, `PhoneType`, `CountryCode`)
VALUES
    (10, HEX(AES_ENCRYPT('603-751-2155', 'MySecretKey')), 'Cell', '+1');

-- Decrypt Data
SELECT 
	`ContactID`, 
    CAST(AES_DECRYPT(UNHEX(`PhoneNumber`), 'MySecretKey') AS CHAR(32)) AS decrypted_phone_number, 
    `PhoneType`, 
    `CountryCode`
FROM `MyCMS`.`Phone`;

SET FOREIGN_KEY_CHECKS = 1;  -- Re-enable foreign key checks

SET @end_time = SYSDATE(6);
SELECT TIMESTAMPDIFF(MICROSECOND, @start_time, @end_time) / 1000000 AS execution_time_seconds;