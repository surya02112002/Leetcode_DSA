# Write your MySQL query statement below
SELECT ue.unique_id , e.name
FROM Employees as e
left join EmployeeUNI ue on e.id = ue.id