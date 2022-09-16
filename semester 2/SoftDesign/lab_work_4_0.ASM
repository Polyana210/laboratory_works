format PE console
entry start
 
include 'WIN32A.INC'
 
section '.data' data readable writeable
p db 'pause',0
ru db 'Russian',0
fmat db '%d',9,0
smat db '%d',0
m1 db 'Find the sum of the last L of positive elements in an array of A=(a [i]). Baselines should be size 4 bytes.',13,10,0
m2 db 13,10,'Result =',0
m3 db 'Input l:',0
 
a dd -3, 5, -67, 83, 54, -98, 45, 23, -6, 7, 789
 
l db 0
 
section '.code' code readable executable
start:
  cinvoke setlocale,0,ru
  cinvoke printf,m1
  cinvoke printf,m3
  cinvoke scanf, smat,l
 ; cinvoke scanf, smat,m3
  ;****************************************
  mov esi,a
  mov ecx,10
aga:
  mov eax,[esi]
  push ecx
  cinvoke printf,fmat,eax
  pop ecx
  add esi,4
  loop aga
  ;****************************************
  cinvoke printf,m2
   mov ecx,10
   xor eax,eax
   mov al, [l]
 
dec al
 
   sub ecx, eax
   shl eax, 2
   mov esi, a
   add esi, eax ; esi  &a[l]
   xor ebx, ebx
ugu:
  lodsd
  test eax, 8000h ; if(a[i]>0)
  jnz no
  add ebx, eax
no:
  loop ugu
done:
  ;****************************************
  cinvoke printf,fmat,ebx
  cinvoke system,p
  invoke ExitProcess,0
 
 
section '.idata' import data readable
 
library kernel,'kernel32.dll',\
        msvcrt,'msvcrt.dll'
 
import kernel,\
       ExitProcess,'ExitProcess'
 
import msvcrt,\
       setlocale,'setlocale',\
       printf,'printf',\
       scanf,'scanf',\
       system,'system'