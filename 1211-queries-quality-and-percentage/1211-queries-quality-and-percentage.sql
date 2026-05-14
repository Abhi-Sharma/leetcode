# Write your MySQL query statement below
select query_name, ROUND(SUM(rating/position) / COUNT(rating),2) as quality, ROUND((SUM(rating < 3) /COUNT(rating)) * 100,2) as poor_query_percentage from queries
group by query_name;