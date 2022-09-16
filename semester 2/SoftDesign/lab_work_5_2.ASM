format PE console NX
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable

hInput dd ?
hOutput dd ?
dwNumber dd ?
buf db ?
vvodx db "Vvedite x="
vvody db "Vvedite y="
ost db " ostatok  "
Z db "Z = "
x dd ?          ; х
y dd ?          ; у
pr dd ?         ; x*y
sum dd ?        ; x+y
max1 dd ?       ; max(xy, x+y)
max2 dd ?       ; max(xy%10, (x+y)%10)
pr1 dd ?        ; xy%10
sum1 dd ?       ; x+y)%10
max3 dd ?       ; max(|x|,|y|)
fx dd ?         ; |x|
fy dd ?         ; |y|
min dd ?        ; min(max1, max2)
znam dd ?       ; max3 +1
z dd ?          ; итог
ostatok dd ?

; резервируем место под переменную из тридцати элементов типа byte
szNum rb 30
; определяем константу со значением равным размеру предыдущей переменной
szNum.sizeof = $-szNum

section '.text' code readable executable

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

 ;приглашение на ввод х
    push 0
    push dwNumber
    push 10
    push vvodx
    push [hOutput]
    call [WriteConsole]

 ; вводим строку х
    push 0
    push dwNumber
    push szNum.sizeof
    push szNum
    push ptr hInput
    call ptr ReadConsole

 ; заменяем предпоследний символ строки х  на \0 (символ с кодом 0)
    mov EBX, ptr dwNumber
    mov byte ptr szNum + EBX - 2, 0
    
 ; преобразуем строку х в число
    push szNum
    call ptr atoi
    add ESP, 4
        
 ; иницализируем x
    mov [x], EAX

 ; приглашение на ввод у
    push 0
    push dwNumber
    push 10
    push vvody
    push [hOutput]
    call [WriteConsole]

 ; вводим строку у
    push 0
    push dwNumber
    push szNum.sizeof
    push szNum
    push ptr hInput
    call ptr ReadConsole

 ; заменяем предпоследний символ строки у на \0 (символ с кодом 0)
    mov EBX, ptr dwNumber
    mov byte ptr szNum + EBX - 2, 0
    
 ; преобразуем строку у в число
    push szNum
    call ptr atoi
    add ESP, 4
 ; иницализируем у
    mov [y], EAX

 ;подсчет x+y
    mov EDX, [x]
    mov ECX, [y]
    add EDX, ECX
    mov [sum], EDX

 ;подсчет x*y
    mov EDX, [x]
    mov ECX, [y]
    imul EDX, ECX
    mov [pr], EDX
    mov EAX,[pr]


 ;подсчет max1
    mov EDX, [pr]
    mov [max1], EDX
    mov ECX, [sum]
    cmp EDX, ECX
    JLe f
    jmp default
 f:
    mov [max1], ECX
 default:


 ;подсчет ху%10
    mov EBP, 10
    mov EAX, [pr]
    mov EDX, 0
    div EBP
    mov [pr1], EDX

 ;подсчет (х+у)%10
    mov EBP, 10
    mov EDX, 0
    mov EAX, [sum]
    div EBP
    mov [sum1], EDX

 ;подсчет max2
    mov EDX, [pr1]
    mov [max2], EDX
    mov ECX, [sum1]
    cmp EDX, ECX
    JLe f2
    jmp default2
 f2:
    mov [max2], ECX
 default2:

 ;подсчет |x|
    mov EAX, [x]
    test  EAX, EAX
    jns   L2
    neg   eax
 L2:


 ;подсчет |y|
    mov EAX, [y]
    test  EAX, EAX
    jns   L3
    neg   eax
 L3:
    mov [fy], EAX
    mov EAX, [fy]

 ;подсчет max3
   mov EDX, [fx]
   mov [max3], EDX
   mov ECX, [fy]
   cmp EDX, ECX
   JLe f3
   jmp default3
 f3:
   mov [max3], ECX
 default3:

 ;подсчет знаменателя
   mov EDX, [max3]
   add EDX, 1
   mov [znam], EDX


 ;подсчет min
   mov EDX, [max2]
   mov [min], EDX
   mov ECX, [max1]
   cmp ECX, EDX
   JLe f4
   jmp default4
 f4:
   mov [min], ECX
 default4:

 ; итоговый подсчет
    mov EBP, [znam]
    mov EAX, [min]
    mov EDX, 0
    div EBP
    mov [ostatok], EDX
    mov [z], EAX

 ; выводим строку
    push 0
    push dwNumber
    push 4
    push Z
    push [hOutput]
    call [WriteConsole]
    mov EAX, [z]

 ; получаем представление числа в десятичной система счисления
    push 10
    push szNum
    push EAX
    call ptr itoa
    add ESP, 3 * 4 ; удаляем параметы (три параметра по 4 байта каждый)

 ; вычисляем длину полученной строки
    push EAX
    call ptr lstrlen

 ; выводим строковое представление числа
    push 0
    push dwNumber
    push EAX
    push szNum
    push ptr hOutput
    call ptr WriteConsole

 ; выводим остаток
    push 0
    push dwNumber
    push 9
    push ost
    push [hOutput]
    call [WriteConsole]
    mov EAX, [ostatok]

 ; получаем представление числа в десятичной система счисления
    push 10
    push szNum
    push EAX
    call ptr itoa
    add ESP, 3 * 4 ; удаляем параметы (три параметра по 4 байта каждый)

 ; вычисляем длину полученной строки
    push EAX
    call ptr lstrlen

 ; выводим строковое представление числа
    push 0
    push dwNumber
    push EAX
    push szNum
    push ptr hOutput
    call ptr WriteConsole

    push 0
    push dwNumber
    push 1
    push buf
    push [hInput]
    call [ReadConsole]

    push 0
    call [ExitProcess]

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL', \
    msvcrt, 'MSVCRT.DLL'

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA'

import msvcrt, \
    atoi, 'atoi',\
    itoa, '_itoa'

section '.reloc' fixups data readable discardable