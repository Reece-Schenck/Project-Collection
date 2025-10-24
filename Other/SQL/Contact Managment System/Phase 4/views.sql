CREATE OR REPLACE VIEW vw_login AS
SELECT 
	UserID,
	Username,
	Password,
	Role
FROM users;

CREATE OR REPLACE VIEW vw_users_list AS
SELECT
	UserID,
	Username,
	FirstName,
	LastName,
	Email,
	Role,
FROM users;

CREATE OR REPLACE VIEW vw_user_details AS
SELECT
	UserID,
	Username,
	Email,
	Role,
	FirstName,
	LastName,
FROM users;

CREATE OR REPLACE VIEW vw_admin_user_contacts AS
SELECT
	u.UserID,
	u.Username,
	c.ContactID,
	c.FirstName AS ContactFirstName,
	c.LastName AS ContactLastName,
	GROUP_CONCAT(DISTINCT CONCAT(p.PhoneNumber, ' (', p.PhoneType, ')') SEPARATOR ', ') AS PhoneNumbers,
	GROUP_CONCAT(DISTINCT CONCAT(e.EmailAddress, ' (', e.EmailType, ')') SEPARATOR ', ') AS EmailAddresses
FROM MyCMS.User u
JOIN MyCMS.Contact c ON u.UserID = c.UserID
LEFT JOIN MyCMS.Phone p ON c.ContactID = p.ContactID
LEFT JOIN MyCMS.Email e ON c.ContactID = e.ContactID
GROUP BY
	u.UserID,
	u.Username,
	c.ContactID,
	c.FirstName,
	c.LastName;

CREATE OR REPLACE VIEW vw_activity_log AS
SELECT
	al.LogID,
	al.Timestamp,
	u.UserID,
	u.Username,
	u.Email,
	at.ActivityTypeID,
	at.TypeName,
	at.Description AS ActivityTypeDescription,
	al.Description AS LogDescription
FROM MyCMS.ActivityLog AS al
JOIN MyCMS.User AS u ON al.UserID = u.UserID
JOIN MyCMS.ActivityType AS at ON al.ActivityTypeID = at.ActivityTypeID;

CREATE OR REPLACE VIEW vw_contacts_list AS
SELECT
	c.ContactID,
	c.UserID,
	CONCAT(c.FirstName, ' ', c.LastName) AS FullName,
	c.DateOfBirth,
	c.Gender,
	c.Street,
	c.City,
	c.State,
	c.Zip,
	c.Country,
	c.CompanyID,
	GROUP_CONCAT(t.TagName SEPARATOR ', ') AS TagNames
FROM MyCMS.Contact c
LEFT JOIN MyCMS.ContactTagMapping ctm ON c.ContactID = ctm.ContactID
LEFT JOIN MyCMS.Tag t ON ctm.TagID = t.TagID
GROUP BY
	c.ContactID,
	c.UserID,
	c.FirstName,
	c.LastName,
	c.DateOfBirth,
	c.Gender,
	c.Street,
	c.City,
	c.State,
	c.Zip,
	c.Country,
	c.CompanyID;

CREATE OR REPLACE VIEW vw_contact_details AS
SELECT
	ContactID,
	UserID,
	FirstName,
	LastName,
	DateOfBirth,
	Gender,
	Street,
	City,
	State,
	Zip,
	Country,
	CompanyID
FROM MyCMS.Contact;

CREATE OR REPLACE VIEW vw_company_details AS
SELECT
	CompanyID,
	CompanyName,
	Industry,
	Street,
	City,
	State,
	Zip,
	Country,
	Phone,
	Email,
	Website
FROM MyCMS.Company;

CREATE OR REPLACE VIEW vw_profile AS
SELECT
	UserID,
	Username,
	Email,
	FirstName,
	LastName,
	LastLogin
FROM MyCMS.User;

CREATE OR REPLACE VIEW vw_change_password AS
SELECT
	UserID,
	password
FROM users;

CREATE OR REPLACE VIEW vw_meetings AS
SELECT
	MeetingID,
	UserID AS OrganizerID,
	MeetingTitle AS Title,
	Description,
	MeetingDate AS ScheduledDate,
	Location,
	CreatedDate AS CreatedAt
FROM MyCMS.Meeting;

CREATE OR REPLACE VIEW vw_meeting_details AS
SELECT
	m.MeetingID,
	m.UserID AS OrganizerID,
	m.MeetingTitle AS Title,
	m.Description,
	m.MeetingDate AS ScheduledDate,
	m.Location,
	mcm.ContactID AS InviteeID,
	mcm.InvitationStatus AS ResponseStatus,
	mcm.ResponseDate AS RespondedAt
FROM MyCMS.Meeting m
LEFT JOIN MyCMS.MeetingContactMapping mcm ON m.MeetingID = mcm.MeetingID;

CREATE OR REPLACE VIEW vw_meeting_response AS
SELECT
	MeetingID AS meeting_id,
	ContactID AS invitee_id,
	InvitationStatus AS response_status,
	ResponseDate AS responded_at
FROM MyCMS.MeetingContactMapping;