# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary 
FROM Employee
WHERE salary < (SELECT max(salary) FROM Employee);