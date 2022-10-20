/* Написать функцию, принимающую в аргументах массив и возвращающую новый массив,
 в котором отсортированы все нечетные числа по возрастанию, четные числа по убыванию, 
 но при этом сами чётные и нечетные числа остаются на своих местах. 
 ([7, 3, 4, 9, 5, 2, 17] -> [3, 5, 4, 7, 9, 2, 17]).*/
 function compareNumbers(a, b) {
  return a - b;
 }

 function task(array){
  result = [];
  even = [];
  not_even =[];
 for (let i in array){
    if (array[i]%2==0) even.push(array[i]);
    else not_even.push(array[i]);
  }
   even.sort(compareNumbers); 
  not_even.sort(compareNumbers);
  for (let i in array){
    if (array[i]%2==0) result.push(even.pop());
    else result.push(not_even.shift());
  }
  return result;
 }

var array = [7, 3, 4, 9, 5, 2, 17];
console.log(task(array));