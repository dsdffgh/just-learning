
/home/name_linux/workspace/book/嵌入式c自我修养/a.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)  
 319:	6c                   	insb   (%dx),%es:(%rdi)
 31a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
 321:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
 326:	78 2d                	js     355 <__abi_tag-0x37>
 328:	78 38                	js     362 <__abi_tag-0x2a>
 32a:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
 330:	6f                   	outsl  %ds:(%rsi),(%dx)
 331:	2e 32 00             	cs xor (%rax),%al

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    $0x0,%al
 33a:	00 00                	add    %al,(%rax)
 33c:	20 00                	and    %al,(%rax)
 33e:	00 00                	add    %al,(%rax)
 340:	05 00 00 00 47       	add    $0x47000000,%eax
 345:	4e 55                	rex.WRX push %rbp
 347:	00 02                	add    %al,(%rdx)
 349:	00 00                	add    %al,(%rax)
 34b:	c0 04 00 00          	rolb   $0x0,(%rax,%rax,1)
 34f:	00 03                	add    %al,(%rbx)
 351:	00 00                	add    %al,(%rax)
 353:	00 00                	add    %al,(%rax)
 355:	00 00                	add    %al,(%rax)
 357:	00 02                	add    %al,(%rdx)
 359:	80 00 c0             	addb   $0xc0,(%rax)
 35c:	04 00                	add    $0x0,%al
 35e:	00 00                	add    %al,(%rax)
 360:	01 00                	add    %eax,(%rax)
 362:	00 00                	add    %al,(%rax)
 364:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000000368 <.note.gnu.build-id>:
 368:	04 00                	add    $0x0,%al
 36a:	00 00                	add    %al,(%rax)
 36c:	14 00                	adc    $0x0,%al
 36e:	00 00                	add    %al,(%rax)
 370:	03 00                	add    (%rax),%eax
 372:	00 00                	add    %al,(%rax)
 374:	47                   	rex.RXB
 375:	4e 55                	rex.WRX push %rbp
 377:	00 69 5a             	add    %ch,0x5a(%rcx)
 37a:	bf 9b 0a 14 4d       	mov    $0x4d140a9b,%edi
 37f:	66 ec                	data16 in (%dx),%al
 381:	02 40 24             	add    0x24(%rax),%al
 384:	56                   	push   %rsi
 385:	4c 62                	rex.WR (bad) 
 387:	5c                   	pop    %rsp
 388:	6b                   	.byte 0x6b
 389:	54                   	push   %rsp
 38a:	1a ec                	sbb    %ah,%ch

Disassembly of section .note.ABI-tag:

000000000000038c <__abi_tag>:
 38c:	04 00                	add    $0x0,%al
 38e:	00 00                	add    %al,(%rax)
 390:	10 00                	adc    %al,(%rax)
 392:	00 00                	add    %al,(%rax)
 394:	01 00                	add    %eax,(%rax)
 396:	00 00                	add    %al,(%rax)
 398:	47                   	rex.RXB
 399:	4e 55                	rex.WRX push %rbp
 39b:	00 00                	add    %al,(%rax)
 39d:	00 00                	add    %al,(%rax)
 39f:	00 03                	add    %al,(%rbx)
 3a1:	00 00                	add    %al,(%rax)
 3a3:	00 02                	add    %al,(%rdx)
 3a5:	00 00                	add    %al,(%rax)
 3a7:	00 00                	add    %al,(%rax)
 3a9:	00 00                	add    %al,(%rax)
	...

Disassembly of section .gnu.hash:

00000000000003b0 <.gnu.hash>:
 3b0:	02 00                	add    (%rax),%al
 3b2:	00 00                	add    %al,(%rax)
 3b4:	07                   	(bad)  
 3b5:	00 00                	add    %al,(%rax)
 3b7:	00 01                	add    %al,(%rcx)
 3b9:	00 00                	add    %al,(%rax)
 3bb:	00 06                	add    %al,(%rsi)
 3bd:	00 00                	add    %al,(%rax)
 3bf:	00 00                	add    %al,(%rax)
 3c1:	40 81 01 00 00 00 00 	rex addl $0x0,(%rcx)
 3c8:	07                   	(bad)  
 3c9:	00 00                	add    %al,(%rax)
 3cb:	00 00                	add    %al,(%rax)
 3cd:	00 00                	add    %al,(%rax)
 3cf:	00 0e                	add    %cl,(%rsi)
 3d1:	b6 02                	mov    $0x2,%dh
 3d3:	00 d1                	add    %dl,%cl
 3d5:	65 ce                	gs (bad) 
 3d7:	6d                   	insl   (%dx),%es:(%rdi)

Disassembly of section .dynsym:

