/*Дано 3 массива. Найти элементы, которые встречаются в каких-либо 2 массивах, но их нету в 3 массиве.*/
var result = [];
var ar1 = [1, 2, 3, 'aaa', 'wd1'];
var ar2 = [3, 4, 'aaa', 'wd1', 'ssd'];
var ar3 = [2, 1, 'aaa', 'ssd'];
function check(arr1, arr2, arr3) {
    for (var i in arr1) {
        if ((arr2.indexOf(arr1[i]) !== -1 && arr3.indexOf(arr1[i]) == -1) || (arr3.indexOf(arr1[i]) !== -1 && arr2.indexOf(arr1[i]) == -1)) {
            if (result.indexOf(arr1[i]) == -1)
                result.push(arr1[i]);
        }
    }
}
check(ar1, ar2, ar3);
check(ar2, ar1, ar3);
console.log(result);
