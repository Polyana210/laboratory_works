import { Animal } from './Animal';
import { Cat } from './Cat';
import { Dog } from './Dog';
import { Horse } from './Horse';

class Veterinarian {
  treatAnimal(animal: Animal) {
    console.log(`Food of the animal: ${animal.food}\nLocation of the animal: ${animal.location}`);
  }
}

const vet = new Veterinarian();

const Animals: Array<Animal> = [
  new Dog('Meat', 'Russia'),
  new Cat('Fish', 'Belarus'),
  new Horse('Hay', 'Great Britain')  
];

Animals.forEach((animal) => {
  vet.treatAnimal(animal);
});