00000000000003d8 <.dynsym>:
	...
 3f0:	5b                   	pop    %rbx
 3f1:	00 00                	add    %al,(%rax)
 3f3:	00 12                	add    %dl,(%rdx)
	...
 405:	00 00                	add    %al,(%rax)
 407:	00 2a                	add    %ch,(%rdx)
 409:	00 00                	add    %al,(%rax)
 40b:	00 20                	add    %ah,(%rax)
	...
 41d:	00 00                	add    %al,(%rax)
 41f:	00 57 00             	add    %dl,0x0(%rdi)
 422:	00 00                	add    %al,(%rax)
 424:	12 00                	adc    (%rax),%al
	...
 436:	00 00                	add    %al,(%rax)
 438:	6d                   	insl   (%dx),%es:(%rdi)
 439:	00 00                	add    %al,(%rax)
 43b:	00 12                	add    %dl,(%rdx)
	...
 44d:	00 00                	add    %al,(%rax)
 44f:	00 46 00             	add    %al,0x0(%rsi)
 452:	00 00                	add    %al,(%rax)
 454:	20 00                	and    %al,(%rax)
	...
 466:	00 00                	add    %al,(%rax)
 468:	10 00                	adc    %al,(%rax)
 46a:	00 00                	add    %al,(%rax)
 46c:	20 00                	and    %al,(%rax)
	...
 47e:	00 00                	add    %al,(%rax)
 480:	55                   	push   %rbp
 481:	00 00                	add    %al,(%rax)
 483:	00 21                	add    %ah,(%rcx)
 485:	00 19                	add    %bl,(%rcx)
 487:	00 10                	add    %dl,(%rax)
 489:	40 00 00             	rex add %al,(%rax)
 48c:	00 00                	add    %al,(%rax)
 48e:	00 00                	add    %al,(%rax)
 490:	04 00                	add    $0x0,%al
 492:	00 00                	add    %al,(%rax)
 494:	00 00                	add    %al,(%rax)
 496:	00 00                	add    %al,(%rax)
 498:	01 00                	add    %eax,(%rax)
 49a:	00 00                	add    %al,(%rax)
 49c:	22 00                	and    (%rax),%al
	...

Disassembly of section .dynstr:

00000000000004b0 <.dynstr>:
 4b0:	00 5f 5f             	add    %bl,0x5f(%rdi)
 4b3:	63 78 61             	movsxd 0x61(%rax),%edi
 4b6:	5f                   	pop    %rdi
 4b7:	66 69 6e 61 6c 69    	imul   $0x696c,0x61(%rsi),%bp
 4bd:	7a 65                	jp     524 <__abi_tag+0x198>
 4bf:	00 5f 49             	add    %bl,0x49(%rdi)
 4c2:	54                   	push   %rsp
 4c3:	4d 5f                	rex.WRB pop %r15
 4c5:	72 65                	jb     52c <__abi_tag+0x1a0>
 4c7:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4ce:	4d 
 4cf:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4d1:	6f                   	outsl  %ds:(%rsi),(%dx)
 4d2:	6e                   	outsb  %ds:(%rsi),(%dx)
 4d3:	65 54                	gs push %rsp
 4d5:	61                   	(bad)  
 4d6:	62                   	(bad)  
 4d7:	6c                   	insb   (%dx),%es:(%rdi)
 4d8:	65 00 5f 49          	add    %bl,%gs:0x49(%rdi)
 4dc:	54                   	push   %rsp
 4dd:	4d 5f                	rex.WRB pop %r15
 4df:	64 65 72 65          	fs gs jb 548 <__abi_tag+0x1bc>
 4e3:	67 69 73 74 65 72 54 	imul   $0x4d547265,0x74(%ebx),%esi
 4ea:	4d 
 4eb:	43 6c                	rex.XB insb (%dx),%es:(%rdi)
 4ed:	6f                   	outsl  %ds:(%rsi),(%dx)
 4ee:	6e                   	outsb  %ds:(%rsi),(%dx)
 4ef:	65 54                	gs push %rsp
 4f1:	61                   	(bad)  
 4f2:	62                   	(bad)  
 4f3:	6c                   	insb   (%dx),%es:(%rdi)
 4f4:	65 00 5f 5f          	add    %bl,%gs:0x5f(%rdi)
 4f8:	67 6d                	insl   (%dx),%es:(%edi)
 4fa:	6f                   	outsl  %ds:(%rsi),(%dx)
 4fb:	6e                   	outsb  %ds:(%rsi),(%dx)
 4fc:	5f                   	pop    %rdi
 4fd:	73 74                	jae    573 <__abi_tag+0x1e7>
 4ff:	61                   	(bad)  
 500:	72 74                	jb     576 <__abi_tag+0x1ea>
 502:	5f                   	pop    %rdi
 503:	5f                   	pop    %rdi
 504:	00 69 00             	add    %ch,0x0(%rcx)
 507:	61                   	(bad)  
 508:	64 64 00 5f 5f       	fs add %bl,%fs:0x5f(%rdi)
 50d:	6c                   	insb   (%dx),%es:(%rdi)
 50e:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
 515:	72 74                	jb     58b <__abi_tag+0x1ff>
 517:	5f                   	pop    %rdi
 518:	6d                   	insl   (%dx),%es:(%rdi)
 519:	61                   	(bad)  
 51a:	69 6e 00 70 72 69 6e 	imul   $0x6e697270,0x0(%rsi),%ebp
 521:	74 66                	je     589 <__abi_tag+0x1fd>
 523:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 527:	74 65                	je     58e <__abi_tag+0x202>
 529:	73 74                	jae    59f <__abi_tag+0x213>
 52b:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
 52f:	63 2e                	movsxd (%rsi),%ebp
 531:	73 6f                	jae    5a2 <__abi_tag+0x216>
 533:	2e 36 00 47 4c       	cs ss add %al,0x4c(%rdi)
 538:	49                   	rex.WB
 539:	42                   	rex.X
 53a:	43 5f                	rex.XB pop %r15
 53c:	32 2e                	xor    (%rsi),%ch
 53e:	32 2e                	xor    (%rsi),%ch
 540:	35 00 47 4c 49       	xor    $0x494c4700,%eax
 545:	42                   	rex.X
 546:	43 5f                	rex.XB pop %r15
 548:	32 2e                	xor    (%rsi),%ch
 54a:	33 34 00             	xor    (%rax,%rax,1),%esi

