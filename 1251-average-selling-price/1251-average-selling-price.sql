# Write your MySQL query statement below
select p.product_id , ROUND(IFNULL(SUM(u.units * p.price)/ SUM(u.units), 0),2) as average_price
from prices p
left join unitssold u
on p.product_id = u.product_id
and u.purchase_date BETWEEN start_date and end_date
group by p.product_id;