/*Дана дата и число K. Определить день недели, который будет через K дней от данной даты.*/

var days: string[] = ["воскресенье", "понедельник", "вторник",
                      "среда", "четверг", "пятница", "суббота"];

var date: Date = new Date('02.28.2023');
var num_days: number = 365;
var tmpDate: Date = new Date();
tmpDate.setDate(tmpDate.getDate() + num_days);
var n: number = tmpDate.getDay();
console.log(days[n]);
