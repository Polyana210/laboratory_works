Task 1
SELECT * FROM public."user" where id=2;
SELECT * FROM public."doctor" where id=1;
SELECT * FROM public."patient" where id=6;
SELECT * FROM public."phone" where id=2;
SELECT * FROM public."card" where id=1;
SELECT * FROM public."inspection" where id=1;
SELECT * FROM public."speciality" where id=1;
SELECT * FROM public."procedure" where id=1;
Task 2
SELECT * FROM public."procedure" where id>1 and id<5;
SELECT * FROM public."phone" where id=2;
Task 3
SELECT * FROM doctor INNER JOIN phone on (doctor.id=phone.id);
SELECT * FROM speciality LEFT JOIN doctor on (speciality.id=doctor.id_speciality);
SELECT * FROM speciality RIGHT JOIN doctor on (speciality.id=doctor.id_speciality);	
Task 4
SELECT COUNT(id) FROM public."user" where role=3;
SELECT SUM(id)FROM procedure where doctor_1_id=9;