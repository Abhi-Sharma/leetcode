# Write your MySQL query statement below
select 'Low Salary' as category, COUNT(
    CASE 
    WHEN income < 20000 THEN 1
    END
) as accounts_count from accounts
UNION
select 'Average Salary' as category, COUNT(
    CASE 
    WHEN income BETWEEN 20000 AND 50000 THEN 1 
    END
) as accounts_count from accounts
UNION
select 'High Salary' as category, COUNT(
    CASE 
    WHEN income > 50000 THEN 1
    END
) as accounts_count from accounts;