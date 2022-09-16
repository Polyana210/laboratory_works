;На языке Ассемблера создать консольное приложение, которое считывает три введённых пользователем строки,
;усекает или дополняет пробелами каждую строку до 10 символов, после чего выводит текст в соответствии с заданием Вашего варианта.
format PE console NX
entry start
include 'WIN32A.INC'
section '.bss' data readable writeable
; объявление переменной для хранения дискриптора ввода
hInput dd ?
hOutput dd ?
dwNumber dd ?
buf db ?

hInpu dd ?
hOutpu dd ?
dwNumbe dd ?

S1 rb 40
S1.sizeof = $-S1
S2 rb 40
S2.sizeof = $-S2
S3 rb 40
S3.sizeof = $-S3


section '.data' data readable writeable

message db 'Vvedite stroku: '
sizeof.message = $ - message
stroka1 db  0xDC, 0xDC,0xDC, 0xDC, 0xDC, 0xDC,0xDC, 0xDC,0xDC, 0xDC, 0xDC, 0xDC, 13,10
stroka2 db  0xDD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDE, 13,10
stroka5 db  0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 13,10
stroka13 db 0xDF, 0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,0xDF,13,10
str1 db  0xDD
str2 db 0xDE, 13, 10

section '.text' code readable executable ; директива ассемблера: начало секции
    ; .text - имя секции, предназначенной для кода
    ; code - секция содержит код    ; readable - разрешено чтение содержимого секции
    ; executable - разрешено выполнение содержимого секции

start: ; точка входа (см entry)

 ;получить дискриптор ввода
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    
    ; получить дискриптор вывода
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX



    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInpu], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutpu], EAX

    push 0
    push dwNumber
    push sizeof.message
    push message
    push [hOutput]
    call [WriteConsole]

; вводим строку
    push 0
    push dwNumbe
    push S1.sizeof
    push S1
    push ptr hInpu
    call ptr ReadConsole

    push 0
    push dwNumber
    push sizeof.message
    push message
    push [hOutput]
    call [WriteConsole]

    push 0
    push dwNumbe
    push S2.sizeof
    push S2
    push ptr hInpu
    call ptr ReadConsole
       push 0
    push dwNumber
    push sizeof.message
    push message
    push [hOutput]
    call [WriteConsole]
    push 0
    push dwNumbe
    push S3.sizeof
    push S3
    push ptr hInpu
    call ptr ReadConsole

;вывести строку 1
    push 0
    push dwNumber
    push 14
    push stroka1
    push [hOutput]
    call [WriteConsole]

;вывести строку 2
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]

;вывести строку 3
    push 0
    push dwNumber
    push 1
    push str1
    push [hOutput]
    call [WriteConsole]

    mov ebx, S1
    mov eax,ebx 
    nextchar1:
    cmp byte[eax], 0
 
    jz finished
    inc eax
    jmp nextchar1
 
    finished:
    sub eax, ebx
    mov edx, eax
    mov byte [ EBX + EAX - 1 ], " "
    mov byte [ EBX + EAX - 2 ], " "

    push 0
    push dwNumbe
    push 10
    push S1
    push ptr hOutpu
    call ptr WriteConsole

    push 0
    push dwNumber
    push 3
    push str2
    push [hOutput]
    call [WriteConsole]

;вывести строку 4
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]

    ;вывести строку 5
    push 0
    push dwNumber
    push 14
    push stroka5
    push [hOutput]
    call [WriteConsole]

    ;вывести строку 6
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;вывести строку 7
     push 0
    push dwNumber
    push 1
    push str1
    push [hOutput]
    call [WriteConsole]

     mov ebx, S2
    mov eax,ebx 
    nextchar2:
    cmp byte[eax], 0
 
    jz finished2
    inc eax
    jmp nextchar2
 
    finished2:
    sub eax, ebx
    mov edx, eax
    mov byte [ EBX + EAX - 1 ], " "
    mov byte [ EBX + EAX - 2 ], " "

    push 0
    push dwNumbe
    push 10
    push S2
    push ptr hOutpu
    call ptr WriteConsole

        push 0
    push dwNumber
    push 3
    push str2
    push [hOutput]
    call [WriteConsole]
;вывести строку 8
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;вывести строку 9
    push 0
    push dwNumber
    push 14
    push stroka5
    push [hOutput]
    call [WriteConsole]

  ;вывести строку 10
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;вывести строку 11
      push 0
    push dwNumber
    push 1
    push str1
    push [hOutput]
    call [WriteConsole]

      mov ebx, S3
    mov eax,ebx 
    nextchar3:
    cmp byte[eax], 0
 
    jz finished3
    inc eax
    jmp nextchar3
 
    finished3:
    sub eax, ebx
    mov edx, eax
    mov byte [ EBX + EAX - 1 ], " "
    mov byte [ EBX + EAX - 2 ], " "

    push 0
    push dwNumbe
    push 10
    push S3
    push ptr hOutpu
    call ptr WriteConsole
        push 0
    push dwNumber
    push 3
    push str2
    push [hOutput]
    call [WriteConsole]
;вывести строку 12
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
    ;вывести строку 13
    push 0
    push dwNumber
    push 14
    push stroka13
    push [hOutput]
    call [WriteConsole]






    
    ; ввести один символ - используется для ожидания
    push 0
    push dwNumber       ; где сохранить количество введенных символов
    push 1              ; количество вводимых символов
    push buf            ; смещение (адрес), куда сохранять вводимые символы
    push [hInput]       ; где взять дискриптор файла (потока), откуда надо осуществить ввод
    call [ReadConsole]  ; косвенный вызов функции: адрес точки входа хранится в ReadConsole

    ; завершение программы
    push 0              ; код завершения программы: 0 - нет ошибок
    call [ExitProcess]  ; косвенный вызов функции: адрес точки входа хранится в ExitProcess

section '.idata' import data readable writeable ; директива ассемблера: начало секции
    ; .idata - имя секции, предназначенной для данных об импорте функций
    ; data - секция содержит данные
    ; readable - разрешено чтение содержимого секции
    ; writeable - разрешено изменение содержимого секции

library kernel32, 'KERNEL32.DLL' ; вызов макрокоманды: добавление библиотеки в секцию импорта
    ; kernel32 - идентификатор для дальнейших ссылок в этой секции на импортированную библиотеку
    ; 'KERNEL32.DLL' - имя файла импортируемой библиотеки

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA' ; вызов макрокоманды: добавление таблицы импорта из библиотеки
        ; kernel32 - идентификатор библиотеки, из которой импортируем
        ; ExitProcess - метка, где будет сохранен адрес импортированного
        ; 'ExitProcess' - экспортированное библиотекой имя

section '.reloc' fixups data readable discardable ; директива ассемблера: начало секции
    ; .reloc - имя секции, предназначенной для данных таблицы перемещений
    ; fixups - генерировать в этой секиции данные таблицы перемещений
    ; data - секция содержит данные
    ; readable - разрешено чтение содержимого секции
    ; discardable - если секция не нужна, то она не будет загружаться
