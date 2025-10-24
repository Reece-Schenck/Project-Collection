-- SET SQL_SAFE_UPDATES = 0;

-- CREATE TABLE orders (
--     order_id INT PRIMARY KEY AUTO_INCREMENT,
--     customer_name VARCHAR(100),
--     order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
--     status VARCHAR(50));

-- INSERT INTO orders (customer_name, order_date, status) Values 
-- ("Reece Schenck", "2025-02-09 11:30:00", "Pending");

-- UPDATE orders SET order_date = "2024-02-09 11:30:00" WHERE customer_name = "Reece Schenck";

-- CREATE TABLE events (
-- 	id INT AUTO_INCREMENT PRIMARY KEY,
--     event_name VARCHAR(100),
--     event_date DATE,
--     start_time TIME,
--     event_datetime DATETIME,
--     created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
-- );

-- INSERT INTO events (event_name, event_date, start_time, event_datetime)
-- VALUES ("Tech Conference", "2025-03-15", "09:00:00", "2025-03-15 09:00:00"),
-- 	("Music Festival", "2025-06-20", "18:30:00", "2025-06-20 18:30:00"),
-- 	("Webinar on AI", "2025-02-25", "15:00:00", "2025-02-25 15:00:00");

-- SELECT event_name, start_time FROM events WHERE event_date = "2025-03-15";

-- SELECT event_name, event_datetime FROM events WHERE event_datetime > NOW() ORDER BY event_datetime ASC;

-- INSERT INTO events (event_name, event_date, start_time, event_datetime) 
-- VALUE ("My yesterday festival", "2025-02-10", "17:00:00", "2025-02-11 17:00:00");

-- INSERT INTO events (event_name, event_date, start_time, event_datetime) 
-- VALUE ("My festival", "2025-02-11", "17:00:00", "2025-02-11 17:00:00");

-- SELECT event_name, event_datetime FROM events WHERE event_date = CURDATE();

-- SELECT event_name, event_datetime FROM events WHERE event_date BETWEEN CURDATE() AND DATE_ADD(CURDATE(), INTERVAL 7 DAY);

-- C0REATE TABLE delivery_zones ( id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), boundary POLYGON NOT NULL, SPATIAL INDEX (boundary) );

-- INSERT INTO delivery_zones (name, boundary) VALUES ('Zone A', ST_GeomFromText('POLYGON((0 0, 10 0, 10 10, 0 10, 0 0))'));

-- SELECT name FROM delivery_zones WHERE ST_Contains(boundary, ST_GeomFromText('POINT(5 5)'));

-- SELECT name FROM delivery_zones WHERE ST_Contains(boundary, ST_GeomFromText("POINT(20 20)"));

-- CREATE TABLE locations ( id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(100), coordinates POINT NOT NULL, SPATIAL INDEX (coordinates) );

-- INSERT INTO locations (name, coordinates) VALUES ("Central Park", ST_GeomFromText('POINT(-73.968285 40.785091)')); 

-- SELECT name FROM locations 
-- WHERE ST_Distance_Sphere(
--     coordinates, 
--     ST_SRID(ST_GeomFromText('POINT(-73.9600 40.7800)'), 0)
-- ) < 1000;
