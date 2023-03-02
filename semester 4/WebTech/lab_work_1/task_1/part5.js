/*Дана дата и число K. Определить день недели, который будет через K дней от данной даты.*/
var days = ["воскресенье", "понедельник", "вторник",
    "среда", "четверг", "пятница", "суббота"];
var date = new Date('03.02.2023');
var num_days = 730;
var tmpDate = new Date();
tmpDate.setDate(tmpDate.getDate() + num_days);
var n = tmpDate.getDay();
console.log(days[n]);
