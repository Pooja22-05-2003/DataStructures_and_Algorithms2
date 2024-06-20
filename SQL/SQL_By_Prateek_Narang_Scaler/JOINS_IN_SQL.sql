USE classicmodels;

-- ---------------------------------------------------------------------------------------
-- JOINS - (Used for Retrieving the data from the multiple Tables 
-- Types of JOIN in SQL
--  There are many types of Joins in SQL. Depending on the use case, you can use different type of SQL JOIN clause. Here are the frequently used SQL JOIN types:

-- Website Link (To study more about the types:- https://www.devart.com/dbforge/sql/sqlcomplete/sql-join-statements.html#:~:text=SQL%20RIGHT%20OUTER%20JOIN%20creates,rows%20within%20the%20same%20table.)
-- GFG Join:-  https://www.geeksforgeeks.org/sql-join-set-1-inner-left-right-and-full-joins/

-- 1. INNER JOIN
-- 2. EXPLICIT JOIN
-- SELF JOIN
-- OUTER JOIN (a) LEFT JOIN (B) RIGHT JOIN (c) FULL JOIN
-- NATURAL JOIN 
-- CROSS JOIN
-- ---------------------------------------------------------------------------------------

-- -----------------------------
-- 1. 3.1 INNER JOINS
-- -----------------------------

SELECT * FROM payments;

-- Q Give me the table which give all the columns data from the Payment table also give me the customer name table from the customer table.
-- EXPLICIT JOIN
SELECT * -- This will give the merge table from both the table, means all the columns
FROM payments
INNER JOIN  customers 
ON payments.customerNumber=customers.customerNumber;

SELECT payments.customerNumber,checkNumber,paymentDate, amount,customerName
FROM payments
INNER JOIN  customers
ON payments.customerNumber=customers.customerNumber;


-- We can also give ALIAS to the table names to make it more concise.

SELECT p.customerNumber,checkNumber,paymentDate, amount,customerName
FROM payments AS p
INNER JOIN  customers AS c -- AS is not compulsory u can also remove it.
ON p.customerNumber=c.customerNumber;


-- -----------------------------
-- 3.2. INNER JOINS(QUERYING MULTIPLE TABLES
-- -----------------------------

SELECT orderNumber,status,o.customerNumber,c.customerName,e.firstName AS "Sales Person Name",e.jobTitle
FROM orders o
JOIN customers c
	ON o.customerNumber=c.customerNumber
JOIN employees e
	ON c.salesRepEmployeeNumber=e.employeeNumber;
    
-- ----------------------------------------------------------
-- 2. SELF  JOINS (Joining the same table withitself)
-- -------------------------------------------------------

-- Q) Get the details of the empolyess reports to column, whom person this pointing.


SELECT emp.employeeNumber,emp.firstName,emp.jobTitle,
		mgr.firstName AS "Manager Name",
        mgr.jobTitle AS "Manager Job Title"
FROM employees emp
JOIN employees mgr
     ON emp.reportsTo=mgr.employeeNumber;


-- ----------------------------------------------------------
-- 3. IMPLICIT  JOINS (Joining the same table withitself)
-- -------------------------------------------------------

-- a) EXPLICIT JOIN
SELECT payments.customerNumber,checkNumber,paymentDate, amount,customerName
FROM payments
INNER JOIN  customers -- ⭐⭐This is called as EXPLICIT JOIN, as we are writing the JOIN keyword explicitly.
ON payments.customerNumber=customers.customerNumber;

-- b) IMPLICIT JOIN- Not specifying the join keyword, but doing the join
SELECT p.customerNumber,checkNumber,paymentDate, amount,customerName
FROM payments p,customers c 
WHERE  p.customerNumber=c.customerNumber;