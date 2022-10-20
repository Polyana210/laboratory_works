/*Реализовать функцию f: f(2, 3) -> 5 и f(2)(3) -> 5.*/
function f(a, b) {
  if (b !== undefined) {
    return a + b;
  } else {
  return function (b) {
    return a + b;
    }
  }
}

console.log(f(2)(3));
console.log(f(2, 3));