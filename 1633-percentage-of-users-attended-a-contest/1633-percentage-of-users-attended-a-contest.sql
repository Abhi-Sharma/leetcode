# Write your MySQL query statement below
select r.contest_id, ROUND(
    COUNT(DISTINCT r.user_id) * 100 / (select COUNT(*) from users),2  
) as percentage from register r
left join users u
on r.user_id = u.user_id
group by r.contest_id
order by percentage DESC, contest_id ASC;