Disassembly of section .gnu.version:

000000000000054e <.gnu.version>:
 54e:	00 00                	add    %al,(%rax)
 550:	02 00                	add    (%rax),%al
 552:	01 00                	add    %eax,(%rax)
 554:	01 00                	add    %eax,(%rax)
 556:	03 00                	add    (%rax),%eax
 558:	01 00                	add    %eax,(%rax)
 55a:	01 00                	add    %eax,(%rax)
 55c:	01 00                	add    %eax,(%rax)
 55e:	03 00                	add    (%rax),%eax

Disassembly of section .gnu.version_r:

0000000000000560 <.gnu.version_r>:
 560:	01 00                	add    %eax,(%rax)
 562:	02 00                	add    (%rax),%al
 564:	7c 00                	jl     566 <__abi_tag+0x1da>
 566:	00 00                	add    %al,(%rax)
 568:	10 00                	adc    %al,(%rax)
 56a:	00 00                	add    %al,(%rax)
 56c:	00 00                	add    %al,(%rax)
 56e:	00 00                	add    %al,(%rax)
 570:	75 1a                	jne    58c <__abi_tag+0x200>
 572:	69 09 00 00 03 00    	imul   $0x30000,(%rcx),%ecx
 578:	86 00                	xchg   %al,(%rax)
 57a:	00 00                	add    %al,(%rax)
 57c:	10 00                	adc    %al,(%rax)
 57e:	00 00                	add    %al,(%rax)
 580:	b4 91                	mov    $0x91,%ah
 582:	96                   	xchg   %eax,%esi
 583:	06                   	(bad)  
 584:	00 00                	add    %al,(%rax)
 586:	02 00                	add    (%rax),%al
 588:	92                   	xchg   %eax,%edx
 589:	00 00                	add    %al,(%rax)
 58b:	00 00                	add    %al,(%rax)
 58d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000000590 <.rela.dyn>:
 590:	a0 3d 00 00 00 00 00 	movabs 0x80000000000003d,%al
 597:	00 08 
 599:	00 00                	add    %al,(%rax)
 59b:	00 00                	add    %al,(%rax)
 59d:	00 00                	add    %al,(%rax)
 59f:	00 60 11             	add    %ah,0x11(%rax)
 5a2:	00 00                	add    %al,(%rax)
 5a4:	00 00                	add    %al,(%rax)
 5a6:	00 00                	add    %al,(%rax)
 5a8:	a8 3d                	test   $0x3d,%al
 5aa:	00 00                	add    %al,(%rax)
 5ac:	00 00                	add    %al,(%rax)
 5ae:	00 00                	add    %al,(%rax)
 5b0:	08 00                	or     %al,(%rax)
 5b2:	00 00                	add    %al,(%rax)
 5b4:	00 00                	add    %al,(%rax)
 5b6:	00 00                	add    %al,(%rax)
 5b8:	20 11                	and    %dl,(%rcx)
 5ba:	00 00                	add    %al,(%rax)
 5bc:	00 00                	add    %al,(%rax)
 5be:	00 00                	add    %al,(%rax)
 5c0:	08 40 00             	or     %al,0x0(%rax)
 5c3:	00 00                	add    %al,(%rax)
 5c5:	00 00                	add    %al,(%rax)
 5c7:	00 08                	add    %cl,(%rax)
 5c9:	00 00                	add    %al,(%rax)
 5cb:	00 00                	add    %al,(%rax)
 5cd:	00 00                	add    %al,(%rax)
 5cf:	00 08                	add    %cl,(%rax)
 5d1:	40 00 00             	rex add %al,(%rax)
 5d4:	00 00                	add    %al,(%rax)
 5d6:	00 00                	add    %al,(%rax)
 5d8:	d8 3f                	fdivrs (%rdi)
 5da:	00 00                	add    %al,(%rax)
 5dc:	00 00                	add    %al,(%rax)
 5de:	00 00                	add    %al,(%rax)
 5e0:	06                   	(bad)  
 5e1:	00 00                	add    %al,(%rax)
 5e3:	00 01                	add    %al,(%rcx)
	...
 5ed:	00 00                	add    %al,(%rax)
 5ef:	00 e0                	add    %ah,%al
 5f1:	3f                   	(bad)  
 5f2:	00 00                	add    %al,(%rax)
 5f4:	00 00                	add    %al,(%rax)
 5f6:	00 00                	add    %al,(%rax)
 5f8:	06                   	(bad)  
 5f9:	00 00                	add    %al,(%rax)
 5fb:	00 02                	add    %al,(%rdx)
	...
 605:	00 00                	add    %al,(%rax)
 607:	00 e8                	add    %ch,%al
 609:	3f                   	(bad)  
 60a:	00 00                	add    %al,(%rax)
 60c:	00 00                	add    %al,(%rax)
 60e:	00 00                	add    %al,(%rax)
 610:	06                   	(bad)  
 611:	00 00                	add    %al,(%rax)
 613:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 619 <__abi_tag+0x28d>
 619:	00 00                	add    %al,(%rax)
 61b:	00 00                	add    %al,(%rax)
 61d:	00 00                	add    %al,(%rax)
 61f:	00 f0                	add    %dh,%al
 621:	3f                   	(bad)  
 622:	00 00                	add    %al,(%rax)
 624:	00 00                	add    %al,(%rax)
 626:	00 00                	add    %al,(%rax)
 628:	06                   	(bad)  
 629:	00 00                	add    %al,(%rax)
 62b:	00 06                	add    %al,(%rsi)
	...
 635:	00 00                	add    %al,(%rax)
 637:	00 f8                	add    %bh,%al
 639:	3f                   	(bad)  
 63a:	00 00                	add    %al,(%rax)
 63c:	00 00                	add    %al,(%rax)
 63e:	00 00                	add    %al,(%rax)
 640:	06                   	(bad)  
 641:	00 00                	add    %al,(%rax)
 643:	00 08                	add    %cl,(%rax)
	...

