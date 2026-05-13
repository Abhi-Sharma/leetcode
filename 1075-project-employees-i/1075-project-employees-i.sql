# Write your MySQL query statement below
select p.project_id , ROUND(IFNULL(SUM(e.experience_years) / COUNT(e.experience_years),0),2) as average_years
from project as p
left join employee as e
on p.employee_id = e.employee_id
group by p.project_id;