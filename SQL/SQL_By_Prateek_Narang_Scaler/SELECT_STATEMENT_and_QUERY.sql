USE classicmodels;

-- // 2.1 // SELECT QUERY
-- It is a single statement and it is a example of select statemenet
SELECT * 
FROM employees
WHERE officeCode=1
ORDER BY firstName ASC;
SELECT firstName,lastName 
FROM employees
WHERE officeCode=1
ORDER BY firstName ASC;


-- // 2.2 // Various Clauses of the Select Statement
SELECT lastname,
       firstname,
       email
FROM employees;


SELECT lastname,
       firstname,
       email
FROM employees;


SELECT productName, 
	   quantityInStock,
       buyPrice,
       MSRP AS "Selling  Price" -- As is used to rename the columns name
FROM products;


-- Arithmetic Operations in the SELECT Statement
SELECT productName, 
	   quantityInStock,
       buyPrice,
       MSRP AS "Selling  Price", -- As is used to rename the columns name
       (MSRP*0.90) AS "Discounted  Price" -- Discounted Prices(It follows the BODMAS Rule .
FROM products;



-- // 2.3 // WHERE CLAUSE 
-- In Where Clause We can use all types of comparison operators.

-- Comparison Operators are:
-- >
-- >=
-- <
-- <=
-- =
-- != (Not eqaul to)
-- <> (Not eqaul to)

-- USing a Where clause with a specified condition
SELECT * 
FROM orders
WHERE status!="Shipped";

SELECT * 
FROM orders
WHERE status <>"Shipped";

-- // 2.4 // LOGICAL OPERATORS: AND OR NOT
-- SELECT * fROM Payments;

-- 1 AND Operator
SELECT *
FROM Payments
WHERE amount>=40000 AND amount<=60000;


-- 2. NOT Operator
SELECT *
FROM Payments
WHERE NOT(amount>=40000 AND amount<=60000); -- NOT will invert the logic (amount<=40000 OR amount>=60000)

-- 3. OR Operator
-- Another way of writing the same above query
SELECT *
FROM Payments
WHERE NOT(amount<=40000 OR amount>=60000);

-- Query: Payment_date>= 2005-03-15
SELECT *
FROM Payments
WHERE NOT(amount<=40000 OR amount>=60000)
	  AND ( PaymentDate>= '2005-03-15');


-- Without bracket order of execution will be different.
-- BECUASE AND > OR (Priority of AND is greater than Priority of OR).
SELECT *
FROM Payments
WHERE NOT amount<=40000 OR amount>=60000
	  AND PaymentDate>= '2005-03-15';



-- // 2.5 // IN OPERATOR
-- Here we can specify all queries within the bracket.
SELECT *
FROM employees 
WHERE officeCode=1 OR  officeCode=2 OR officeCode=4;

SELECT *
FROM employees 
WHERE officeCode in (1,2,4)
ORDER BY officeCode;

-- // NOT IN OPERATOR 

SELECT *
FROM employees 
WHERE officeCode NOT IN (1,2,4)
ORDER BY officeCode;

-- // 2.6 // BETWEEN  OPERATOR

SELECT *
FROM customers
WHERE creditLimit>=20000 AND creditLimit <=40000;

-- Same statement as above using between
SELECT *
FROM customers
WHERE creditLimit BETWEEN 20000 AND 40000;

SELECT *
FROM payments 
WHERE paymentDate BETWEEN '2003-05-31' AND '2004-02-01';


-- // 2.6 // LIKE OPERATOR
-- Que: Find all the rows where the word 'sale ' is present in the job title.

-- % operator will find 0 or more character before the term specified

SELECT *
FROM employees
WHERE jobTitle LIKE "%Sale%";

SELECT *
FROM employees
WHERE jobTitle LIKE "Sale%"; -- Now I will get only the rows, in which job Title has first 4 characters starting with Sale

SELECT *
FROM employees
WHERE jobTitle LIKE "%Sale"; -- Now I will get only the rows, in which job Title has last 4 characters starting with Sale

-- _(Underscore) operator will match only single characte
--   _ _ e (It will search a word in which starting 2 characters can be anything but the 3rd character is fixed, whihc gonna be e.

SELECT *
FROM employees
WHERE firstName LIKE "%e"; -- this will give all the names ending with e


SELECT *
FROM employees
WHERE firstName LIKE "____e"; -- this will give all the names having starting 4 characters can be anything , but the fifth character must be e.


-- // 2.6 // REGEX- Mainly used for Pattern/String Matching (Regex is a very Poerful Tool)
-- Use in email Validation.

-- REGEXP Operator:
-- 1. ^ beginning of string
-- 2. $ ending of the string
-- 3. | logical or
-- 4. [abcd]
-- 5. [a-z]

-- Query1 Search all the rows having "Sale" word anywhere in the JobTitle

SELECT *
FROM employees
WHERE jobTitle REGEXP "Sale";

-- 1. ^ beginning of string
-- Query1 Search all the rows having "Sale"  as the starting word  in the JobTitle column.
SELECT *
FROM employees
WHERE jobTitle REGEXP "^Sale";


-- 2. $ ending of the string
-- Query2 Search all the rows having "Rep"  as the ending word  in the JobTitle column.
SELECT *
FROM employees
WHERE jobTitle REGEXP "Rep$";

-- 3. | logical or
-- Query3 Search all the rows where the firstName starting with a or b.

SELECT *
FROM employees
WHERE firstname REGEXP ("^a|^b");

-- 4. [abcd]
-- Query3 Search all the rows where the firstName begins with characters ranges from [abcd]

SELECT *
FROM employees
WHERE firstname REGEXP ("^[abcd]");


-- 5. [a-d]
-- Query3 Search all the rows where the firstName begins with characters ranges from [a-d]

SELECT *
FROM employees
WHERE firstname REGEXP ("^[a-d]");


