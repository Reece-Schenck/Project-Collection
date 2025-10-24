use MyCMS;

CREATE TABLE Trush (
    username VARCHAR(255) PRIMARY KEY,
    FailedAttempts TINYINT,
    SuccessfulAttempt TINYINT
) ENGINE = BLACKHOLE;