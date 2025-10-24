CREATE SCHEMA IF NOT EXISTS `MyCMS` DEFAULT CHARACTER SET utf8 ;
USE `MyCMS` ;

-- -----------------------------------------------------
-- Table `MyCMS`.`User`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`User` (
  `UserID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `Username` VARCHAR(50) NOT NULL,
  `Password` VARCHAR(255) NOT NULL,
  `Role` ENUM('ADMIN', 'NORMAL') NOT NULL,
  `Email` VARCHAR(100) NOT NULL,
  `FirstName` VARCHAR(50) NULL DEFAULT NULL,
  `LastName` VARCHAR(50) NULL DEFAULT NULL,
  `LastLogin` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`UserID`),
  UNIQUE INDEX (`Username` ASC) VISIBLE,
  UNIQUE INDEX (`Email` ASC) VISIBLE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Company`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Company` (
  `CompanyID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `CompanyName` VARCHAR(100) NOT NULL,
  `Industry` VARCHAR(50) NULL DEFAULT NULL,
  `Street` VARCHAR(100) NULL DEFAULT NULL,
  `City` VARCHAR(50) NULL DEFAULT NULL,
  `State` VARCHAR(50) NULL DEFAULT NULL,
  `Zip` VARCHAR(20) NULL DEFAULT NULL,
  `Country` VARCHAR(50) NULL DEFAULT NULL,
  `Phone` VARCHAR(20) NULL DEFAULT NULL,
  `Email` VARCHAR(100) NULL DEFAULT NULL,
  `Website` VARCHAR(100) NULL DEFAULT NULL,
  PRIMARY KEY (`CompanyID`),
  UNIQUE INDEX (`CompanyName` ASC) VISIBLE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Picture`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Picture` (
  `PictureID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ImagePath` VARCHAR(255) NULL DEFAULT NULL,
  `UploadedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `Description` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`PictureID`));


-- -----------------------------------------------------
-- Table `MyCMS`.`Contact`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Contact` (
  `ContactID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `UserID` INT NOT NULL,
  `FirstName` VARCHAR(50) NOT NULL,
  `LastName` VARCHAR(50) NOT NULL,
  `DateOfBirth` DATE NOT NULL,
  `Gender` ENUM('M', 'F', 'Other') NULL DEFAULT NULL,
  `Street` VARCHAR(100) NULL DEFAULT NULL,
  `City` VARCHAR(50) NULL DEFAULT NULL,
  `State` VARCHAR(50) NULL DEFAULT NULL,
  `Zip` VARCHAR(20) NULL DEFAULT NULL,
  `Country` VARCHAR(50) NULL DEFAULT NULL,
  `CompanyID` INT NULL DEFAULT NULL,
  `Picture_PictureID` INT NOT NULL,
  PRIMARY KEY (`ContactID`, `Picture_PictureID`),
  INDEX (`UserID` ASC) VISIBLE,
  INDEX (`CompanyID` ASC) VISIBLE,
  INDEX `fk_Contact_Picture1_idx` (`Picture_PictureID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`UserID`)
    REFERENCES `MyCMS`.`User` (`UserID`)
    ON DELETE CASCADE,
  CONSTRAINT ``
    FOREIGN KEY (`CompanyID`)
    REFERENCES `MyCMS`.`Company` (`CompanyID`)
    ON DELETE SET NULL,
  CONSTRAINT `fk_Contact_Picture1`
    FOREIGN KEY (`Picture_PictureID`)
    REFERENCES `MyCMS`.`Picture` (`PictureID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION);


-- -----------------------------------------------------
-- Table `MyCMS`.`ContactNickname`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ContactNickname` (
  `NicknameID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `Nickname` VARCHAR(50) NOT NULL,
  `CreatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `UpdatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`NicknameID`, `ContactID`),
  INDEX (`ContactID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Phone`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Phone` (
  `PhoneID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `PhoneNumber` VARCHAR(20) NOT NULL,
  `PhoneType` ENUM('Cell', 'Home', 'Work', 'Fax') NOT NULL,
  `CountryCode` VARCHAR(10) NULL DEFAULT NULL,
  PRIMARY KEY (`PhoneID`),
  INDEX (`ContactID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Email`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Email` (
  `EmailID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `EmailAddress` VARCHAR(100) NOT NULL,
  `EmailType` ENUM('Personal', 'Work', 'Other') NOT NULL,
  `IsPrimary` TINYINT NULL DEFAULT FALSE,
  PRIMARY KEY (`EmailID`),
  INDEX (`ContactID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`ActivityType`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ActivityType` (
  `ActivityTypeID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `TypeName` VARCHAR(50) NOT NULL,
  `Description` TEXT NULL DEFAULT NULL,
  `CreatedAt` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `UpdatedAt` DATETIME NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ActivityTypeID`),
  UNIQUE INDEX (`TypeName` ASC) VISIBLE);


-- -----------------------------------------------------
-- Table `MyCMS`.`ActivityLog`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ActivityLog` (
  `LogID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `UserID` INT NOT NULL,
  `ActivityTypeID` INT NOT NULL,
  `Timestamp` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `Description` TEXT NULL DEFAULT NULL,
  PRIMARY KEY (`LogID`),
  INDEX (`UserID` ASC) VISIBLE,
  INDEX (`ActivityTypeID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`UserID`)
    REFERENCES `MyCMS`.`User` (`UserID`)
    ON DELETE CASCADE,
  CONSTRAINT ``
    FOREIGN KEY (`ActivityTypeID`)
    REFERENCES `MyCMS`.`ActivityType` (`ActivityTypeID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`ContactNote`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ContactNote` (
  `NoteID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `NoteTitle` VARCHAR(100) NULL DEFAULT NULL,
  `NoteText` TEXT NULL DEFAULT NULL,
  `CreatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `LastModified` DATETIME NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Status` ENUM('ACTIVE', 'REMOVED') NULL DEFAULT 'ACTIVE',
  PRIMARY KEY (`NoteID`),
  INDEX (`ContactID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`GroupTable`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`GroupTable` (
  `GroupID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `GroupName` VARCHAR(100) NOT NULL,
  `Description` TEXT NULL DEFAULT NULL,
  `CreatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `Status` VARCHAR(50) NULL DEFAULT NULL,
  PRIMARY KEY (`GroupID`),
  UNIQUE INDEX (`GroupName` ASC) VISIBLE);


-- -----------------------------------------------------
-- Table `MyCMS`.`ContactGroupMapping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ContactGroupMapping` (
  `MappingID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `GroupID` INT NOT NULL,
  `DateAdded` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `MappingStatus` ENUM('ACTIVE', 'INACTIVE') NULL DEFAULT 'ACTIVE',
  PRIMARY KEY (`MappingID`),
  INDEX (`ContactID` ASC) VISIBLE,
  INDEX (`GroupID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE,
  CONSTRAINT ``
    FOREIGN KEY (`GroupID`)
    REFERENCES `MyCMS`.`GroupTable` (`GroupID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Tag`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Tag` (
  `TagID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `TagName` VARCHAR(50) NOT NULL,
  `Description` TEXT NULL DEFAULT NULL,
  `CreatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `TagColor` VARCHAR(20) NULL DEFAULT NULL,
  PRIMARY KEY (`TagID`),
  UNIQUE INDEX (`TagName` ASC) VISIBLE);


-- -----------------------------------------------------
-- Table `MyCMS`.`ContactTagMapping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`ContactTagMapping` (
  `MappingID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `ContactID` INT NOT NULL,
  `TagID` INT NOT NULL,
  `CreatedTime` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  `Status` ENUM('ACTIVE', 'REMOVED') NULL DEFAULT 'ACTIVE',
  PRIMARY KEY (`MappingID`),
  INDEX (`ContactID` ASC) VISIBLE,
  INDEX (`TagID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE,
  CONSTRAINT ``
    FOREIGN KEY (`TagID`)
    REFERENCES `MyCMS`.`Tag` (`TagID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`Meeting`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`Meeting` (
  `MeetingID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `UserID` INT NOT NULL,
  `MeetingTitle` VARCHAR(100) NOT NULL,
  `Description` TEXT NULL DEFAULT NULL,
  `Location` VARCHAR(200) NULL DEFAULT NULL,
  `MeetingDate` DATETIME NOT NULL,
  `CreatedDate` DATETIME NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`MeetingID`),
  INDEX (`UserID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`UserID`)
    REFERENCES `MyCMS`.`User` (`UserID`)
    ON DELETE CASCADE);


-- -----------------------------------------------------
-- Table `MyCMS`.`MeetingContactMapping`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `MyCMS`.`MeetingContactMapping` (
  `MappingID` INT NULL DEFAULT NULL AUTO_INCREMENT,
  `MeetingID` INT NOT NULL,
  `ContactID` INT NOT NULL,
  `InvitationStatus` ENUM('Accepted', 'Declined', 'Pending') NULL DEFAULT 'Pending',
  `ResponseDate` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`MappingID`),
  INDEX (`MeetingID` ASC) VISIBLE,
  INDEX (`ContactID` ASC) VISIBLE,
  CONSTRAINT ``
    FOREIGN KEY (`MeetingID`)
    REFERENCES `MyCMS`.`Meeting` (`MeetingID`)
    ON DELETE CASCADE,
  CONSTRAINT ``
    FOREIGN KEY (`ContactID`)
    REFERENCES `MyCMS`.`Contact` (`ContactID`)
    ON DELETE CASCADE);
