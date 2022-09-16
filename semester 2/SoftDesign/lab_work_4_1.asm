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

; резервируем место под переменную из тридцати элементов типа byte
szNum rb 40
; определяем константу со значением равным размеру предыдущей переменной
szNum.sizeof = $-szNum


section '.data' data readable writeable

; выводимое сообщение
message db 'Vvedite stroku: '
sizeof.message = $ - message
skobka1 db '{'
sizeof.skobka1 = $ - skobka1
skobka2 db '}',13,10
sizeof.skobka2 = $ - skobka2

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

    push 0              ; зарезервировано, должно быть 0
    push dwNumber       ; где сохранить количество выведенных символов
    push sizeof.message ; количество выводимых символов
    push message        ; смещение (адрес), где располагается выводимое сообщение
    push [hOutput]      ; где взять дискриптор файла (потока), куда надо осуществить вывод
    call [WriteConsole] ; косвенный вызов функции: адрес точки входа хранится в WriteConsole
      ; вводим строку
    push 0
    push dwNumbe
    push szNum.sizeof
    push szNum
    push ptr hInpu
    call ptr ReadConsole

;вывести сообщение
    push 0              ; зарезервировано, должно быть 0
    push dwNumber       ; где сохранить количество выведенных символов
    push sizeof.skobka1 ; количество выводимых символов
    push skobka1        ; смещение (адрес), где располагается выводимое сообщение
    push [hOutput]      ; где взять дискриптор файла (потока), куда надо осуществить вывод
    call [WriteConsole] ; косвенный вызов функции: адрес точки входа хранится в WriteConsole

    mov ebx, szNum
    mov eax,ebx 
    nextchar: 
    cmp byte[eax], 0
 
    jz finished
    inc eax
    jmp nextchar
 
    finished:
    sub eax, ebx
    mov edx, eax
    mov byte [ EBX + EAX - 1 ], " "
    mov byte [ EBX + EAX - 2 ], " "
    sub edx, 2
    push 0
    push dwNumbe
    push edx
    push szNum
    push ptr hOutpu
    call ptr WriteConsole

    




    push 0              ; зарезервировано, должно быть 0
    push dwNumber       ; где сохранить количество выведенных символов
    push sizeof.skobka2 ; количество выводимых символов
    push skobka2        ; смещение (адрес), где располагается выводимое сообщение
    push [hOutput]      ; где взять дискриптор файла (потока), куда надо осуществить вывод
    call [WriteConsole] ; косвенный вызов функции: адрес точки входа хранится в WriteConsole



    
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
