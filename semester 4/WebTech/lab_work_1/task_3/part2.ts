import 'reflect-metadata';

enum Roles {
  Admin = 'Admin',
  Moderator = 'Moderator',
}

const definedRoles = Symbol('ro');
// eslint-disable-next-line @typescript-eslint/ban-types
const WithRoles = <T extends { new (...args: any[]): {} }>(constructor: T) => {
  const newClass = class extends constructor {
    constructor(...args: Array<any>) {
      super(...args);

      const roles = Reflect.getMetadata(definedRoles, newClass.prototype);
      if (roles) {
        Reflect.defineMetadata(definedRoles, { ...roles, [args[0]]: args[1] }, newClass.prototype);
      } else {
        Reflect.defineMetadata(definedRoles, { [args[0]]: args[1] }, newClass.prototype);
      }
    }
  };

  return newClass;
};

const RolesGuard = (role?: Roles) => (
  target: any,
  propertyKey: string,
  descriptor: any,
) => {
  const originalMethod = descriptor.value;
  // eslint-disable-next-line no-param-reassign
  descriptor.value = function (...args: any) {
    const result = originalMethod.apply(this, args);

    const roles = Reflect.getMetadata(definedRoles, Object.getPrototypeOf(this));

    if (!roles[this.nickname] || (role !== roles[this.nickname] && role)) {
      throw new Error(`Permission denied! Nickname: ${this.nickname}`);
    }

    return result;
  };
};

@WithRoles
class User {
  constructor(private nickname: string, private role?: Roles) {}

  @RolesGuard(Roles.Admin)
  methodWithSuperAccess() {
    console.log('I can do everything');
  }

  @RolesGuard()
  methodWithoutSuperAccess() {
    console.log('I can\'t do everything');
  }
}


  const admin = new User('Dmitry', Roles.Admin);
  const moderator = new User('Ivan', Roles.Moderator);
  const user = new User('Mikita');

  admin.methodWithSuperAccess();
  moderator.methodWithoutSuperAccess();
  user.methodWithoutSuperAccess();

