;�� ����� ���������� ������� ���������� ����������, ������� ��������� ��� �������� ������������� ������,
;������� ��� ��������� ��������� ������ ������ �� 10 ��������, ����� ���� ������� ����� � ������������ � �������� ������ ��������.
format PE console NX
entry start
include 'WIN32A.INC'
section '.bss' data readable writeable
; ���������� ���������� ��� �������� ����������� �����
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

section '.text' code readable executable ; ��������� ����������: ������ ������
    ; .text - ��� ������, ��������������� ��� ����
    ; code - ������ �������� ���    ; readable - ��������� ������ ����������� ������
    ; executable - ��������� ���������� ����������� ������

start: ; ����� ����� (�� entry)

 ;�������� ���������� �����
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    
    ; �������� ���������� ������
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

; ������ ������
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

;������� ������ 1
    push 0
    push dwNumber
    push 14
    push stroka1
    push [hOutput]
    call [WriteConsole]

;������� ������ 2
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]

;������� ������ 3
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

;������� ������ 4
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]

    ;������� ������ 5
    push 0
    push dwNumber
    push 14
    push stroka5
    push [hOutput]
    call [WriteConsole]

    ;������� ������ 6
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;������� ������ 7
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
;������� ������ 8
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;������� ������ 9
    push 0
    push dwNumber
    push 14
    push stroka5
    push [hOutput]
    call [WriteConsole]

  ;������� ������ 10
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
     ;������� ������ 11
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
;������� ������ 12
    push 0
    push dwNumber
    push 14
    push stroka2
    push [hOutput]
    call [WriteConsole]
    ;������� ������ 13
    push 0
    push dwNumber
    push 14
    push stroka13
    push [hOutput]
    call [WriteConsole]






    
    ; ������ ���� ������ - ������������ ��� ��������
    push 0
    push dwNumber       ; ��� ��������� ���������� ��������� ��������
    push 1              ; ���������� �������� ��������
    push buf            ; �������� (�����), ���� ��������� �������� �������
    push [hInput]       ; ��� ����� ���������� ����� (������), ������ ���� ����������� ����
    call [ReadConsole]  ; ��������� ����� �������: ����� ����� ����� �������� � ReadConsole

    ; ���������� ���������
    push 0              ; ��� ���������� ���������: 0 - ��� ������
    call [ExitProcess]  ; ��������� ����� �������: ����� ����� ����� �������� � ExitProcess

section '.idata' import data readable writeable ; ��������� ����������: ������ ������
    ; .idata - ��� ������, ��������������� ��� ������ �� ������� �������
    ; data - ������ �������� ������
    ; readable - ��������� ������ ����������� ������
    ; writeable - ��������� ��������� ����������� ������

library kernel32, 'KERNEL32.DLL' ; ����� ������������: ���������� ���������� � ������ �������
    ; kernel32 - ������������� ��� ���������� ������ � ���� ������ �� ��������������� ����������
    ; 'KERNEL32.DLL' - ��� ����� ������������� ����������

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA' ; ����� ������������: ���������� ������� ������� �� ����������
        ; kernel32 - ������������� ����������, �� ������� �����������
        ; ExitProcess - �����, ��� ����� �������� ����� ����������������
        ; 'ExitProcess' - ���������������� ����������� ���

section '.reloc' fixups data readable discardable ; ��������� ����������: ������ ������
    ; .reloc - ��� ������, ��������������� ��� ������ ������� �����������
    ; fixups - ������������ � ���� ������� ������ ������� �����������
    ; data - ������ �������� ������
    ; readable - ��������� ������ ����������� ������
    ; discardable - ���� ������ �� �����, �� ��� �� ����� �����������
