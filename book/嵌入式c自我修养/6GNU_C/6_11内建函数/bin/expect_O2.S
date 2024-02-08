
6_11内建函数/bin/expect_O2:     file format elf32-littlearm


Disassembly of section .interp:

00010154 <.interp>:
   10154:	62696c2f 	rsbvs	r6, r9, #12032	; 0x2f00
   10158:	2d646c2f 	stclcs	12, cr6, [r4, #-188]!	; 0xffffff44
   1015c:	756e696c 	strbvc	r6, [lr, #-2412]!	; 0xfffff694
   10160:	6f732e78 	svcvs	0x00732e78
   10164:	Address 0x0000000000010164 is out of bounds.


Disassembly of section .note.gnu.build-id:

00010168 <.note.gnu.build-id>:
   10168:	00000004 	andeq	r0, r0, r4
   1016c:	00000014 	andeq	r0, r0, r4, lsl r0
   10170:	00000003 	andeq	r0, r0, r3
   10174:	00554e47 	subseq	r4, r5, r7, asr #28
   10178:	0da9b76f 	stceq	7, cr11, [r9, #444]!	; 0x1bc
   1017c:	62f27f23 	rscsvs	r7, r2, #35, 30	; 0x8c
   10180:	ed726032 	ldcl	0, cr6, [r2, #-200]!	; 0xffffff38
   10184:	ef593712 	svc	0x00593712
   10188:	e804a083 	stmda	r4, {r0, r1, r7, sp, pc}

Disassembly of section .note.ABI-tag:

0001018c <__abi_tag>:
   1018c:	00000004 	andeq	r0, r0, r4
   10190:	00000010 	andeq	r0, r0, r0, lsl r0
   10194:	00000001 	andeq	r0, r0, r1
   10198:	00554e47 	subseq	r4, r5, r7, asr #28
   1019c:	00000000 	andeq	r0, r0, r0
   101a0:	00000003 	andeq	r0, r0, r3
   101a4:	00000002 	andeq	r0, r0, r2
   101a8:	00000000 	andeq	r0, r0, r0

Disassembly of section .gnu.hash:

000101ac <.gnu.hash>:
   101ac:	00000003 	andeq	r0, r0, r3
   101b0:	00000002 	andeq	r0, r0, r2
   101b4:	00000002 	andeq	r0, r0, r2
   101b8:	00000006 	andeq	r0, r0, r6
   101bc:	00042b80 	andeq	r2, r4, r0, lsl #23
   101c0:	21204101 			; <UNDEFINED> instruction: 0x21204101
   101c4:	00000002 	andeq	r0, r0, r2
   101c8:	00000004 	andeq	r0, r0, r4
   101cc:	00000006 	andeq	r0, r0, r6
   101d0:	07646220 	strbeq	r6, [r4, -r0, lsr #4]!
   101d4:	eafe348d 	b	fff9d410 <__bss_end__+0xfff7c3d8>
   101d8:	b4ebe20a 	strbtlt	lr, [fp], #522	; 0x20a
   101dc:	0f11ed7d 	svceq	0x0011ed7d
   101e0:	f63d4e2e 			; <UNDEFINED> instruction: 0xf63d4e2e
   101e4:	1f4039c9 	svcne	0x004039c9

Disassembly of section .dynsym:

000101e8 <.dynsym>:
	...
   101f8:	0000008f 	andeq	r0, r0, pc, lsl #1
	...
   10204:	00000020 	andeq	r0, r0, r0, lsr #32
   10208:	00000046 	andeq	r0, r0, r6, asr #32
   1020c:	00020f08 	andeq	r0, r2, r8, lsl #30
   10210:	00000004 	andeq	r0, r0, r4
   10214:	00140011 	andseq	r0, r4, r1, lsl r0
   10218:	00000020 	andeq	r0, r0, r0, lsr #32
	...
   10224:	00000012 	andeq	r0, r0, r2, lsl r0
   10228:	00000001 	andeq	r0, r0, r1
	...
   10234:	00000012 	andeq	r0, r0, r2, lsl r0
   10238:	0000002f 	andeq	r0, r0, pc, lsr #32
	...
   10244:	00000012 	andeq	r0, r0, r2, lsl r0
   10248:	0000000e 	andeq	r0, r0, lr
	...
   10254:	00000012 	andeq	r0, r0, r2, lsl r0
   10258:	00000035 	andeq	r0, r0, r5, lsr r0
	...
   10264:	00000012 	andeq	r0, r0, r2, lsl r0

Disassembly of section .dynstr:

00010268 <.dynstr>:
   10268:	705f5f00 	subsvc	r5, pc, r0, lsl #30
   1026c:	746e6972 	strbtvc	r6, [lr], #-2418	; 0xfffff68e
   10270:	68635f66 	stmdavs	r3!, {r1, r2, r5, r6, r8, r9, sl, fp, ip, lr}^
   10274:	5f5f006b 	svcpl	0x005f006b
   10278:	6362696c 	cmnvs	r2, #108, 18	; 0x1b0000
   1027c:	6174735f 	cmnvs	r4, pc, asr r3
   10280:	6d5f7472 	cfldrdvs	mvd7, [pc, #-456]	; 100c0 <__abi_tag-0xcc>
   10284:	006e6961 	rsbeq	r6, lr, r1, ror #18
   10288:	73695f5f 	cmnvc	r9, #380	; 0x17c
   1028c:	3939636f 	ldmdbcc	r9!, {r0, r1, r2, r3, r5, r6, r8, r9, sp, lr}
   10290:	6163735f 	cmnvs	r3, pc, asr r3
   10294:	6100666e 	tstvs	r0, lr, ror #12
   10298:	74726f62 	ldrbtvc	r6, [r2], #-3938	; 0xfffff09e
   1029c:	735f5f00 	cmpvc	pc, #0, 30
   102a0:	6b636174 	blvs	18e8878 <__bss_end__+0x18c7840>
   102a4:	6b68635f 	blvs	1a29028 <__bss_end__+0x1a07ff0>
   102a8:	6961665f 	stmdbvs	r1!, {r0, r1, r2, r3, r4, r6, r9, sl, sp, lr}^
   102ac:	5f5f006c 	svcpl	0x005f006c
   102b0:	63617473 	cmnvs	r1, #1929379840	; 0x73000000
   102b4:	68635f6b 	stmdavs	r3!, {r0, r1, r3, r5, r6, r8, r9, sl, fp, ip, lr}^
   102b8:	75675f6b 	strbvc	r5, [r7, #-3947]!	; 0xfffff095
   102bc:	00647261 	rsbeq	r7, r4, r1, ror #4
   102c0:	6362696c 	cmnvs	r2, #108, 18	; 0x1b0000
   102c4:	2e6f732e 	cdpcs	3, 6, cr7, cr15, cr14, {1}
   102c8:	646c0036 	strbtvs	r0, [ip], #-54	; 0xffffffca
   102cc:	6e696c2d 	cdpvs	12, 6, cr6, cr9, cr13, {1}
   102d0:	732e7875 			; <UNDEFINED> instruction: 0x732e7875
   102d4:	00332e6f 	eorseq	r2, r3, pc, ror #28
   102d8:	42494c47 	submi	r4, r9, #18176	; 0x4700
   102dc:	2e325f43 	cdpcs	15, 3, cr5, cr2, cr3, {2}
   102e0:	4c470034 	mcrrmi	0, 3, r0, r7, cr4
   102e4:	5f434249 	svcpl	0x00434249
   102e8:	00372e32 	eorseq	r2, r7, r2, lsr lr
   102ec:	42494c47 	submi	r4, r9, #18176	; 0x4700
   102f0:	2e325f43 	cdpcs	15, 3, cr5, cr2, cr3, {2}
   102f4:	5f003433 	svcpl	0x00003433
   102f8:	6f6d675f 	svcvs	0x006d675f
   102fc:	74735f6e 	ldrbtvc	r5, [r3], #-3950	; 0xfffff092
   10300:	5f747261 	svcpl	0x00747261
   10304:	Address 0x0000000000010304 is out of bounds.


Disassembly of section .gnu.version:

00010306 <.gnu.version>:
   10306:	00010000 	andeq	r0, r1, r0
   1030a:	00050003 	andeq	r0, r5, r3
   1030e:	00040004 	andeq	r0, r4, r4
   10312:	00040002 	andeq	r0, r4, r2

Disassembly of section .gnu.version_r:

00010318 <.gnu.version_r>:
   10318:	00010001 	andeq	r0, r1, r1
   1031c:	00000062 	andeq	r0, r0, r2, rrx
   10320:	00000010 	andeq	r0, r0, r0, lsl r0
   10324:	00000020 	andeq	r0, r0, r0, lsr #32
   10328:	0d696914 			; <UNDEFINED> instruction: 0x0d696914
   1032c:	00030000 	andeq	r0, r3, r0
   10330:	00000070 	andeq	r0, r0, r0, ror r0
   10334:	00000000 	andeq	r0, r0, r0
   10338:	00030001 	andeq	r0, r3, r1
   1033c:	00000058 	andeq	r0, r0, r8, asr r0
   10340:	00000010 	andeq	r0, r0, r0, lsl r0
   10344:	00000000 	andeq	r0, r0, r0
   10348:	0d696917 			; <UNDEFINED> instruction: 0x0d696917
   1034c:	00050000 	andeq	r0, r5, r0
   10350:	0000007a 	andeq	r0, r0, sl, ror r0
   10354:	00000010 	andeq	r0, r0, r0, lsl r0
   10358:	0d696914 			; <UNDEFINED> instruction: 0x0d696914
   1035c:	00040000 	andeq	r0, r4, r0
   10360:	00000070 	andeq	r0, r0, r0, ror r0
   10364:	00000010 	andeq	r0, r0, r0, lsl r0
   10368:	069691b4 			; <UNDEFINED> instruction: 0x069691b4
   1036c:	00020000 	andeq	r0, r2, r0
   10370:	00000084 	andeq	r0, r0, r4, lsl #1
   10374:	00000000 	andeq	r0, r0, r0

Disassembly of section .rel.dyn:

00010378 <.rel.dyn>:
   10378:	00021024 	andeq	r1, r2, r4, lsr #32
   1037c:	00000115 	andeq	r0, r0, r5, lsl r1
   10380:	00020f08 	andeq	r0, r2, r8, lsl #30
   10384:	00000214 	andeq	r0, r0, r4, lsl r2

Disassembly of section .rel.plt:

00010388 <.rel.plt>:
   10388:	0002100c 	andeq	r1, r2, ip
   1038c:	00000616 	andeq	r0, r0, r6, lsl r6
   10390:	00021010 	andeq	r1, r2, r0, lsl r0
   10394:	00000716 	andeq	r0, r0, r6, lsl r7
   10398:	00021014 	andeq	r1, r2, r4, lsl r0
   1039c:	00000116 	andeq	r0, r0, r6, lsl r1
   103a0:	00021018 	andeq	r1, r2, r8, lsl r0
   103a4:	00000416 	andeq	r0, r0, r6, lsl r4
   103a8:	0002101c 	andeq	r1, r2, ip, lsl r0
   103ac:	00000316 	andeq	r0, r0, r6, lsl r3
   103b0:	00021020 	andeq	r1, r2, r0, lsr #32
   103b4:	00000516 	andeq	r0, r0, r6, lsl r5

Disassembly of section .init:

000103b8 <_init>:
   103b8:	e92d4008 	push	{r3, lr}
   103bc:	eb000052 	bl	1050c <call_weak_fn>
   103c0:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000103c4 <.plt>:
   103c4:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   103c8:	e59fe004 	ldr	lr, [pc, #4]	; 103d4 <.plt+0x10>
   103cc:	e08fe00e 	add	lr, pc, lr
   103d0:	e5bef008 	ldr	pc, [lr, #8]!
   103d4:	00010c2c 	andeq	r0, r1, ip, lsr #24

000103d8 <__libc_start_main@plt>:
   103d8:	e28fc600 	add	ip, pc, #0, 12
   103dc:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103e0:	e5bcfc2c 	ldr	pc, [ip, #3116]!	; 0xc2c

000103e4 <__stack_chk_fail@plt>:
   103e4:	e28fc600 	add	ip, pc, #0, 12
   103e8:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103ec:	e5bcfc24 	ldr	pc, [ip, #3108]!	; 0xc24

000103f0 <__gmon_start__@plt>:
   103f0:	e28fc600 	add	ip, pc, #0, 12
   103f4:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103f8:	e5bcfc1c 	ldr	pc, [ip, #3100]!	; 0xc1c

000103fc <__printf_chk@plt>:
   103fc:	e28fc600 	add	ip, pc, #0, 12
   10400:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10404:	e5bcfc14 	ldr	pc, [ip, #3092]!	; 0xc14

00010408 <__isoc99_scanf@plt>:
   10408:	e28fc600 	add	ip, pc, #0, 12
   1040c:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10410:	e5bcfc0c 	ldr	pc, [ip, #3084]!	; 0xc0c

00010414 <abort@plt>:
   10414:	e28fc600 	add	ip, pc, #0, 12
   10418:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   1041c:	e5bcfc04 	ldr	pc, [ip, #3076]!	; 0xc04

Disassembly of section .text:

00010420 <main>:
   10420:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   10424:	e59f3090 	ldr	r3, [pc, #144]	; 104bc <main+0x9c>
   10428:	e24dd00c 	sub	sp, sp, #12
   1042c:	e1a0100d 	mov	r1, sp
   10430:	e59f0088 	ldr	r0, [pc, #136]	; 104c0 <main+0xa0>
   10434:	e5933000 	ldr	r3, [r3]
   10438:	e58d3004 	str	r3, [sp, #4]
   1043c:	e3a03000 	mov	r3, #0
   10440:	ebfffff0 	bl	10408 <__isoc99_scanf@plt>
   10444:	e59d3000 	ldr	r3, [sp]
   10448:	e3530000 	cmp	r3, #0
   1044c:	0a000010 	beq	10494 <main+0x74>
   10450:	e3a02005 	mov	r2, #5
   10454:	e59f1064 	ldr	r1, [pc, #100]	; 104c0 <main+0xa0>
   10458:	e3a00001 	mov	r0, #1
   1045c:	ebffffe6 	bl	103fc <__printf_chk@plt>
   10460:	e3a02006 	mov	r2, #6
   10464:	e3a00001 	mov	r0, #1
   10468:	e59f1054 	ldr	r1, [pc, #84]	; 104c4 <main+0xa4>
   1046c:	ebffffe2 	bl	103fc <__printf_chk@plt>
   10470:	e59f3044 	ldr	r3, [pc, #68]	; 104bc <main+0x9c>
   10474:	e5932000 	ldr	r2, [r3]
   10478:	e59d3004 	ldr	r3, [sp, #4]
   1047c:	e0332002 	eors	r2, r3, r2
   10480:	e3a03000 	mov	r3, #0
   10484:	1a00000b 	bne	104b8 <main+0x98>
   10488:	e3a00000 	mov	r0, #0
   1048c:	e28dd00c 	add	sp, sp, #12
   10490:	e49df004 	pop	{pc}		; (ldr pc, [sp], #4)
   10494:	e3a02001 	mov	r2, #1
   10498:	e59f1020 	ldr	r1, [pc, #32]	; 104c0 <main+0xa0>
   1049c:	e1a00002 	mov	r0, r2
   104a0:	ebffffd5 	bl	103fc <__printf_chk@plt>
   104a4:	e3a02002 	mov	r2, #2
   104a8:	e59f1014 	ldr	r1, [pc, #20]	; 104c4 <main+0xa4>
   104ac:	e3a00001 	mov	r0, #1
   104b0:	ebffffd1 	bl	103fc <__printf_chk@plt>
   104b4:	eaffffed 	b	10470 <main+0x50>
   104b8:	ebffffc9 	bl	103e4 <__stack_chk_fail@plt>
   104bc:	00020f08 	andeq	r0, r2, r8, lsl #30
   104c0:	0001065c 	andeq	r0, r1, ip, asr r6
   104c4:	00010660 	andeq	r0, r1, r0, ror #12

000104c8 <_start>:
   104c8:	e3a0b000 	mov	fp, #0
   104cc:	e3a0e000 	mov	lr, #0
   104d0:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
   104d4:	e1a0200d 	mov	r2, sp
   104d8:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
   104dc:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
   104e0:	e59fa01c 	ldr	sl, [pc, #28]	; 10504 <_start+0x3c>
   104e4:	e28f3018 	add	r3, pc, #24
   104e8:	e08aa003 	add	sl, sl, r3
   104ec:	e3a03000 	mov	r3, #0
   104f0:	e52d3004 	push	{r3}		; (str r3, [sp, #-4]!)
   104f4:	e59f000c 	ldr	r0, [pc, #12]	; 10508 <_start+0x40>
   104f8:	e79a0000 	ldr	r0, [sl, r0]
   104fc:	ebffffb5 	bl	103d8 <__libc_start_main@plt>
   10500:	ebffffc3 	bl	10414 <abort@plt>
   10504:	00010afc 	strdeq	r0, [r1], -ip
   10508:	00000028 	andeq	r0, r0, r8, lsr #32

0001050c <call_weak_fn>:
   1050c:	e59f3014 	ldr	r3, [pc, #20]	; 10528 <call_weak_fn+0x1c>
   10510:	e59f2014 	ldr	r2, [pc, #20]	; 1052c <call_weak_fn+0x20>
   10514:	e08f3003 	add	r3, pc, r3
   10518:	e7932002 	ldr	r2, [r3, r2]
   1051c:	e3520000 	cmp	r2, #0
   10520:	012fff1e 	bxeq	lr
   10524:	eaffffb1 	b	103f0 <__gmon_start__@plt>
   10528:	00010ae4 	andeq	r0, r1, r4, ror #21
   1052c:	00000024 	andeq	r0, r0, r4, lsr #32

00010530 <deregister_tm_clones>:
   10530:	e59f0018 	ldr	r0, [pc, #24]	; 10550 <deregister_tm_clones+0x20>
   10534:	e59f3018 	ldr	r3, [pc, #24]	; 10554 <deregister_tm_clones+0x24>
   10538:	e1530000 	cmp	r3, r0
   1053c:	012fff1e 	bxeq	lr
   10540:	e59f3010 	ldr	r3, [pc, #16]	; 10558 <deregister_tm_clones+0x28>
   10544:	e3530000 	cmp	r3, #0
   10548:	012fff1e 	bxeq	lr
   1054c:	e12fff13 	bx	r3
   10550:	00021034 	andeq	r1, r2, r4, lsr r0
   10554:	00021034 	andeq	r1, r2, r4, lsr r0
   10558:	00000000 	andeq	r0, r0, r0

0001055c <register_tm_clones>:
   1055c:	e59f0024 	ldr	r0, [pc, #36]	; 10588 <register_tm_clones+0x2c>
   10560:	e59f3024 	ldr	r3, [pc, #36]	; 1058c <register_tm_clones+0x30>
   10564:	e0433000 	sub	r3, r3, r0
   10568:	e1a01fa3 	lsr	r1, r3, #31
   1056c:	e0811143 	add	r1, r1, r3, asr #2
   10570:	e1b010c1 	asrs	r1, r1, #1
   10574:	012fff1e 	bxeq	lr
   10578:	e59f3010 	ldr	r3, [pc, #16]	; 10590 <register_tm_clones+0x34>
   1057c:	e3530000 	cmp	r3, #0
   10580:	012fff1e 	bxeq	lr
   10584:	e12fff13 	bx	r3
   10588:	00021034 	andeq	r1, r2, r4, lsr r0
   1058c:	00021034 	andeq	r1, r2, r4, lsr r0
   10590:	00000000 	andeq	r0, r0, r0

00010594 <__do_global_dtors_aux>:
   10594:	e92d4010 	push	{r4, lr}
   10598:	e59f4018 	ldr	r4, [pc, #24]	; 105b8 <__do_global_dtors_aux+0x24>
   1059c:	e5d43000 	ldrb	r3, [r4]
   105a0:	e3530000 	cmp	r3, #0
   105a4:	18bd8010 	popne	{r4, pc}
   105a8:	ebffffe0 	bl	10530 <deregister_tm_clones>
   105ac:	e3a03001 	mov	r3, #1
   105b0:	e5c43000 	strb	r3, [r4]
   105b4:	e8bd8010 	pop	{r4, pc}
   105b8:	00021034 	andeq	r1, r2, r4, lsr r0

000105bc <frame_dummy>:
   105bc:	eaffffe6 	b	1055c <register_tm_clones>

Disassembly of section .fini:

000105c0 <_fini>:
   105c0:	e92d4008 	push	{r3, lr}
   105c4:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

000105c8 <_IO_stdin_used>:
   105c8:	00020001 	andeq	r0, r2, r1

000105cc <all_implied_fbits>:
   105cc:	0000003b 	andeq	r0, r0, fp, lsr r0
   105d0:	0000003e 	andeq	r0, r0, lr, lsr r0
   105d4:	0000000b 	andeq	r0, r0, fp
   105d8:	0000003e 	andeq	r0, r0, lr, lsr r0
   105dc:	00000010 	andeq	r0, r0, r0, lsl r0
   105e0:	0000003e 	andeq	r0, r0, lr, lsr r0
   105e4:	00000025 	andeq	r0, r0, r5, lsr #32
   105e8:	0000003e 	andeq	r0, r0, lr, lsr r0
   105ec:	00000033 	andeq	r0, r0, r3, lsr r0
   105f0:	0000003e 	andeq	r0, r0, lr, lsr r0
   105f4:	00000003 	andeq	r0, r0, r3
   105f8:	0000003e 	andeq	r0, r0, lr, lsr r0
   105fc:	00000006 	andeq	r0, r0, r6
   10600:	0000003e 	andeq	r0, r0, lr, lsr r0
   10604:	00000014 	andeq	r0, r0, r4, lsl r0
   10608:	0000003e 	andeq	r0, r0, lr, lsr r0
   1060c:	0000000e 	andeq	r0, r0, lr
   10610:	0000003e 	andeq	r0, r0, lr, lsr r0
   10614:	0000000d 	andeq	r0, r0, sp
   10618:	0000003e 	andeq	r0, r0, lr, lsr r0
   1061c:	00000024 	andeq	r0, r0, r4, lsr #32
   10620:	0000003e 	andeq	r0, r0, lr, lsr r0
   10624:	00000012 	andeq	r0, r0, r2, lsl r0
   10628:	0000003e 	andeq	r0, r0, lr, lsr r0
   1062c:	00000027 	andeq	r0, r0, r7, lsr #32
   10630:	0000003e 	andeq	r0, r0, lr, lsr r0
   10634:	00000002 	andeq	r0, r0, r2
   10638:	0000003e 	andeq	r0, r0, lr, lsr r0
   1063c:	00000018 	andeq	r0, r0, r8, lsl r0
   10640:	0000003e 	andeq	r0, r0, lr, lsr r0
   10644:	00000009 	andeq	r0, r0, r9
   10648:	0000003e 	andeq	r0, r0, lr, lsr r0
   1064c:	0000000a 	andeq	r0, r0, sl
   10650:	0000003e 	andeq	r0, r0, lr, lsr r0
	...
   1065c:	00006425 	andeq	r6, r0, r5, lsr #8
   10660:	000a6425 	andeq	r6, sl, r5, lsr #8

00010664 <all_implied_fbits>:
   10664:	0000003b 	andeq	r0, r0, fp, lsr r0
   10668:	0000003e 	andeq	r0, r0, lr, lsr r0
   1066c:	0000000b 	andeq	r0, r0, fp
   10670:	0000003e 	andeq	r0, r0, lr, lsr r0
   10674:	00000010 	andeq	r0, r0, r0, lsl r0
   10678:	0000003e 	andeq	r0, r0, lr, lsr r0
   1067c:	00000025 	andeq	r0, r0, r5, lsr #32
   10680:	0000003e 	andeq	r0, r0, lr, lsr r0
   10684:	00000033 	andeq	r0, r0, r3, lsr r0
   10688:	0000003e 	andeq	r0, r0, lr, lsr r0
   1068c:	00000003 	andeq	r0, r0, r3
   10690:	0000003e 	andeq	r0, r0, lr, lsr r0
   10694:	00000006 	andeq	r0, r0, r6
   10698:	0000003e 	andeq	r0, r0, lr, lsr r0
   1069c:	00000014 	andeq	r0, r0, r4, lsl r0
   106a0:	0000003e 	andeq	r0, r0, lr, lsr r0
   106a4:	0000000e 	andeq	r0, r0, lr
   106a8:	0000003e 	andeq	r0, r0, lr, lsr r0
   106ac:	0000000d 	andeq	r0, r0, sp
   106b0:	0000003e 	andeq	r0, r0, lr, lsr r0
   106b4:	00000024 	andeq	r0, r0, r4, lsr #32
   106b8:	0000003e 	andeq	r0, r0, lr, lsr r0
   106bc:	00000012 	andeq	r0, r0, r2, lsl r0
   106c0:	0000003e 	andeq	r0, r0, lr, lsr r0
   106c4:	00000027 	andeq	r0, r0, r7, lsr #32
   106c8:	0000003e 	andeq	r0, r0, lr, lsr r0
   106cc:	00000002 	andeq	r0, r0, r2
   106d0:	0000003e 	andeq	r0, r0, lr, lsr r0
   106d4:	00000018 	andeq	r0, r0, r8, lsl r0
   106d8:	0000003e 	andeq	r0, r0, lr, lsr r0
   106dc:	00000009 	andeq	r0, r0, r9
   106e0:	0000003e 	andeq	r0, r0, lr, lsr r0
   106e4:	0000000a 	andeq	r0, r0, sl
   106e8:	0000003e 	andeq	r0, r0, lr, lsr r0
	...

Disassembly of section .ARM.exidx:

000106f4 <.ARM.exidx>:
   106f4:	7ffffdd4 	svcvc	0x00fffdd4
   106f8:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

000106fc <__FRAME_END__>:
   106fc:	00000000 	andeq	r0, r0, r0

Disassembly of section .init_array:

00020f00 <__frame_dummy_init_array_entry>:
   20f00:	000105bc 			; <UNDEFINED> instruction: 0x000105bc

Disassembly of section .fini_array:

00020f04 <__do_global_dtors_aux_fini_array_entry>:
   20f04:	00010594 	muleq	r1, r4, r5

Disassembly of section .data.rel.ro:

00020f08 <__stack_chk_guard@GLIBC_2.4>:
   20f08:	00000000 	andeq	r0, r0, r0

Disassembly of section .dynamic:

00020f0c <_DYNAMIC>:
   20f0c:	00000001 	andeq	r0, r0, r1
   20f10:	00000058 	andeq	r0, r0, r8, asr r0
   20f14:	00000001 	andeq	r0, r0, r1
   20f18:	00000062 	andeq	r0, r0, r2, rrx
   20f1c:	0000000c 	andeq	r0, r0, ip
   20f20:	000103b8 			; <UNDEFINED> instruction: 0x000103b8
   20f24:	0000000d 	andeq	r0, r0, sp
   20f28:	000105c0 	andeq	r0, r1, r0, asr #11
   20f2c:	00000019 	andeq	r0, r0, r9, lsl r0
   20f30:	00020f00 	andeq	r0, r2, r0, lsl #30
   20f34:	0000001b 	andeq	r0, r0, fp, lsl r0
   20f38:	00000004 	andeq	r0, r0, r4
   20f3c:	0000001a 	andeq	r0, r0, sl, lsl r0
   20f40:	00020f04 	andeq	r0, r2, r4, lsl #30
   20f44:	0000001c 	andeq	r0, r0, ip, lsl r0
   20f48:	00000004 	andeq	r0, r0, r4
   20f4c:	6ffffef5 	svcvs	0x00fffef5
   20f50:	000101ac 	andeq	r0, r1, ip, lsr #3
   20f54:	00000005 	andeq	r0, r0, r5
   20f58:	00010268 	andeq	r0, r1, r8, ror #4
   20f5c:	00000006 	andeq	r0, r0, r6
   20f60:	000101e8 	andeq	r0, r1, r8, ror #3
   20f64:	0000000a 	andeq	r0, r0, sl
   20f68:	0000009e 	muleq	r0, lr, r0
   20f6c:	0000000b 	andeq	r0, r0, fp
   20f70:	00000010 	andeq	r0, r0, r0, lsl r0
   20f74:	00000015 	andeq	r0, r0, r5, lsl r0
   20f78:	00000000 	andeq	r0, r0, r0
   20f7c:	00000003 	andeq	r0, r0, r3
   20f80:	00021000 	andeq	r1, r2, r0
   20f84:	00000002 	andeq	r0, r0, r2
   20f88:	00000030 	andeq	r0, r0, r0, lsr r0
   20f8c:	00000014 	andeq	r0, r0, r4, lsl r0
   20f90:	00000011 	andeq	r0, r0, r1, lsl r0
   20f94:	00000017 	andeq	r0, r0, r7, lsl r0
   20f98:	00010388 	andeq	r0, r1, r8, lsl #7
   20f9c:	00000011 	andeq	r0, r0, r1, lsl r0
   20fa0:	00010378 	andeq	r0, r1, r8, ror r3
   20fa4:	00000012 	andeq	r0, r0, r2, lsl r0
   20fa8:	00000010 	andeq	r0, r0, r0, lsl r0
   20fac:	00000013 	andeq	r0, r0, r3, lsl r0
   20fb0:	00000008 	andeq	r0, r0, r8
   20fb4:	6ffffffe 	svcvs	0x00fffffe
   20fb8:	00010318 	andeq	r0, r1, r8, lsl r3
   20fbc:	6fffffff 	svcvs	0x00ffffff
   20fc0:	00000002 	andeq	r0, r0, r2
   20fc4:	6ffffff0 	svcvs	0x00fffff0
   20fc8:	00010306 	andeq	r0, r1, r6, lsl #6
	...

Disassembly of section .got:

00021000 <_GLOBAL_OFFSET_TABLE_>:
   21000:	00020f0c 	andeq	r0, r2, ip, lsl #30
	...
   2100c:	000103c4 	andeq	r0, r1, r4, asr #7
   21010:	000103c4 	andeq	r0, r1, r4, asr #7
   21014:	000103c4 	andeq	r0, r1, r4, asr #7
   21018:	000103c4 	andeq	r0, r1, r4, asr #7
   2101c:	000103c4 	andeq	r0, r1, r4, asr #7
   21020:	000103c4 	andeq	r0, r1, r4, asr #7
   21024:	00000000 	andeq	r0, r0, r0
   21028:	00010420 	andeq	r0, r1, r0, lsr #8

Disassembly of section .data:

0002102c <__data_start>:
   2102c:	00000000 	andeq	r0, r0, r0

00021030 <__dso_handle>:
   21030:	00000000 	andeq	r0, r0, r0

Disassembly of section .bss:

00021034 <completed.0>:
   21034:	00000000 	andeq	r0, r0, r0

Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <__bss_end__+0x10afcec>
   4:	62552820 	subsvs	r2, r5, #32, 16	; 0x200000
   8:	75746e75 	ldrbvc	r6, [r4, #-3701]!	; 0xfffff18b
   c:	2e313120 	rsfcssp	f3, f1, f0
  10:	2d302e34 	ldccs	14, cr2, [r0, #-208]!	; 0xffffff30
  14:	75627531 	strbvc	r7, [r2, #-1329]!	; 0xfffffacf
  18:	3175746e 	cmncc	r5, lr, ror #8
  1c:	2e32327e 	mrccs	2, 1, r3, cr2, cr14, {3}
  20:	20293430 	eorcs	r3, r9, r0, lsr r4
  24:	342e3131 	strtcc	r3, [lr], #-305	; 0xfffffecf
  28:	Address 0x0000000000000028 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002941 	andeq	r2, r0, r1, asr #18
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000001f 	andeq	r0, r0, pc, lsl r0
  10:	00543505 	subseq	r3, r4, r5, lsl #10
  14:	01080306 	tsteq	r8, r6, lsl #6
  18:	04120109 	ldreq	r0, [r2], #-265	; 0xfffffef7
  1c:	01140113 	tsteq	r4, r3, lsl r1
  20:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	Address 0x0000000000000028 is out of bounds.

