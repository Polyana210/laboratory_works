; ѕример программы на ассемблере с вводом и выводом чисел
; ѕрограмма считывает число и выводит число на 1 больше.
; ѕреобразование строки в число и обратно производитс€
; средствами библиотеки MSVCRT.DLL -- Microsoft Visual C++ Runtime.
; Ёта библиотека поставл€етс€ вместе с Microsoft Visual Studio и
; Microsoft Visual C++ Redistributable.

format PE console NX
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable

hInput dd ?
hOutput dd ?
dwNumber dd ?
buf db ?
; резервируем место под переменную из тридцати элементов типа byte
szNum rb 30
; определ€ем константу со значением равным размеру предыдущей переменной
szNum.sizeof = $-szNum

section '.text' code readable executable

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; вводим строку    
    push 0
    push dwNumber
    push szNum.sizeof
    push szNum
    push ptr hInput
    call ptr ReadConsole

    ; замен€ем предпоследний символ стоки на \0 (символ с кодом 0)
    mov EBX, ptr dwNumber
    mov byte ptr szNum + EBX - 2, 0
    
        ; преобразуем строку в число
        push szNum
    call ptr atoi
    add ESP, 4
        
        ; увеличиваем число на 1
    inc EAX

    ; получаем представление числа в дес€тичной система счислени€
    push 10
    push szNum
    push EAX
    call ptr itoa
    add ESP, 3 * 4 ; удал€ем параметы (три параметра по 4 байта каждый)

    ; вычисл€ем длину полученной строки
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