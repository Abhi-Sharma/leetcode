# Write your MySQL query statement below
select id , COUNT(*) as num
from 
(
    select requester_id as id
    from requestaccepted 

    union all

    select accepter_id as id
    from requestaccepted
) t
group by id
order by num DESC
limit 1;