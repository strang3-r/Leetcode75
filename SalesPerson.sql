# MySQL query to the problem of Sales Person

# Problem link : https://leetcode.com/problems/sales-person/


SELECT name
FROM SalesPerson
Where sales_id NOT IN (SELECT a.sales_id
                       FROM Orders a JOIN Company b on a.com_id = b.com_id
                       WHERE b.name = 'RED')
