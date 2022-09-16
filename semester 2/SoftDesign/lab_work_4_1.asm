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

; ����������� ����� ��� ���������� �� �������� ��������� ���� byte
szNum rb 40
; ���������� ��������� �� ��������� ������ ������� ���������� ����������
szNum.sizeof = $-szNum


section '.data' data readable writeable

; ��������� ���������
message db 'Vvedite stroku: '
sizeof.message = $ - message
skobka1 db '{'
sizeof.skobka1 = $ - skobka1
skobka2 db '}',13,10
sizeof.skobka2 = $ - skobka2

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

    push 0              ; ���������������, ������ ���� 0
    push dwNumber       ; ��� ��������� ���������� ���������� ��������
    push sizeof.message ; ���������� ��������� ��������
    push message        ; �������� (�����), ��� ������������� ��������� ���������
    push [hOutput]      ; ��� ����� ���������� ����� (������), ���� ���� ����������� �����
    call [WriteConsole] ; ��������� ����� �������: ����� ����� ����� �������� � WriteConsole
      ; ������ ������
    push 0
    push dwNumbe
    push szNum.sizeof
    push szNum
    push ptr hInpu
    call ptr ReadConsole

;������� ���������
    push 0              ; ���������������, ������ ���� 0
    push dwNumber       ; ��� ��������� ���������� ���������� ��������
    push sizeof.skobka1 ; ���������� ��������� ��������
    push skobka1        ; �������� (�����), ��� ������������� ��������� ���������
    push [hOutput]      ; ��� ����� ���������� ����� (������), ���� ���� ����������� �����
    call [WriteConsole] ; ��������� ����� �������: ����� ����� ����� �������� � WriteConsole

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

    




    push 0              ; ���������������, ������ ���� 0
    push dwNumber       ; ��� ��������� ���������� ���������� ��������
    push sizeof.skobka2 ; ���������� ��������� ��������
    push skobka2        ; �������� (�����), ��� ������������� ��������� ���������
    push [hOutput]      ; ��� ����� ���������� ����� (������), ���� ���� ����������� �����
    call [WriteConsole] ; ��������� ����� �������: ����� ����� ����� �������� � WriteConsole



    
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
