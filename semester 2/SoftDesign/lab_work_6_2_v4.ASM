

format PE console NX
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable

        hInput dd ?
        hOutput dd ?
        dwNumber dd ?
        buf db ?

        tempStr db "asd"

        numberFirst rb 30
        numberFirst.sizeof = $-numberFirst

        point db '.'
        point.sizeof = $ - point

        endl db 13,10
        endl.sizeof = $ - endl

        strResult dd ?

        strTrue db "TRUE"

       buffer db ?

       array  dd 10 dup ("")
       size   dd 10

       arrayPtr dd ?


       resultSumArray dd 0
        template db "%d ", 0


section '.text' code readable executable

printArray:


        push EBP
        mov EBP, ESP


        cycle_printArray:
                cmp dword ptr EBP + 12, 0
                je endFunction_printArray

                mov EAX, [ EBP + 8 ]
                mov EAX, dword ptr EAX

               cinvoke printf, template, EAX



                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12

        jmp cycle_printArray
        endFunction_printArray:

        pop EBP
ret 8

; int* result (EBP + 8), int* array(EBP + 12), int size (EBP + 16)
sumArray:
        push EBP
        mov EBP, ESP


        mov EDX,  dword ptr EBP + 8
        mov dword ptr EDX, 0

        cycle_sumArray:

                cmp dword ptr EBP + 16, 0
                je endFunctionsumArray

                mov EAX, dword ptr EBP + 12
                mov EAX, dword ptr EAX



                mov EDX,  dword ptr EBP + 8
                add [EDX], EAX

                add dword ptr EBP + 12, 4

                dec dword ptr EBP + 16

        jmp cycle_sumArray
        endFunctionsumArray:
        pop EBP
ret 12


incArray:
        push EBP
        mov EBP, ESP




        cycle_incArray:

                cmp dword ptr EBP + 12, 0
                je endFunctionIncArray

                mov EAX, dword ptr EBP + 8

                inc dword ptr EAX

                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12

        jmp cycle_incArray
        endFunctionIncArray:
        pop EBP
ret 8

; int mainNumber(EBP + 8), int div (EBP + 12) return mainNumber % div
rule_1:
      push EBP
      mov EBP, ESP

      mov EAX, [EBP + 8]

      push EDX
      mov EDX, 0

      push ESI
      mov ESI,[EBP + 12]

      imul EAX, ESI


      pop ESI
      pop EDX
      pop EBP
ret 8

 ; int* array(EBP + 8), int size (EBP + 12)
makeArrayByRule_1:
        push EBP
        mov EBP, ESP

        push ESI
        push EAX
        push EDX

        mov ESI, 1
        mov EDI, 2

        cycle_makeArrayByRule_1:

                cmp dword ptr EBP + 12, 0
                je endFunction_makeArrayByRule_1

                push ESI
                push 1
                call rule_1


                mov EDX, dword ptr EBP + 8
              ;  mov EDX, dword ptr EDX
                mov dword ptr EDX, EAX

mov ESI, EDI
                imul ESI, ESI
                inc EDI

                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12

        jmp cycle_makeArrayByRule_1
        endFunction_makeArrayByRule_1:

        pop ESI
        pop EAX
        pop EDX
        pop EBP
ret 8

makeArrayByRule_2:
        push EBP
        mov EBP, ESP

        push ESI
        push EAX
        push EDX
        push EDI

        mov EDI, 1

        cycle_makeArrayByRule_2:

                cmp dword ptr EBP + 12, 0
                je endFunction_makeArrayByRule_2

                mov ESI, dword ptr EBP + 8

                mov EAX, dword ptr ESI
                mov EDX, 0

                cmp EAX, 4
                jne notDivideByNineNumber
                mov dword ptr ESI, 2

         notDivideByNineNumber:

                cmp EAX, 16
                jne notDivideByNineNumber1
                mov dword ptr ESI, 4


         notDivideByNineNumber1:

                      cmp EAX, 64
                jne notDivideByNineNumber2
                mov dword ptr ESI, 6


         notDivideByNineNumber2:

                add dword ptr EBP + 8, 4
                dec dword ptr EBP + 12

        jmp cycle_makeArrayByRule_2


        endFunction_makeArrayByRule_2:
        pop EDI
        pop ESI
        pop EAX
        pop EDX
        pop EBP



ret 8

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; Формируем массив
    push [size]
    push array
    call makeArrayByRule_1
    ; Выводим массив
    push [size]
    push array
    call printArray
    invoke WriteConsole, [hOutput], endl, 2, 0, 0
    ; Подсчитываем сумму
    push [size]
    push array
    push resultSumArray
    call sumArray
    ; Выводим сумму
      ; Преобразуем в число
    push 10
    push strResult
    push [resultSumArray]
    call [itoa]
    add ESP, 3 * 4
       ; Выводим число
    push strResult
    call [lstrlen]
    invoke WriteConsole, [hOutput], strResult, EAX, 0, 0
    invoke WriteConsole, [hOutput], endl, 2, 0, 0

    ; Формируем массив
    push [size]
    push array
    call makeArrayByRule_2

     ; сумма № 2
    push [size]
    push array
    push resultSumArray
    call sumArray
    ; Выводим массив
    push [size]
    push array
    call printArray
    invoke WriteConsole, [hOutput], endl, 2, 0, 0
; Выводим сумму
      ; Преобразуем в число
    push 10
    push strResult
    push [resultSumArray]
    call [itoa]
    add ESP, 3 * 4
       ; Выводим число
    push strResult
    call [lstrlen]
    invoke WriteConsole, [hOutput], strResult, EAX, 0, 0
    invoke WriteConsole, [hOutput], endl, 2, 0, 0




    ; конец программы
    push 0
    push dwNumber
    push 1
    push buf
    push [hInput]
    call [ReadConsole]

    push 0
    call [ExitProcess]

section '.idata' import data readable writeable
library user32,'user32.dll', \
    kernel32, 'KERNEL32.DLL', \
    msvcrt, 'MSVCRT.DLL'

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA'

import user32,\
   MsgBox,'MessageBoxA',\ 
   wsprintf,'wsprintfA'

import msvcrt, \
    atoi, 'atoi',\
    itoa, '_itoa', \
    printf, 'printf'

section '.reloc' fixups data readable discardable