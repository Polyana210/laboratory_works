var list = document.querySelector('.rhombus');
var fl = true// red
var reds = 0;
var blues = 0;
var n11=true, n12=true, n13 =true, n14=true, n15=true, n16=true, n17=true, n18=true, n19=true;
var n21=true, n22=true, n23 =true, n24=true, n25=true, n26=true, n27=true, n28=true, n29=true;
var n31=true, n32=true, n33 =true, n34=true, n35=true, n36=true, n37=true, n38=true, n39=true;
var n41=true, n42=true, n43 =true, n44=true, n45=true, n46=true, n47=true, n48=true, n49=true;
var n51=true, n52=true, n53 =true, n54=true, n55=true, n56=true, n57=true, n58=true, n59=true;
var n61=true, n62=true, n63 =true, n64=true, n65=true, n66=true, n67=true, n68=true, n69=true;
var n71=true, n72=true, n73 =true, n74=true, n75=true, n76=true, n77=true, n78=true, n79=true;
var n81=true, n82=true, n83 =true, n84=true, n85=true, n86=true, n87=true, n88=true, n89=true;
var n91=true, n92=true, n93 =true, n94=true, n95=true, n96=true, n97=true, n98=true, n99=true;

function check24(){
  var el = document.getElementById('n24');
  if ((el.style.borderRight=='red' || el.style.borderRight=='blue') && (el.style.borderBottom=='red' || el.style.borderBottom=='blue')){
    n24 = false;
    if (fl===true){el.style.background = "red"; reds++;}
    else { el.style.background = "blue"; blues++;}
  }
}

function check33(){
  var el = document.getElementById('n33');
  if ((el.style.borderRight=='red' || el.style.borderRight=='blue') && (el.style.borderBottom=='red' || el.style.borderBottom=='blue')){
    n33 = false;
    if (fl===true){el.style.background = "red"; reds++;}
    else { el.style.background = "blue"; blues++;}
  }
}

function check42(){
  var el = document.getElementById('n42');
  if ((el.style.borderRight=='red' || el.style.borderRight=='blue') && (el.style.borderBottom=='red' || el.style.borderBottom=='blue')){
    n42 = false;
    if (fl===true){el.style.background = "red"; reds++;}
    else { el.style.background = "blue"; blues++;}
  }
}

list.addEventListener('click', function(ev) {
  if (ev.target.classList.contains('game')) {
  if(ev.target.classList.contains('top') && n15){
  var el = document.getElementById('n25');
  if (fl===true){
  ev.target.style.borderBottom = "2px solid red";
  ev.target.style.background = "red";
  fl = false;
  el.style.borderTop = "1px solid red";
  n15=false;
  reds++;
  } else {ev.target.style.borderBottom = "2px solid blue";
  ev.target.style.background = "blue";fl = true; console.log(fl);
  el.style.borderTop = "1px solid blue";
  n15=false;
  blues++;
  }
  }

  else{if(ev.target.classList.contains('bottom') && n95){
    var el = document.getElementById('n85');
    if (fl===true){
    ev.target.style.borderTop = "2px solid red";
    ev.target.style.background = "red";fl = false; console.log(fl);
    n95=false;
    el.style.borderBottom = "1px solid red";
    reds++;} else {ev.target.style.borderTop = "2px solid blue";
    ev.target.style.background = "blue";fl = true; console.log(fl);
    n95=false;
    el.style.borderBottom = "1px solid blue";
    blues++;}
    } else{

    if(ev.target.classList.contains('right') && n59){
    var el = document.getElementById('n58');
      if (fl===true){
      ev.target.style.borderLeft = "2px solid red";
      ev.target.style.background = "red";fl = false; console.log(fl);
      n59=false;
      el.style.borderRight = "1px solid red";
      reds++;
      } else {ev.target.style.borderLeft = "2px solid blue";
      ev.target.style.background = "blue";fl = true; console.log(fl);n59=false;
      el.style.borderRight = "1px solid blue";
      blues++;}
      } else{

      if(ev.target.classList.contains('n51') && n51){
        var el = document.getElementById('n52');    
        if (fl===true){
        ev.target.style.borderRight = "2px solid red";
        ev.target.style.background = "red";fl = false; console.log(fl);
        
      el.style.borderLeft = "1px solid red";
      n51=false;
      reds++;
        } else {ev.target.style.borderRight = "2px solid blue";
        ev.target.style.background = "blue";fl = true; console.log(fl);n51=false;
        blues++; 
        el.style.borderLeft = "1px solid blue";}
        }
        else{
          document.addEventListener("keydown", function(event) {
            if (event.key === 'A' || event.key === 'a'){
             

            document.addEventListener('keydown', function(event1){
              if (event1.code=='KeyZ') {
                
                if (fl==true){
                  ev.target.style.borderLeft = "2px solid red";
                  event.preventDefault();
                   fl=false;}
                else{
                  ev.target.style.borderLeft = "2px solid blue";
                  event.preventDefault();
                  fl=true;}
              }
              else if (event1.code=='KeyX'){
              alert('ОТМЕНИТЬ');}
            });

            } else if (event.key === 'W' || event.key === 'w'){
              if (fl==true){
                ev.target.style.borderTop = "2px solid red";
                 fl=false; return;}
              else{
                ev.target.style.borderTop = "2px solid blue";
                fl=true; return;}
            } else if (event.key === 'S' || event.key === 's'){
              if (fl==true){
                ev.target.style.borderBottom = "2px solid red";
                 fl=false;}
              else{
                ev.target.style.borderBottom = "2px solid blue";
                fl=true;}
            } else if (event.key === 'd' || event.key === 'D'){
              if (fl==true){
                ev.target.style.borderRight = "2px solid red";
                event.preventDefault();
                 fl=false;}
              else{
                ev.target.style.borderRight = "2px solid blue";
                event.preventDefault();
                fl=true;}
            } return;
          }); 





          
        }
        
        console.log(reds)
        console.log(blues)

      }
        }
      }
  }
}, false);

