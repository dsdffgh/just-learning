
/home/name_linux/workspace/book/嵌入式c自我修养/main.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	48 83 ec 10          	sub    $0x10,%rsp
   c:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 12 <main+0x12>
  12:	89 c6                	mov    %eax,%esi
  14:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 1b <main+0x1b>
  1b:	48 89 c7             	mov    %rax,%rdi
  1e:	b8 00 00 00 00       	mov    $0x0,%eax
  23:	e8 00 00 00 00       	call   28 <main+0x28>
  28:	be 03 00 00 00       	mov    $0x3,%esi
  2d:	bf 01 00 00 00       	mov    $0x1,%edi
  32:	e8 00 00 00 00       	call   37 <main+0x37>
  37:	89 45 fc             	mov    %eax,-0x4(%rbp)
  3a:	8b 45 fc             	mov    -0x4(%rbp),%eax
  3d:	89 c6                	mov    %eax,%esi
  3f:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 46 <main+0x46>
  46:	48 89 c7             	mov    %rax,%rdi
  49:	b8 00 00 00 00       	mov    $0x0,%eax
  4e:	e8 00 00 00 00       	call   53 <main+0x53>
  53:	b8 00 00 00 00       	mov    $0x0,%eax
  58:	c9                   	leave  
  59:	c3                   	ret    

Disassembly of section .data:

0000000000000000 <i>:
   0:	0a 00                	or     (%rax),%al
	...

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	69 20 3d 20 25 64    	imul   $0x6425203d,(%rax),%esp
   6:	0a 00                	or     (%rax),%al
   8:	73 75                	jae    7f <main+0x7f>
   a:	6d                   	insl   (%dx),%es:(%rdi)
   b:	20 20                	and    %ah,(%rax)
   d:	3d 20 25 64 0a       	cmp    $0xa642520,%eax
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 62             	sub    %dl,0x62(%rbp)
   9:	75 6e                	jne    79 <main+0x79>
   b:	74 75                	je     82 <main+0x82>
   d:	20 31                	and    %dh,(%rcx)
   f:	31 2e                	xor    %ebp,(%rsi)
  11:	34 2e                	xor    $0x2e,%al
  13:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 7562754a <main+0x7562754a>
  19:	6e                   	outsb  %ds:(%rsi),(%dx)
  1a:	74 75                	je     91 <main+0x91>
  1c:	31 7e 32             	xor    %edi,0x32(%rsi)
  1f:	32 2e                	xor    (%rsi),%ch
  21:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  24:	20 31                	and    %dh,(%rcx)
  26:	31 2e                	xor    %ebp,(%rsi)
  28:	34 2e                	xor    $0x2e,%al
  2a:	30 00                	xor    %al,(%rax)

Disassembly of section .note.gnu.property:

0000000000000000 <.note.gnu.property>:
   0:	04 00                	add    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	10 00                	adc    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	05 00 00 00 47       	add    $0x47000000,%eax
   d:	4e 55                	rex.WRX push %rbp
   f:	00 02                	add    %al,(%rdx)
  11:	00 00                	add    %al,(%rax)
  13:	c0 04 00 00          	rolb   $0x0,(%rax,%rax,1)
  17:	00 03                	add    %al,(%rbx)
  19:	00 00                	add    %al,(%rax)
  1b:	00 00                	add    %al,(%rax)
  1d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	5a                   	pop    %rdx
  25:	00 00                	add    %al,(%rax)
  27:	00 00                	add    %al,(%rax)
  29:	45 0e                	rex.RB (bad) 
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	02 51 0c             	add    0xc(%rcx),%dl
  34:	07                   	(bad)  
  35:	08 00                	or     %al,(%rax)
	...
