/*Написать функцию, принимающую в аргументах две строки и возвращающую true, 
если эти строки состоят из идентичных букв и false в противном случае.*/

function compare(str1, str2){
  letters_str_1 = [];
  letters_str_2 = [];
  for (let i in str1){
    if (!letters_str_1.includes(str1[i]))  letters_str_1.push(str1[i]);
  }
  for (let i in str2){
    if (!letters_str_2.includes(str2[i]))  letters_str_2.push(str2[i]);
  }
  letters_str_1.sort();
  letters_str_2.sort();
  for (let i in letters_str_1){
    if (letters_str_1[i]!==letters_str_2[i]) return false;
  }
  return true;  
}

str1 = "hello"
str2 = "ole"
console.log(compare(str1, str2));