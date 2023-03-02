"use strict";
exports.__esModule = true;
exports.Animal = void 0;
var Animal = /** @class */ (function () {
    function Animal(food, location) {
        this.food = food;
        this.location = location;
    }
    Animal.prototype.makeNoise = function () { };
    Animal.prototype.eat = function () { };
    Animal.prototype.sleep = function () { };
    return Animal;
}());
exports.Animal = Animal;
