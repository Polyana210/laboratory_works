/*Написать функцию, принимающая на вход массив дат и сортирующая их в порядке возрастания. */
function compareDates(date1, date2) {
  return new Date(date1).setHours(0, 0, 0, 0) - new Date(date2).setHours(0, 0, 0, 0);
 }

function task(array_dates){
  array_dates.sort(compareDates);
  return array_dates;
}


const dates = [
  new Date('2019-06-01'),
  new Date('2004-05-03'),
  new Date('2019-06-07'),
  new Date('2021-08-01')
];

task (dates);
for (let i in dates){
  console.log(dates[i]);
}
