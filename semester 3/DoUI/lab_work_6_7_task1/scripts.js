// Create a "close" button and append it to each list item
var myNodelist = document.getElementsByTagName("LI");
var i;
for (i = 0; i < myNodelist.length; i++) {
  var span = document.createElement("SPAN");
  var txt = document.createTextNode("✖");
  span.className = "close";
  span.appendChild(txt);
  myNodelist[i].appendChild(span);

  var span1 = document.createElement("SPAN1");
  var txt1 = document.createTextNode("✎");
  span1.className = "redact";
  span1.appendChild(txt1);
  myNodelist[i].appendChild(span1);
}


// Click on a close button to hide the current list item
var close = document.getElementsByClassName("close");
var i;
for (i = 0; i < close.length; i++) {
  close[i].onclick = function() {
    var div = this.parentElement;
    div.style.display = "none";
  }
}


// Click on a redact button to hide the current list item
var redact = document.getElementsByClassName("redact");
var i;
for (i = 0; i < redact.length; i++) {
  let flag = false;
  redact[i].onclick = function() {
    if (flag===false){
    var div = this.parentElement; 
    this.textContent = "✔"; 
    div.setAttribute('contentEditable', true);
    div.focus();
    flag = true;}
    else {
    var div = this.parentElement;
    
    div.removeAttribute('contentEditable');
    this.textContent = "✎"; 
    flag = false;
    }
  }
}

// Add a "checked" symbol when clicking on a list item
var list = document.querySelector('ul');
list.addEventListener('click', function(ev) {
  if (ev.target.tagName === 'LI') {
    ev.target.classList.toggle('checked');
  }
}, false);

document.addEventListener("keydown", function(event) {
  if (event.altKey && (event.key === 'x' || event.key === 'X'))
  {
      for (i = 0; i < close.length; i++) {
        if ( close[i].parentElement.style.display != "none"){
          var div = close[i].parentElement;
          div.style.display = "none";
          console.log(i);break;}
      }
      event.preventDefault();
  }
});
let flag = false;
document.addEventListener("keydown", function(event) {
  i = 0;

  if (event.altKey && (event.key === 'z' || event.key === 'Z'))
  { 
        if (flag===false){
        var div = redact[redact.length-1].parentElement;
        div.setAttribute('contentEditable', true);
        div.focus();
        flag = true;}
        else {
        var div = redact[redact.length-1].parentElement;
        div.removeAttribute('contentEditable'); 
        flag = false;
        }
    
      event.preventDefault();
  }
});

// Create a new list item when clicking on the "Add" button
function newElement() {
  var li = document.createElement("li");
  var inputValue = document.getElementById("myInput").value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  li.classList.add("tasks__item");
  if (inputValue === '') {
    alert("You must write something!");
  } else {
    document.getElementById("myUL").appendChild(li);
  }
  document.getElementById("myInput").value = "";

  var span = document.createElement("SPAN");
  var txt = document.createTextNode("✖");
  span.className = "close";
  span.appendChild(txt);
  li.appendChild(span);

  var span1 = document.createElement("SPAN1");
  var txt1 = document.createTextNode("✎");
  span1.className = "redact";
  span1.appendChild(txt1);
  li.appendChild(span1);

  for (i = 0; i < close.length; i++) {
    close[i].onclick = function() {
      var div = this.parentElement;
      div.style.display = "none";
    }
  }

  for (i = 0; i < redact.length; i++) {
    let flag = false;
    redact[i].onclick = function() {
      if (flag===false){
      var div = this.parentElement; 
      this.textContent = "✔"; 
      div.setAttribute('contentEditable', true);
      div.focus();
      flag = true;}
      else {
      var div = this.parentElement;
      
      div.removeAttribute('contentEditable');
      this.textContent = "✎"; 
      flag = false;
      }
    }
  }

  
const tasksListElement = document.querySelector(`.tasks__list`);
const taskElements = tasksListElement.querySelectorAll(`.tasks__item`);

for (const task of taskElements) {
  task.draggable = true;
}

tasksListElement.addEventListener(`dragstart`, (evt) => {
  evt.target.classList.add(`selected`);
});

tasksListElement.addEventListener(`dragend`, (evt) => {
  evt.target.classList.remove(`selected`);
});

const getNextElement = (cursorPosition, currentElement) => {
  const currentElementCoord = currentElement.getBoundingClientRect();
  const currentElementCenter = currentElementCoord.y + currentElementCoord.height / 2;
  
  const nextElement = (cursorPosition < currentElementCenter) ?
    currentElement :
    currentElement.nextElementSibling;
  
  return nextElement;
};

tasksListElement.addEventListener(`dragover`, (evt) => {
  evt.preventDefault();
  
  const activeElement = tasksListElement.querySelector(`.selected`);
  const currentElement = evt.target;
  const isMoveable = activeElement !== currentElement &&
    currentElement.classList.contains(`tasks__item`);
    
  if (!isMoveable) {
    return;
  }
  
  const nextElement = getNextElement(evt.clientY, currentElement);
  
  if (
    nextElement && 
    activeElement === nextElement.previousElementSibling ||
    activeElement === nextElement
  ) {
    return;
  }
		
	tasksListElement.insertBefore(activeElement, nextElement);
});
  
}

const tasksListElement = document.querySelector(`.tasks__list`);
const taskElements = tasksListElement.querySelectorAll(`.tasks__item`);

for (const task of taskElements) {
  task.draggable = true;
}

tasksListElement.addEventListener(`dragstart`, (evt) => {
  evt.target.classList.add(`selected`);
});

tasksListElement.addEventListener(`dragend`, (evt) => {
  evt.target.classList.remove(`selected`);
});

const getNextElement = (cursorPosition, currentElement) => {
  const currentElementCoord = currentElement.getBoundingClientRect();
  const currentElementCenter = currentElementCoord.y + currentElementCoord.height / 2;
  
  const nextElement = (cursorPosition < currentElementCenter) ?
    currentElement :
    currentElement.nextElementSibling;
  
  return nextElement;
};

tasksListElement.addEventListener(`dragover`, (evt) => {
  evt.preventDefault();
  
  const activeElement = tasksListElement.querySelector(`.selected`);
  const currentElement = evt.target;
  const isMoveable = activeElement !== currentElement &&
    currentElement.classList.contains(`tasks__item`);
    
  if (!isMoveable) {
    return;
  }
  
  const nextElement = getNextElement(evt.clientY, currentElement);
  
  if (
    nextElement && 
    activeElement === nextElement.previousElementSibling ||
    activeElement === nextElement
  ) {
    return;
  }
		
	tasksListElement.insertBefore(activeElement, nextElement);
});
