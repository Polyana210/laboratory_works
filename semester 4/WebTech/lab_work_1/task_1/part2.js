/*Дан массив целых чисел. Найти наибольшую сумму подряд идущих элементов.
(Например, [1, 0, -4, 5, 6, -7,-2, 3, 8] -> максимальная сумма: 13.*/
var array = [1, 0, -4, 5, 6, -7, -5, 3, 9];
var max_sum = array[0];
var sum = 0;
for (var i in array) {
    sum += array[i];
    max_sum = Math.max(max_sum, sum);
    sum = Math.max(sum, 0);
}
console.log('Maximum sum:', max_sum);
