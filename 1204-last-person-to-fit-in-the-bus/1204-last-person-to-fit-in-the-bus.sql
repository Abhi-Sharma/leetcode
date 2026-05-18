# Write your MySQL query statement below
select person_name from
(select person_name, turn, SUM(weight) OVER(ORDER BY turn) as total_weight from queue) q
where total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;
