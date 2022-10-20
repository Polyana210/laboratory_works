/*Напишите функцию, которая будет проходить через массив целых чисел
 и выводить индекс каждого элемента с задержкой в 3 секунды.*/
 function task(arr){
  for(let i=0; i < arr.length; i++) {
    setTimeout(function(){
        console.log(i);
    }, i*3000);
 }
}
const arr = [1,3,4,56,7,8,54];
task(arr);