Disassembly of section .rela.plt:

0000000000000650 <.rela.plt>:
 650:	c8 3f 00 00          	enter  $0x3f,$0x0
 654:	00 00                	add    %al,(%rax)
 656:	00 00                	add    %al,(%rax)
 658:	07                   	(bad)  
 659:	00 00                	add    %al,(%rax)
 65b:	00 03                	add    %al,(%rbx)
	...
 665:	00 00                	add    %al,(%rax)
 667:	00 d0                	add    %dl,%al
 669:	3f                   	(bad)  
 66a:	00 00                	add    %al,(%rax)
 66c:	00 00                	add    %al,(%rax)
 66e:	00 00                	add    %al,(%rax)
 670:	07                   	(bad)  
 671:	00 00                	add    %al,(%rax)
 673:	00 04 00             	add    %al,(%rax,%rax,1)
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 92 2f 00 00    	push   0x2f92(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 93 2f 00 00 	bnd jmp *0x2f93(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	push   $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    104f:	90                   	nop

Disassembly of section .plt.got:

0000000000001050 <__cxa_finalize@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 9d 2f 00 00 	bnd jmp *0x2f9d(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001060 <add@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 5d 2f 00 00 	bnd jmp *0x2f5d(%rip)        # 3fc8 <add@Base>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001070 <printf@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmp *0x2f55(%rip)        # 3fd0 <printf@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001080 <_start>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	31 ed                	xor    %ebp,%ebp
    1086:	49 89 d1             	mov    %rdx,%r9
    1089:	5e                   	pop    %rsi
    108a:	48 89 e2             	mov    %rsp,%rdx
    108d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1091:	50                   	push   %rax
    1092:	54                   	push   %rsp
    1093:	45 31 c0             	xor    %r8d,%r8d
    1096:	31 c9                	xor    %ecx,%ecx
    1098:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 1169 <main>
    109f:	ff 15 33 2f 00 00    	call   *0x2f33(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    10a5:	f4                   	hlt    
    10a6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    10ad:	00 00 00 

00000000000010b0 <deregister_tm_clones>:
    10b0:	48 8d 3d 61 2f 00 00 	lea    0x2f61(%rip),%rdi        # 4018 <__TMC_END__>
    10b7:	48 8d 05 5a 2f 00 00 	lea    0x2f5a(%rip),%rax        # 4018 <__TMC_END__>
    10be:	48 39 f8             	cmp    %rdi,%rax
    10c1:	74 15                	je     10d8 <deregister_tm_clones+0x28>
    10c3:	48 8b 05 16 2f 00 00 	mov    0x2f16(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10ca:	48 85 c0             	test   %rax,%rax
    10cd:	74 09                	je     10d8 <deregister_tm_clones+0x28>
    10cf:	ff e0                	jmp    *%rax
    10d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10d8:	c3                   	ret    
    10d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010e0 <register_tm_clones>:
    10e0:	48 8d 3d 31 2f 00 00 	lea    0x2f31(%rip),%rdi        # 4018 <__TMC_END__>
    10e7:	48 8d 35 2a 2f 00 00 	lea    0x2f2a(%rip),%rsi        # 4018 <__TMC_END__>
    10ee:	48 29 fe             	sub    %rdi,%rsi
    10f1:	48 89 f0             	mov    %rsi,%rax
    10f4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10f8:	48 c1 f8 03          	sar    $0x3,%rax
    10fc:	48 01 c6             	add    %rax,%rsi
    10ff:	48 d1 fe             	sar    %rsi
    1102:	74 14                	je     1118 <register_tm_clones+0x38>
    1104:	48 8b 05 e5 2e 00 00 	mov    0x2ee5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    110b:	48 85 c0             	test   %rax,%rax
    110e:	74 08                	je     1118 <register_tm_clones+0x38>
    1110:	ff e0                	jmp    *%rax
    1112:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1118:	c3                   	ret    
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <__do_global_dtors_aux>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	80 3d e9 2e 00 00 00 	cmpb   $0x0,0x2ee9(%rip)        # 4014 <completed.0>
    112b:	75 2b                	jne    1158 <__do_global_dtors_aux+0x38>
    112d:	55                   	push   %rbp
    112e:	48 83 3d c2 2e 00 00 	cmpq   $0x0,0x2ec2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1135:	00 
    1136:	48 89 e5             	mov    %rsp,%rbp
    1139:	74 0c                	je     1147 <__do_global_dtors_aux+0x27>
    113b:	48 8b 3d c6 2e 00 00 	mov    0x2ec6(%rip),%rdi        # 4008 <__dso_handle>
    1142:	e8 09 ff ff ff       	call   1050 <__cxa_finalize@plt>
    1147:	e8 64 ff ff ff       	call   10b0 <deregister_tm_clones>
    114c:	c6 05 c1 2e 00 00 01 	movb   $0x1,0x2ec1(%rip)        # 4014 <completed.0>
    1153:	5d                   	pop    %rbp
    1154:	c3                   	ret    
    1155:	0f 1f 00             	nopl   (%rax)
    1158:	c3                   	ret    
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	e9 77 ff ff ff       	jmp    10e0 <register_tm_clones>

0000000000001169 <main>:
    1169:	f3 0f 1e fa          	endbr64 
    116d:	55                   	push   %rbp
    116e:	48 89 e5             	mov    %rsp,%rbp
    1171:	48 83 ec 10          	sub    $0x10,%rsp
    1175:	8b 05 95 2e 00 00    	mov    0x2e95(%rip),%eax        # 4010 <i>
    117b:	89 c6                	mov    %eax,%esi
    117d:	48 8d 05 80 0e 00 00 	lea    0xe80(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    1184:	48 89 c7             	mov    %rax,%rdi
    1187:	b8 00 00 00 00       	mov    $0x0,%eax
    118c:	e8 df fe ff ff       	call   1070 <printf@plt>
    1191:	be 03 00 00 00       	mov    $0x3,%esi
    1196:	bf 01 00 00 00       	mov    $0x1,%edi
    119b:	e8 c0 fe ff ff       	call   1060 <add@plt>
    11a0:	89 45 fc             	mov    %eax,-0x4(%rbp)
    11a3:	8b 45 fc             	mov    -0x4(%rbp),%eax
    11a6:	89 c6                	mov    %eax,%esi
    11a8:	48 8d 05 5d 0e 00 00 	lea    0xe5d(%rip),%rax        # 200c <_IO_stdin_used+0xc>
    11af:	48 89 c7             	mov    %rax,%rdi
    11b2:	b8 00 00 00 00       	mov    $0x0,%eax
    11b7:	e8 b4 fe ff ff       	call   1070 <printf@plt>
    11bc:	b8 00 00 00 00       	mov    $0x0,%eax
    11c1:	c9                   	leave  
    11c2:	c3                   	ret    

Disassembly of section .fini:

00000000000011c4 <_fini>:
    11c4:	f3 0f 1e fa          	endbr64 
    11c8:	48 83 ec 08          	sub    $0x8,%rsp
    11cc:	48 83 c4 08          	add    $0x8,%rsp
    11d0:	c3                   	ret    

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    %eax,(%rax)
    2002:	02 00                	add    (%rax),%al
    2004:	69 20 3d 20 25 64    	imul   $0x6425203d,(%rax),%esp
    200a:	0a 00                	or     (%rax),%al
    200c:	73 75                	jae    2083 <__GNU_EH_FRAME_HDR+0x6b>
    200e:	6d                   	insl   (%dx),%es:(%rdi)
    200f:	20 20                	and    %ah,(%rax)
    2011:	3d 20 25 64 0a       	cmp    $0xa642520,%eax
	...

Disassembly of section .eh_frame_hdr:

0000000000002018 <__GNU_EH_FRAME_HDR>:
    2018:	01 1b                	add    %ebx,(%rbx)
    201a:	03 3b                	add    (%rbx),%edi
    201c:	34 00                	xor    $0x0,%al
    201e:	00 00                	add    %al,(%rax)
    2020:	05 00 00 00 08       	add    $0x8000000,%eax
    2025:	f0 ff                	lock (bad) 
    2027:	ff 68 00             	ljmp   *0x0(%rax)
    202a:	00 00                	add    %al,(%rax)
    202c:	38 f0                	cmp    %dh,%al
    202e:	ff                   	(bad)  
    202f:	ff 90 00 00 00 48    	call   *0x48000000(%rax)
    2035:	f0 ff                	lock (bad) 
    2037:	ff a8 00 00 00 68    	ljmp   *0x68000000(%rax)
    203d:	f0 ff                	lock (bad) 
    203f:	ff 50 00             	call   *0x0(%rax)
    2042:	00 00                	add    %al,(%rax)
    2044:	51                   	push   %rcx
    2045:	f1                   	int1   
    2046:	ff                   	(bad)  
    2047:	ff c0                	inc    %eax
    2049:	00 00                	add    %al,(%rax)
	...

Disassembly of section .eh_frame:

0000000000002050 <__FRAME_END__-0xa8>:
    2050:	14 00                	adc    $0x0,%al
    2052:	00 00                	add    %al,(%rax)
    2054:	00 00                	add    %al,(%rax)
    2056:	00 00                	add    %al,(%rax)
    2058:	01 7a 52             	add    %edi,0x52(%rdx)
    205b:	00 01                	add    %al,(%rcx)
    205d:	78 10                	js     206f <__GNU_EH_FRAME_HDR+0x57>
    205f:	01 1b                	add    %ebx,(%rbx)
    2061:	0c 07                	or     $0x7,%al
    2063:	08 90 01 00 00 14    	or     %dl,0x14000001(%rax)
    2069:	00 00                	add    %al,(%rax)
    206b:	00 1c 00             	add    %bl,(%rax,%rax,1)
    206e:	00 00                	add    %al,(%rax)
    2070:	10 f0                	adc    %dh,%al
    2072:	ff                   	(bad)  
    2073:	ff 26                	jmp    *(%rsi)
    2075:	00 00                	add    %al,(%rax)
    2077:	00 00                	add    %al,(%rax)
    2079:	44 07                	rex.R (bad) 
    207b:	10 00                	adc    %al,(%rax)
    207d:	00 00                	add    %al,(%rax)
    207f:	00 24 00             	add    %ah,(%rax,%rax,1)
    2082:	00 00                	add    %al,(%rax)
    2084:	34 00                	xor    $0x0,%al
    2086:	00 00                	add    %al,(%rax)
    2088:	98                   	cwtl   
    2089:	ef                   	out    %eax,(%dx)
    208a:	ff                   	(bad)  
    208b:	ff 30                	push   (%rax)
    208d:	00 00                	add    %al,(%rax)
    208f:	00 00                	add    %al,(%rax)
    2091:	0e                   	(bad)  
    2092:	10 46 0e             	adc    %al,0xe(%rsi)
    2095:	18 4a 0f             	sbb    %cl,0xf(%rdx)
    2098:	0b 77 08             	or     0x8(%rdi),%esi
    209b:	80 00 3f             	addb   $0x3f,(%rax)
    209e:	1a 3a                	sbb    (%rdx),%bh
    20a0:	2a 33                	sub    (%rbx),%dh
    20a2:	24 22                	and    $0x22,%al
    20a4:	00 00                	add    %al,(%rax)
    20a6:	00 00                	add    %al,(%rax)
    20a8:	14 00                	adc    $0x0,%al
    20aa:	00 00                	add    %al,(%rax)
    20ac:	5c                   	pop    %rsp
    20ad:	00 00                	add    %al,(%rax)
    20af:	00 a0 ef ff ff 10    	add    %ah,0x10ffffef(%rax)
	...
    20bd:	00 00                	add    %al,(%rax)
    20bf:	00 14 00             	add    %dl,(%rax,%rax,1)
    20c2:	00 00                	add    %al,(%rax)
    20c4:	74 00                	je     20c6 <__GNU_EH_FRAME_HDR+0xae>
    20c6:	00 00                	add    %al,(%rax)
    20c8:	98                   	cwtl   
    20c9:	ef                   	out    %eax,(%dx)
    20ca:	ff                   	(bad)  
    20cb:	ff 20                	jmp    *(%rax)
	...
    20d5:	00 00                	add    %al,(%rax)
    20d7:	00 1c 00             	add    %bl,(%rax,%rax,1)
    20da:	00 00                	add    %al,(%rax)
    20dc:	8c 00                	mov    %es,(%rax)
    20de:	00 00                	add    %al,(%rax)
    20e0:	89 f0                	mov    %esi,%eax
    20e2:	ff                   	(bad)  
    20e3:	ff 5a 00             	lcall  *0x0(%rdx)
    20e6:	00 00                	add    %al,(%rax)
    20e8:	00 45 0e             	add    %al,0xe(%rbp)
    20eb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
    20f1:	02 51 0c             	add    0xc(%rcx),%dl
    20f4:	07                   	(bad)  
    20f5:	08 00                	or     %al,(%rax)
	...

00000000000020f8 <__FRAME_END__>:
    20f8:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000003da0 <__frame_dummy_init_array_entry>:
    3da0:	60                   	(bad)  
    3da1:	11 00                	adc    %eax,(%rax)
    3da3:	00 00                	add    %al,(%rax)
    3da5:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000003da8 <__do_global_dtors_aux_fini_array_entry>:
    3da8:	20 11                	and    %dl,(%rcx)
    3daa:	00 00                	add    %al,(%rax)
    3dac:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000003db0 <_DYNAMIC>:
    3db0:	01 00                	add    %eax,(%rax)
    3db2:	00 00                	add    %al,(%rax)
    3db4:	00 00                	add    %al,(%rax)
    3db6:	00 00                	add    %al,(%rax)
    3db8:	74 00                	je     3dba <_DYNAMIC+0xa>
    3dba:	00 00                	add    %al,(%rax)
    3dbc:	00 00                	add    %al,(%rax)
    3dbe:	00 00                	add    %al,(%rax)
    3dc0:	01 00                	add    %eax,(%rax)
    3dc2:	00 00                	add    %al,(%rax)
    3dc4:	00 00                	add    %al,(%rax)
    3dc6:	00 00                	add    %al,(%rax)
    3dc8:	7c 00                	jl     3dca <_DYNAMIC+0x1a>
    3dca:	00 00                	add    %al,(%rax)
    3dcc:	00 00                	add    %al,(%rax)
    3dce:	00 00                	add    %al,(%rax)
    3dd0:	0c 00                	or     $0x0,%al
    3dd2:	00 00                	add    %al,(%rax)
    3dd4:	00 00                	add    %al,(%rax)
    3dd6:	00 00                	add    %al,(%rax)
    3dd8:	00 10                	add    %dl,(%rax)
    3dda:	00 00                	add    %al,(%rax)
    3ddc:	00 00                	add    %al,(%rax)
    3dde:	00 00                	add    %al,(%rax)
    3de0:	0d 00 00 00 00       	or     $0x0,%eax
    3de5:	00 00                	add    %al,(%rax)
    3de7:	00 c4                	add    %al,%ah
    3de9:	11 00                	adc    %eax,(%rax)
    3deb:	00 00                	add    %al,(%rax)
    3ded:	00 00                	add    %al,(%rax)
    3def:	00 19                	add    %bl,(%rcx)
    3df1:	00 00                	add    %al,(%rax)
    3df3:	00 00                	add    %al,(%rax)
    3df5:	00 00                	add    %al,(%rax)
    3df7:	00 a0 3d 00 00 00    	add    %ah,0x3d(%rax)
    3dfd:	00 00                	add    %al,(%rax)
    3dff:	00 1b                	add    %bl,(%rbx)
    3e01:	00 00                	add    %al,(%rax)
    3e03:	00 00                	add    %al,(%rax)
    3e05:	00 00                	add    %al,(%rax)
    3e07:	00 08                	add    %cl,(%rax)
    3e09:	00 00                	add    %al,(%rax)
    3e0b:	00 00                	add    %al,(%rax)
    3e0d:	00 00                	add    %al,(%rax)
    3e0f:	00 1a                	add    %bl,(%rdx)
    3e11:	00 00                	add    %al,(%rax)
    3e13:	00 00                	add    %al,(%rax)
    3e15:	00 00                	add    %al,(%rax)
    3e17:	00 a8 3d 00 00 00    	add    %ch,0x3d(%rax)
    3e1d:	00 00                	add    %al,(%rax)
    3e1f:	00 1c 00             	add    %bl,(%rax,%rax,1)
    3e22:	00 00                	add    %al,(%rax)
    3e24:	00 00                	add    %al,(%rax)
    3e26:	00 00                	add    %al,(%rax)
    3e28:	08 00                	or     %al,(%rax)
    3e2a:	00 00                	add    %al,(%rax)
    3e2c:	00 00                	add    %al,(%rax)
    3e2e:	00 00                	add    %al,(%rax)
    3e30:	f5                   	cmc    
    3e31:	fe                   	(bad)  
    3e32:	ff 6f 00             	ljmp   *0x0(%rdi)
    3e35:	00 00                	add    %al,(%rax)
    3e37:	00 b0 03 00 00 00    	add    %dh,0x3(%rax)
    3e3d:	00 00                	add    %al,(%rax)
    3e3f:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 3e45 <_DYNAMIC+0x95>
    3e45:	00 00                	add    %al,(%rax)
    3e47:	00 b0 04 00 00 00    	add    %dh,0x4(%rax)
    3e4d:	00 00                	add    %al,(%rax)
    3e4f:	00 06                	add    %al,(%rsi)
    3e51:	00 00                	add    %al,(%rax)
    3e53:	00 00                	add    %al,(%rax)
    3e55:	00 00                	add    %al,(%rax)
    3e57:	00 d8                	add    %bl,%al
    3e59:	03 00                	add    (%rax),%eax
    3e5b:	00 00                	add    %al,(%rax)
    3e5d:	00 00                	add    %al,(%rax)
    3e5f:	00 0a                	add    %cl,(%rdx)
    3e61:	00 00                	add    %al,(%rax)
    3e63:	00 00                	add    %al,(%rax)
    3e65:	00 00                	add    %al,(%rax)
    3e67:	00 9d 00 00 00 00    	add    %bl,0x0(%rbp)
    3e6d:	00 00                	add    %al,(%rax)
    3e6f:	00 0b                	add    %cl,(%rbx)
    3e71:	00 00                	add    %al,(%rax)
    3e73:	00 00                	add    %al,(%rax)
    3e75:	00 00                	add    %al,(%rax)
    3e77:	00 18                	add    %bl,(%rax)
    3e79:	00 00                	add    %al,(%rax)
    3e7b:	00 00                	add    %al,(%rax)
    3e7d:	00 00                	add    %al,(%rax)
    3e7f:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 3e85 <_DYNAMIC+0xd5>
	...
    3e8d:	00 00                	add    %al,(%rax)
    3e8f:	00 03                	add    %al,(%rbx)
    3e91:	00 00                	add    %al,(%rax)
    3e93:	00 00                	add    %al,(%rax)
    3e95:	00 00                	add    %al,(%rax)
    3e97:	00 b0 3f 00 00 00    	add    %dh,0x3f(%rax)
    3e9d:	00 00                	add    %al,(%rax)
    3e9f:	00 02                	add    %al,(%rdx)
    3ea1:	00 00                	add    %al,(%rax)
    3ea3:	00 00                	add    %al,(%rax)
    3ea5:	00 00                	add    %al,(%rax)
    3ea7:	00 30                	add    %dh,(%rax)
    3ea9:	00 00                	add    %al,(%rax)
    3eab:	00 00                	add    %al,(%rax)
    3ead:	00 00                	add    %al,(%rax)
    3eaf:	00 14 00             	add    %dl,(%rax,%rax,1)
    3eb2:	00 00                	add    %al,(%rax)
    3eb4:	00 00                	add    %al,(%rax)
    3eb6:	00 00                	add    %al,(%rax)
    3eb8:	07                   	(bad)  
    3eb9:	00 00                	add    %al,(%rax)
    3ebb:	00 00                	add    %al,(%rax)
    3ebd:	00 00                	add    %al,(%rax)
    3ebf:	00 17                	add    %dl,(%rdi)
    3ec1:	00 00                	add    %al,(%rax)
    3ec3:	00 00                	add    %al,(%rax)
    3ec5:	00 00                	add    %al,(%rax)
    3ec7:	00 50 06             	add    %dl,0x6(%rax)
    3eca:	00 00                	add    %al,(%rax)
    3ecc:	00 00                	add    %al,(%rax)
    3ece:	00 00                	add    %al,(%rax)
    3ed0:	07                   	(bad)  
    3ed1:	00 00                	add    %al,(%rax)
    3ed3:	00 00                	add    %al,(%rax)
    3ed5:	00 00                	add    %al,(%rax)
    3ed7:	00 90 05 00 00 00    	add    %dl,0x5(%rax)
    3edd:	00 00                	add    %al,(%rax)
    3edf:	00 08                	add    %cl,(%rax)
    3ee1:	00 00                	add    %al,(%rax)
    3ee3:	00 00                	add    %al,(%rax)
    3ee5:	00 00                	add    %al,(%rax)
    3ee7:	00 c0                	add    %al,%al
    3ee9:	00 00                	add    %al,(%rax)
    3eeb:	00 00                	add    %al,(%rax)
    3eed:	00 00                	add    %al,(%rax)
    3eef:	00 09                	add    %cl,(%rcx)
    3ef1:	00 00                	add    %al,(%rax)
    3ef3:	00 00                	add    %al,(%rax)
    3ef5:	00 00                	add    %al,(%rax)
    3ef7:	00 18                	add    %bl,(%rax)
    3ef9:	00 00                	add    %al,(%rax)
    3efb:	00 00                	add    %al,(%rax)
    3efd:	00 00                	add    %al,(%rax)
    3eff:	00 1e                	add    %bl,(%rsi)
    3f01:	00 00                	add    %al,(%rax)
    3f03:	00 00                	add    %al,(%rax)
    3f05:	00 00                	add    %al,(%rax)
    3f07:	00 08                	add    %cl,(%rax)
    3f09:	00 00                	add    %al,(%rax)
    3f0b:	00 00                	add    %al,(%rax)
    3f0d:	00 00                	add    %al,(%rax)
    3f0f:	00 fb                	add    %bh,%bl
    3f11:	ff                   	(bad)  
    3f12:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f15:	00 00                	add    %al,(%rax)
    3f17:	00 01                	add    %al,(%rcx)
    3f19:	00 00                	add    %al,(%rax)
    3f1b:	08 00                	or     %al,(%rax)
    3f1d:	00 00                	add    %al,(%rax)
    3f1f:	00 fe                	add    %bh,%dh
    3f21:	ff                   	(bad)  
    3f22:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f25:	00 00                	add    %al,(%rax)
    3f27:	00 60 05             	add    %ah,0x5(%rax)
    3f2a:	00 00                	add    %al,(%rax)
    3f2c:	00 00                	add    %al,(%rax)
    3f2e:	00 00                	add    %al,(%rax)
    3f30:	ff                   	(bad)  
    3f31:	ff                   	(bad)  
    3f32:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f35:	00 00                	add    %al,(%rax)
    3f37:	00 01                	add    %al,(%rcx)
    3f39:	00 00                	add    %al,(%rax)
    3f3b:	00 00                	add    %al,(%rax)
    3f3d:	00 00                	add    %al,(%rax)
    3f3f:	00 f0                	add    %dh,%al
    3f41:	ff                   	(bad)  
    3f42:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f45:	00 00                	add    %al,(%rax)
    3f47:	00 4e 05             	add    %cl,0x5(%rsi)
    3f4a:	00 00                	add    %al,(%rax)
    3f4c:	00 00                	add    %al,(%rax)
    3f4e:	00 00                	add    %al,(%rax)
    3f50:	f9                   	stc    
    3f51:	ff                   	(bad)  
    3f52:	ff 6f 00             	ljmp   *0x0(%rdi)
    3f55:	00 00                	add    %al,(%rax)
    3f57:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .got:

0000000000003fb0 <_GLOBAL_OFFSET_TABLE_>:
    3fb0:	b0 3d                	mov    $0x3d,%al
	...
    3fc6:	00 00                	add    %al,(%rax)
    3fc8:	30 10                	xor    %dl,(%rax)
    3fca:	00 00                	add    %al,(%rax)
    3fcc:	00 00                	add    %al,(%rax)
    3fce:	00 00                	add    %al,(%rax)
    3fd0:	40 10 00             	rex adc %al,(%rax)
	...

Disassembly of section .data:

0000000000004000 <__data_start>:
	...

0000000000004008 <__dso_handle>:
    4008:	08 40 00             	or     %al,0x0(%rax)
    400b:	00 00                	add    %al,(%rax)
    400d:	00 00                	add    %al,(%rax)
	...

0000000000004010 <i>:
    4010:	0a 00                	or     (%rax),%al
	...

Disassembly of section .bss:

0000000000004014 <completed.0>:
    4014:	00 00                	add    %al,(%rax)
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <__abi_tag-0x314>
   a:	74 75                	je     81 <__abi_tag-0x30b>
   c:	20 31                	and    %dh,(%rcx)
   e:	31 2e                	xor    %ebp,(%rsi)
  10:	34 2e                	xor    $0x2e,%al
  12:	30 2d 31 75 62 75    	xor    %ch,0x75627531(%rip)        # 75627549 <__TMC_END__+0x75623531>
  18:	6e                   	outsb  %ds:(%rsi),(%dx)
  19:	74 75                	je     90 <__abi_tag-0x2fc>
  1b:	31 7e 32             	xor    %edi,0x32(%rsi)
  1e:	32 2e                	xor    (%rsi),%ch
  20:	30 34 29             	xor    %dh,(%rcx,%rbp,1)
  23:	20 31                	and    %dh,(%rcx)
  25:	31 2e                	xor    %ebp,(%rsi)
  27:	34 2e                	xor    $0x2e,%al
  29:	30 00                	xor    %al,(%rax)
