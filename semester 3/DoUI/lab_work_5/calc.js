const digit = ['0','1', '2', '3', '4', '5','6','7','8','9','.']
const action = ['-', '+', 'X', '/', '%']
const out= document.querySelector('.calc-screen p')

var Calc = function (){};

Calc.prototype ={
  a : '',
  b : '',
  sign : '',
  finish : false,
  clearAll : function(){
  this.a = '';
  this.b = '';
  this.finish = false;
  out.textContent = 0;
  location.reload(true);
},

 btn_off : function(){
  this.a = '';
  this.b = '';
  this.finish = false;
  out.textContent = '';
},

 root : function(){
  console.log(this.a);
  this.a = Math.sqrt(this.a);
  this.finish = true;
  console.log("sqrt ", this.a);
  calc.check_a();
  out.textContent = this.a;
}, 

 division_one : function(){
  if (1/this.a==Infinity){
    out.textContent = 'Ошибка';
    this.a ='';
    this.b ='';
    this.sign = '';
    return;
  }
  let b = 1/parseFloat(this.a);
  console.log(this.a);
  this.a = b;
  this.finish = true;
  calc.check_a();
  out.textContent = this.a;
 },
 plus: function(){
  this.a=(+this.a) +(+this.b);
 },

 minus: function(){
  this.a=this.a -this.b;
 },

 myltiply: function(){
  this.a=this.a * this.b;
 },

 division: function(){
  if (this.a/this.b==Infinity){
    out.textContent = 'Ошибка';
    this.a ='';
    this.b ='';
    this.sign = '';
    return;
  }
  this.a = this.a/this.b;
 },

 plus_minus: function(){
   this.a = this.a *(-1);
   console.log(this.a)
   out.textContent = this.a;
 },

 percent: function(){
  this.a = this.a *this.b/100;
  console.log(this.a)
  out.textContent = this.a;
},
 mrc1:  function(){
  this.a = this.a.slice(0, -1);
  out.textContent = this.a;
},

mrc2:  function(){
  this.b = this.b.slice(0, -1);
  out.textContent = this.b;
},
check_a: function(){
  if (String(this.a)[0]=="-"){if (String(this.a).length>9){
    this.a = String(this.a).substr(0,9);}}
  else if (String(this.a).length>8){
    this.a = String(this.a).substr(0,8);
  }
},
check_b: function(){
  if (String(this.b)[0]=="-"){if (String(this.b).length>9){
    this.b = String(this.b).substr(0,9);}}
  else if (String(this.b).length>8){
    this.b = String(this.b).substr(0,8);
  }
}
}

let calc = new Calc()
document.querySelector('.buttons').onclick = (event) => {
  if(!event.target.classList.contains('btn')) return;

  if(event.target.classList.contains('ac')){calc.clearAll(); return;}
  if(event.target.classList.contains('sqrt')){calc.root(); return;}
  if(event.target.classList.contains('division_one')){calc.division_one(); return;}
  if(event.target.classList.contains('off')){ calc.btn_off(); return;}
  if(event.target.classList.contains('plus-minus')){ calc.plus_minus(); return;}
  if (calc.sign === "") if(event.target.classList.contains('mrc')){ calc.mrc1(); return;}
  if (calc.sign !== "") if(event.target.classList.contains('mrc')){ calc.mrc2(); return;}

  out.textContent = '';
  // получаем кнопку
  const key = event.target.textContent;
  if (digit.includes(key)){
    if (calc.b ==='' && calc.sign === ""){
    calc.a +=key;
    console.log(calc.a, calc.b, calc.sign);
    calc.check_a();
    out.textContent = calc.a;}
    else if (calc.a!=='' && calc.b!=='' && calc.finish){
       calc.b = key;
       calc.finish = false;
       out.textContent = calc.b;
    }else{
      calc.b+= key;
      calc.check_b();
      out.textContent = calc.b;
    }
    console.log("a",calc.a, 'b',calc.b, 's',calc.sign);
    return;
  }
  if (action.includes(key)){
    calc.sign = key;
    out.textContent = calc.sign;
    console.log("a",calc.a, 'b',calc.b, 's',calc.sign);
    return;
  }
  if (key === '='){
    if (calc.b===''){
      calc.b=calc.a;
    }
    switch(calc.sign){
      case '+':
        calc.plus();
        break;
      case '-':
        calc.minus();
        break;
      case 'X':
        calc.myltiply();
        break;
      case '/':
        calc.division();
        break;
      case '%':
        calc.percent();
        break;
    }
    calc.finish = true;
    calc.check_a();
    out.textContent = calc.a;
    console.log("a",calc.a, 'b',calc.b, 's',calc.sign);
  }
}