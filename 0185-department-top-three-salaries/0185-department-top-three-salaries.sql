# Write your MySQL query statement below
select d.name as Department, e.name as employee, e.salary as Salary
from
(
    select *, DENSE_RANK() OVER(
        PARTITION BY departmentId
        ORDER BY salary DESC
    ) as rnk
    from employee
) e
JOIN DEPARTMENT d
on e.departmentId = d.id
where rnk <= 3;
