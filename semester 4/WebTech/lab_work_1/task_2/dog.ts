import { Animal } from './Animal';
class Dog extends Animal{
  food: string;
  location: string;
  dog_name: string;
  constructor(food: string, location: string) {
    super(food, location);
  }
  makeNoise() {
    console.log('Dog says: "Woof-woof!"');
  }

  eat() {
    console.log(`Dog eats ${this.food}`);
  }

  sleep() {
    console.log('Dog is sleeping');
  }
}

export {Dog}