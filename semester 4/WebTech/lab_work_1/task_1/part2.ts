/*Дан массив целых чисел. Найти наибольшую сумму подряд идущих элементов. 
(Например, [1, 0, -4, 5, 6, -7,-2, 3, 8] -> максимальная сумма: 13.*/

var array: number[] = [1, 0, -4, 5, 6, -7,-2, 3, 8];

var max_sum:number=array[0];
var sum:number=0;
for (let i in array){
  sum+=array[i];
  max_sum = Math.max(max_sum, sum);
  sum = Math.max(sum, 0);
}
console.log('Maximum sum:', max_sum);