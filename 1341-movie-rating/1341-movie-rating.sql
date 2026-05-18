# Write your MySQL query statement below
(select u.name as results
from users u
join movierating m
on u.user_id = m.user_id
group by u.user_id , u.name 
order by count(*) DESC, u.name ASC
LIMIT 1
) 
UNION ALL
(
    select mo.title as results 
    from movies mo
    join movierating m
    on mo.movie_id = m.movie_id
    WHERE m.created_at LIKE '2020-02%'
    group by mo.movie_id, mo.title
    order by AVG(rating) DESC, mo.title ASC
    LIMIT 1
)