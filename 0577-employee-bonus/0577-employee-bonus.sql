# Write your MySQL query statement below
select e.name, b.bonus from employee e
LEFT JOIN bonus b 
on e.empid = b.empid
where bonus < 1000 OR bonus IS NULL;