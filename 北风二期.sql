select
 AVG((t1.val1 - t2.val2)) as val
FROM
 (SELECT
   id,value as val1
  FROM
   statis
  WHERE type = 'woman'
  GROUP BY id) as t1
LEFT JOIN
 (SELECT
   id,
   MIN(value) as val2
  FROM
   statis
  WHERE TYPE = 'man'
  GROUP BY id) as t2
ON t1.id = t2.id;



select 
	f1.f1_val as woman_avg,f2.f2_val as right_avg
from
	(select
 AVG((t1.val1 - t2.val2)) as f1_val
FROM
 (SELECT
   id,value as val1
  FROM
   statis
  WHERE type = 'woman'
  GROUP BY id) as t1
LEFT JOIN
 (SELECT
   id,
   MIN(value) as val2
  FROM
   statis
  WHERE TYPE = 'man'
  GROUP BY id) as t2
ON t1.id = t2.id) as f1,
(select
 AVG((t3.val3 - t4.val4)) as f2_val
FROM
 (SELECT
   id,value as val3
  FROM
   statis
  WHERE type = 'right'
  GROUP BY id) as t3
LEFT JOIN
 (SELECT
   id,
   MIN(value) as val4
  FROM
   statis
  WHERE type = 'left'
  GROUP BY id) as t4
ON t3.id = t4.id) as f2;
