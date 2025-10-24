SET FOREIGN_KEY_CHECKS = 0;  -- Disable foreign key checks

TRUNCATE TABLE `MyCMS`.`MeetingContactMapping`;
TRUNCATE TABLE `MyCMS`.`Meeting`;
TRUNCATE TABLE `MyCMS`.`ContactTagMapping`;
TRUNCATE TABLE `MyCMS`.`Tag`;
TRUNCATE TABLE `MyCMS`.`ContactGroupMapping`;
TRUNCATE TABLE `MyCMS`.`GroupTable`;
TRUNCATE TABLE `MyCMS`.`ContactNote`;
TRUNCATE TABLE `MyCMS`.`ActivityLog`;
TRUNCATE TABLE `MyCMS`.`ActivityType`;
TRUNCATE TABLE `MyCMS`.`Picture`;
TRUNCATE TABLE `MyCMS`.`Email`;
TRUNCATE TABLE `MyCMS`.`Phone`;
TRUNCATE TABLE `MyCMS`.`ContactNickname`;
TRUNCATE TABLE `MyCMS`.`Contact`;
TRUNCATE TABLE `MyCMS`.`Company`;
TRUNCATE TABLE `MyCMS`.`User`;

SET FOREIGN_KEY_CHECKS = 1;  -- Re-enable foreign key checks