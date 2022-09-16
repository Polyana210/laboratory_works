format PE console NX
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable

        hInput dd ?
        hOutput dd ?
        dwNumber dd ?
        buf db ?

        numberFirst rb 30
        numberFirst.sizeof = $-numberFirst

        point db '.'
        point.sizeof = $ - point

        endl db 13,10
        endl.sizeof = $ - endl

        strResult dd ?

       buffer db ?

       array  dd 1,2,3,4,5, 6
       size   dd 6

        arrayPtr dd ?

section '.rdata' data readable
        template db "%d ", 0

section '.text' code readable executable

arrayToStr:

        push EBP
        mov EBP, ESP
        cycle:
                cmp dword ptr EBP + 16, 0
                je endFunction
                mov EAX, [ EBP + 12 ]
                push dword ptr EAX
                push template
                push dword Ptr EBP + 8
                call [ wsprintf ]
                add ESP, 12
                add [ EBP + 8 ], EAX
                add dword ptr EBP + 12, 4
                dec dword ptr EBP + 16
        jmp cycle
        endFunction:
        pop EBP
ret 12


start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

   push [size]
   push array
   push buffer
   call arrayToStr


   push buffer
   call [lstrlen]
   invoke WriteConsole, [hOutput], buffer, EAX, 0, 0
   invoke WriteConsole, [hOutput], endl, 2, 0, 0

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