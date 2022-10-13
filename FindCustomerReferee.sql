# MySQL query for problem of Finding Customer Referee

# Problem link : https://leetcode.com/problems/find-customer-referee/

SELECT name 
From Customer
WHERE id NOT IN (SELECT id 
                WHERE referee_id = 2);
                
                
