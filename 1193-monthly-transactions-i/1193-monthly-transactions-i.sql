# Write your MySQL query statement below
select DATE_FORMAT(trans_date, '%Y-%m') as month, country, COUNT(state) as trans_count, SUM(state = 'approved') as approved_count,
SUM(amount) as trans_total_amount, 
SUM(
        CASE 
            WHEN state = 'approved' THEN amount
            ELSE 0
        END
    ) AS approved_total_amount from transactions
group by month, country;