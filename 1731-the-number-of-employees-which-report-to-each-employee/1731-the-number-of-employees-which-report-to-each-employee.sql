# Write your MySQL query statement below
select e.employee_id, e.name, COUNT(em.reports_to) as reports_count, ROUND(SUM(em.age) / COUNT(em.age),0) as average_age
from employees e
join employees em
on e.employee_id = em.reports_to
group by e.employee_id
order by e.employee_id;