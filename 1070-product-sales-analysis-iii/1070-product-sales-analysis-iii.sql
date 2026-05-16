# Write your MySQL query statement below
select s.product_id, s.year as first_year, quantity, price 
from sales s
join (select product_id, MIN(year) as first_year
from sales
group by product_id) f
on s.product_id = f.product_id
and s.year = f.first_year;