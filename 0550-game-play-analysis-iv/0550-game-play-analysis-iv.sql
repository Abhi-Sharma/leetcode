# Write your MySQL query statement below
select ROUND(COUNT(DISTINCT a.player_id) / (
    select COUNT(DISTINCT player_id) from activity
),2) as fraction from activity a
join activity a1
on a.player_id = a1.player_id
and DATEDIFF(a1.event_date , a.event_date) = 1
where (a.player_id, a.event_date) IN
(select player_id, MIN(event_date)
from activity group by player_id);