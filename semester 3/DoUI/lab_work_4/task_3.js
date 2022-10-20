/*Напишите функцию, которая на вход получает произвольное количество аргументов и возвращает массив, 
состоящих только из уникальных значений параметров функции.*/
function task(){
  result =[];
  for (let i = 0; i < arguments.length; i++){
    if (!result.includes(arguments[i])) result.push(arguments[i])
  }
 return result;
}
console.log(task(1, 2, 2, 'hi', 'hello', 'hi'));