CREATE DATABASE university;



USE university;


 -- TABLE 1
CREATE TABLE student(
	student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    GPA DECIMAL (3,2),
-- DECIMAL(3, 2) means:

-- The total number of digits allowed is 3.
-- Out of those 3 digits, 2 digits will be after the decimal point. 
	enrollment_date DATETIME,
    major VARCHAR(50)
);

-- DROP TABLE  student;
-- INSERT INTO student VALUES (1,'Shivansh',
--  'Mahajan', 8.79, '2021-09-01 09:30:00', 'Computer Science');
--  

INSERT INTO Student (STUDENT_ID, FIRST_NAME, LAST_NAME, GPA, ENROLLMENT_DATE, MAJOR)
VALUES
(201, 'Shivansh', 'Mahajan', 8.79, '2021-09-01 09:30:00', 'Computer Science'),
(202, 'Umesh', 'Sharma', 8.44, '2021-09-01 08:30:00', 'Mathematics'),
(203, 'Rakesh', 'Kumar', 5.60, '2021-09-01 10:00:00', 'Biology'),
(204, 'Radha', 'Sharma', 9.20, '2021-09-01 12:45:00', 'Chemistry'),
(205, 'Kush', 'Kumar', 7.85, '2021-09-01 08:30:00', 'Physics'),
(206, 'Prem', 'Chopra', 9.56, '2021-09-01 09:24:00', 'History'),
(207, 'Pankaj', 'Vats', 9.78, '2021-09-01 14:30:00', 'English'),
(208, 'Navleen', 'Kaur', 7.00, '2021-09-01 06:30:00', 'Mathematics');



 SELECT * FROM student;
 
 
 
 
 
 -- TABLE 2 
 
 -- Creating Program Table
CREATE TABLE Program (
    STUDENT_REF_ID INT,
    PROGRAM_NAME VARCHAR(50),
    PROGRAM_START_DATE DATETIME,
    FOREIGN KEY (STUDENT_REF_ID) REFERENCES Student(STUDENT_ID)
);
 
 
INSERT INTO Program (STUDENT_REF_ID, PROGRAM_NAME, PROGRAM_START_DATE)
VALUES
(201, 'Computer Science', '2021-09-01 00:00:00'),
(202, 'Mathematics', '2021-09-01 00:00:00'),
(208, 'Mathematics', '2021-09-01 00:00:00'),
(205, 'Physics', '2021-09-01 00:00:00'),
(204, 'Chemistry', '2021-09-01 00:00:00'),
(207, 'Psychology', '2021-09-01 00:00:00'),
(206, 'History', '2021-09-01 00:00:00'),
(203, 'Biology', '2021-09-01 00:00:00');


 SELECT * FROM Program;
 
 
 
 
 -- 3rd Table
 
 -- Creating Scholarship Table

CREATE TABLE Scholarship (
    STUDENT_REF_ID INT,
    SCHOLARSHIP_AMOUNT DECIMAL(10, 2),
    SCHOLARSHIP_DATE DATETIME,
    FOREIGN KEY (STUDENT_REF_ID) REFERENCES Student(STUDENT_ID)
);
TRUNCATE Table  Scholarship;
INSERT INTO Scholarship (STUDENT_REF_ID, SCHOLARSHIP_AMOUNT, SCHOLARSHIP_DATE)
VALUES
(201, 5000, '2021-10-15 00:00:00'),
(202, 4500, '2022-08-18 00:00:00'),
(203, 3000, '2022-01-25 00:00:00'),
(201, 4000, '2021-10-15 00:00:00');

 SELECT * FROM Scholarship;