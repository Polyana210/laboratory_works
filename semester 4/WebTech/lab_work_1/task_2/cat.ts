import { Animal } from './Animal';
class Cat extends Animal{
  food: string;
  location: string;
  cat_name: string;
  constructor(food: string, location: string) {
    super(food, location);
  }
  makeNoise() {
    console.log('Cat says: "Meow-meow!"');
  }

  eat() {
    console.log(`Cat eats ${this.food}`);
  }

  sleep() {
    console.log('Cat is sleeping');
  }
}

export {Cat}