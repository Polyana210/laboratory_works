"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
const IsInteger = (target, propertyKey) => {
    let value;
    Object.defineProperty(target, propertyKey, {
        set: (newVal) => {
            if (!Number.isInteger(newVal))
                throw new Error(`The number must be an integer! [Given value: ${newVal}]`);
            value = newVal;
        },
        get: () => value,
    });
};
const NotNaNResult = (target, propertyKey, descriptor) => {
    const originalMethod = descriptor.value;
    // eslint-disable-next-line no-param-reassign
    descriptor.value = function (...args) {
        const result = originalMethod.apply(this, args);
        if (!result) {
            throw new Error('Value must not be negative!');
        }
        return result;
    };
};
class Integer {
    constructor(value) {
        this.value = value;
    }
    getSquareRoot() {
        return Math.sqrt(this.value);
    }
}
__decorate([
    IsInteger,
    __metadata("design:type", Number)
], Integer.prototype, "value", void 0);
__decorate([
    NotNaNResult,
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], Integer.prototype, "getSquareRoot", null);
const integer = new Integer(-3);
console.log('Value:', integer.value);
console.log('Square root:', integer.getSquareRoot());
