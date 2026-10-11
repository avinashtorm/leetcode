# Write your MySQL query statement below
select distinct author_id as id from Views as t where t.author_id=t.viewer_id order by author_id 