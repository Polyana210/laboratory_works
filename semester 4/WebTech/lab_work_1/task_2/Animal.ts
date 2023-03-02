class Animal{
  food:string;
  location:string;
  makeNoise(): void{}
  eat(): void{}
  sleep(): void{}
  constructor(food:string, location:string){
    this.food=food;
    this.location=location;
  }
}
 export {Animal}