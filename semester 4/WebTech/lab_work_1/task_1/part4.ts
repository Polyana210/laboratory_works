/*Дано предложение на русском языке. Определить, является ли оно панграммой.*/
var letters: string[]= ['а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к',
                        'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц',
                        'ч', 'ш', 'щ', 'ы', 'ь', 'э', 'ю', 'я'];

var sentence:string = 'В чащах юга жил бы цитрус? Да, но фальшивый экземпляр!';
sentence = sentence.toLowerCase();
var pangramma: boolean = true;
for (let i in letters){
  if (sentence.indexOf(letters[i])==-1){
    pangramma=false;
    break;
  }
}

if (pangramma){
   console.log('Sentence is a pangram!');
}else console.log('Sentence is NOT a pangram!')
