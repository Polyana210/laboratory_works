"use strict";
exports.__esModule = true;
var Cat_1 = require("./Cat");
var Dog_1 = require("./Dog");
var Horse_1 = require("./Horse");
var Veterinarian = /** @class */ (function () {
    function Veterinarian() {
    }
    Veterinarian.prototype.treatAnimal = function (animal) {
        console.log("Food of the animal: ".concat(animal.food, "\nLocation of the animal: ").concat(animal.location));
    };
    return Veterinarian;
}());
var vet = new Veterinarian();
var Animals = [
    new Dog_1.Dog('Meat', 'Russia'),
    new Cat_1.Cat('Fish', 'Belarus'),
    new Horse_1.Horse('Hay', 'Great Britain')
];
Animals.forEach(function (animal) {
    vet.treatAnimal(animal);
});
