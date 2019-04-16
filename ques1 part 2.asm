.386

INCLUDE Irvine32.inc

.data
intArray WORD  2,4,6,8,10
foundMsg BYTE "odd integer found: ",0
noneMsg  BYTE "no odd integer found ",0
testing SWORD ?

.code
main proc
    mov   ebx,OFFSET intArray        
    mov   ecx,LENGTHOF intArray        

L1:
    mov   ax, WORD PTR[ebx]
    mov   testing, ax
    and   WORD PTR [ebx],1        
    jnz   found                
    add   ebx,2                
    loop  L1                    
    jmp   notFound                

found:
    mov   edx,OFFSET foundMsg        
    call  WriteString
    movsx eax,testing        
    call  WriteInt
    jmp   quit

notFound:
    mov   edx,OFFSET noneMsg        
    call  WriteString

quit:
    call  crlf
    exit
main endp
end main