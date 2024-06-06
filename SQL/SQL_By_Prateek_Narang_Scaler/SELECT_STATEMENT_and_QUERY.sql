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


