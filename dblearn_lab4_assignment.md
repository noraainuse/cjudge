

    DATABASE SYSTEM CONCEPT 2569 Assignment: 2569-LAB04-SQL SELECT Submission #104752 

    14:37:59 



Submission #104752
ID 	104752
Quiz Name 	2569-LAB04-SQL SELECT
User 	it68070141 (Mr.BHUMITHONG PAIBOONPAN)
Score 	???
Status 	???
Started at 	2026-07-29 16:36:01
Submitted at 	2026-08-05 00:11:43
SQL
SQL
Question # 2584
    Question Detail 	จงแสดงอีเมลและเบอร์โทรศัพท์ของพนักงานทุกคน (คั่นอีเมลและเบอร์โทรศัพท์ด้วย whitespace) ตั้งชื่อคอลัมน์ว่า Contact
*ตัวอย่างบางส่วนจากคำตอบ
    User Answer #811800 	

SELECT CONCAT(email,' ',phone_number) AS Contact
FROM employees;

Question # 308
    Question Detail 	จงแสดงชื่อและนามสกุลของพนักงาน  (คั่นชื่อและนามสกุลด้วย whitespace) ตั้งชื่อคอลัมน์ว่า full name
*ตัวอย่างบางส่วนจากคำตอบ
full name
Steven King
Neena Kochhar
Lex De Haan
Alexander Hunold
Bruce Ernst
    User Answer #811804 	

SELECT CONCAT(first_name, ' ', last_name) AS `full name`
FROM employees;

Question # 2586
    Question Detail 	จงแสดงรหัสประเทศ และรหัสภูมิภาคทั้งหมด เรียงผลลัพธ์ด้วยชื่อประเทศจาก Z-A
    User Answer #811810 	

SELECT country_id, region_id
FROM countries
ORDER BY country_name DESC;

Question # 3101
    Question Detail 	จงแสดงชื่อเต็มของพนักงานและเงินคอมมิชชั่นสุทธิของพนักงานคนนั้น เรียงผลลัพธ์ด้วย Net Commission จากมากไปน้อย (แสดงผลลัพธ์พนักงานทุกคนที่ได้รับและไม่ได้รับค่าคอมมิชชั่น)
หมายเหตุ ชื่อเต็มคือ ชื่อจริงและนามสกุลคั่นด้วย whitespace และตั้งชื่อคอลัมน์ว่า Employee name 
เงินคอมมิชชั่นสุทธิ คำนวณจาก ค่าคอมมิชชั่นคูณเงินเดือนของพนักงานคนนั้น และตั้งชื่อคอลัมน์ว่า Net Commission 
ตัวอย่างบางส่วนจากคำตอบ
Employee name 	Net Commission
 John Russell 	 5600.0000
 Karen Partners 	 4050.0000
 Alberto Errazuriz 	 3600.0000
    User Answer #811816 	

SELECT CONCAT(first_name, ' ', last_name) AS `Employee name`, salary * commission_pct AS `Net Commission`
FROM employees
ORDER BY `Net Commission` DESC;

Question # 3102
    Question Detail 	จงแสดงข้อมูลงานทั้งหมดในตาราง และค่าบ่งชี้เงินเดือนของแต่ละงาน
หมายเหตุ ค่าบ่งชี้เงินเดือนคำนวณจากเงินเดือนสูงสุดลบเงินเดือนต่ำสุด หารด้วยค่าน้ำหนัก 1.25 และตั้งชื่อคอลัมน์ว่า index of salary
*ตัวอย่างบางส่วนจากคำตอบ
 job_id 	 job_title 	 min_salary 	 max_salary 	 index of salary
 AC_ACCOUNT 	Public Accountant 	 4200 	 9000 	 3840.0000
 AC_MGR 	Accounting Manager 	 8200 	 16000 	 6240.0000
 AD_ASST 	Administration Assistant 	 3000 	 6000 	 2400.0000
    User Answer #811817 	

SELECT job_id, job_title, min_salary, max_salary, (max_salary - min_salary) / 1.25 AS `index of salary`
FROM jobs;

Question # 3103
    Question Detail 	จงแสดงรหัสงานของพนักงานจากตารางพนักงาน โดยไม่แสดงแถวที่มีข้อมูลซ้ำ
    User Answer #811818 	

SELECT DISTINCT job_id
FROM employees;

Question # 3104
    Question Detail 	เขียน SQL statement แสดงข้อมูลแผนกทั้งหมด เรียงผลลัพธ์ด้วยรหัสที่ตั้งจากน้อยไปมาก และแถวที่มีรหัสที่ตั้งเหมือนกันให้เรียงผลลัพธ์ด้วยรหัสผู้จัดการจากน้อยไปมาก
    User Answer #811819 	

SELECT *
FROM departments
ORDER BY location_id ASC, manager_id ASC;

Question # 3105
    Question Detail 	

จงแสดงข้อมูลรายละเอียดโดยย่อของพนักงาน โดยหาจากชื่อจริง คั่นด้วย white space ตามหลังด้วยนามสกุล และ white space วงเล็บเปิด อีเมล วงเล็บปิด white space ตามด้วยคำว่า is white space และลงท้ายด้วยชื่อตำแหน่งงานของพนักงานคนนั้น เช่น Joe Joewa (jjoe) is AD_VP และตั้งชื่อคอลัมน์ว่า short description
*ตัวย่างบางส่วนจากคำตอบ
short description
 Steven King (SKING) is AD_PRES
 Neena Kochhar (NKOCHHAR) is AD_VP
    User Answer #811820 	

SELECT CONCAT(first_name, ' ', last_name, ' ', '(', email, ')', ' ', 'is', ' ', job_id) AS `short description`
FROM employees;

