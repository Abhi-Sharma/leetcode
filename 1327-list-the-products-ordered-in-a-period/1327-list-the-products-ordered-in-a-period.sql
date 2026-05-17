# Write your MySQL query statement below
select p.product_name, SUM(o.unit) as unit 
from products p
join orders o
on p.product_id = o.product_id
WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
group by p.product_id, p.product_name
having sum(o.unit) >= 100;