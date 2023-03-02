const IsInteger = (target: any, propertyKey: string) => {
  let value: number;

  Object.defineProperty(target, propertyKey, {
    set: (newVal: number) => {
      if (!Number.isInteger(newVal)) throw new Error(`The number must be an integer! [Given value: ${newVal}]`);

      value = newVal;
    },
    get: () => value,
  });
};

const NotNaNResult = (
  target: any,
  propertyKey: string,
  descriptor: PropertyDescriptor,
) => {
  const originalMethod = descriptor.value;
  // eslint-disable-next-line no-param-reassign
  descriptor.value = function (...args: any) {
    const result = originalMethod.apply(this, args);

    if (!result) {
      throw new Error('Value must not be negative!');
    }

    return result;
  };
};

class Integer {
  @IsInteger
    value: number;

  constructor(value: number) {
    this.value = value;
  }

  @NotNaNResult
  getSquareRoot() {
    return Math.sqrt(this.value);
  }
}


  const integer = new Integer(-3);
  console.log('Value:', integer.value);
  console.log('Square root:', integer.getSquareRoot());
