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
Object.defineProperty(exports, "__esModule", { value: true });
require("reflect-metadata");
var Roles;
(function (Roles) {
    Roles["Admin"] = "Admin";
    Roles["Moderator"] = "Moderator";
})(Roles || (Roles = {}));
const definedRoles = Symbol('ro');
// eslint-disable-next-line @typescript-eslint/ban-types
const WithRoles = (constructor) => {
    const newClass = class extends constructor {
        constructor(...args) {
            super(...args);
            const roles = Reflect.getMetadata(definedRoles, newClass.prototype);
            if (roles) {
                Reflect.defineMetadata(definedRoles, Object.assign(Object.assign({}, roles), { [args[0]]: args[1] }), newClass.prototype);
            }
            else {
                Reflect.defineMetadata(definedRoles, { [args[0]]: args[1] }, newClass.prototype);
            }
        }
    };
    return newClass;
};
const RolesGuard = (role) => (target, propertyKey, descriptor) => {
    const originalMethod = descriptor.value;
    // eslint-disable-next-line no-param-reassign
    descriptor.value = function (...args) {
        const result = originalMethod.apply(this, args);
        const roles = Reflect.getMetadata(definedRoles, Object.getPrototypeOf(this));
        if (!roles[this.nickname] || (role !== roles[this.nickname] && role)) {
            throw new Error(`Permission denied! Nickname: ${this.nickname}`);
        }
        return result;
    };
};
let User = class User {
    constructor(nickname, role) {
        this.nickname = nickname;
        this.role = role;
    }
    methodWithSuperAccess() {
        console.log('I can do everything');
    }
    methodWithoutSuperAccess() {
        console.log('I can\'t do everything');
    }
};
__decorate([
    RolesGuard(Roles.Admin),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], User.prototype, "methodWithSuperAccess", null);
__decorate([
    RolesGuard(),
    __metadata("design:type", Function),
    __metadata("design:paramtypes", []),
    __metadata("design:returntype", void 0)
], User.prototype, "methodWithoutSuperAccess", null);
User = __decorate([
    WithRoles,
    __metadata("design:paramtypes", [String, String])
], User);
const admin = new User('Dmitry', Roles.Admin);
const moderator = new User('Ivan', Roles.Moderator);
const user = new User('Mikita');
admin.methodWithSuperAccess();
moderator.methodWithoutSuperAccess();
user.methodWithoutSuperAccess();
