#!/bin/bash

#Creates object file from kernel assembly
nasm -f elf32 kernel.asm -o kasm.o 

#creates object from kernel C functions
gcc -m32 -c kernel.c -o kc.o 

#Uses the link file to tie together the compiled asm/c objects
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o 