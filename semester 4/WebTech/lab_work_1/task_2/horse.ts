import { Animal } from './Animal';
class Horse extends Animal{
  food: string;
  location: string;
  horse_name: string;
  constructor(food: string, location: string) {
    super(food, location);
  }
  makeNoise() {
    console.log('Horse says: "Neigh-neigh!"');
  }

  eat() {
    console.log(`Horse eats ${this.food}`);
  }

  sleep() {
    console.log('Horse is sleeping');
  }
}

export {Horse}