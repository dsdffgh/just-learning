
6_11内建函数/bin/expect:     file format elf32-littlearm


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
   10178:	6609612d 	strvs	r6, [r9], -sp, lsr #2
   1017c:	75b340fc 	ldrvc	r4, [r3, #252]!	; 0xfc
   10180:	fe7fad77 	vudot.u8	q13, <illegal reg q7.5>, d7[1]
   10184:	8fb15f99 	svchi	0x00b15f99
   10188:	a1547fba 	ldrhge	r7, [r4, #-250]	; 0xffffff06

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
   101bc:	00042280 	andeq	r2, r4, r0, lsl #5
   101c0:	21204101 			; <UNDEFINED> instruction: 0x21204101
   101c4:	00000002 	andeq	r0, r0, r2
   101c8:	00000004 	andeq	r0, r0, r4
   101cc:	00000006 	andeq	r0, r0, r6
   101d0:	07646220 	strbeq	r6, [r4, -r0, lsr #4]!
   101d4:	eafe348d 	b	fff9d410 <__bss_end__+0xfff7c3d8>
   101d8:	156b2bb8 	strbne	r2, [fp, #-3000]!	; 0xfffff448
   101dc:	0f11ed7d 	svceq	0x0011ed7d
   101e0:	f63d4e2e 			; <UNDEFINED> instruction: 0xf63d4e2e
   101e4:	1f4039c9 	svcne	0x004039c9

Disassembly of section .dynsym:

000101e8 <.dynsym>:
	...
   101f8:	00000089 	andeq	r0, r0, r9, lsl #1
	...
   10204:	00000020 	andeq	r0, r0, r0, lsr #32
   10208:	00000040 	andeq	r0, r0, r0, asr #32
   1020c:	00020f08 	andeq	r0, r2, r8, lsl #30
   10210:	00000004 	andeq	r0, r0, r4
   10214:	00140011 	andseq	r0, r4, r1, lsl r0
   10218:	00000013 	andeq	r0, r0, r3, lsl r0
	...
   10224:	00000012 	andeq	r0, r0, r2, lsl r0
   10228:	00000039 	andeq	r0, r0, r9, lsr r0
	...
   10234:	00000012 	andeq	r0, r0, r2, lsl r0
   10238:	00000022 	andeq	r0, r0, r2, lsr #32
	...
   10244:	00000012 	andeq	r0, r0, r2, lsl r0
   10248:	00000001 	andeq	r0, r0, r1
	...
   10254:	00000012 	andeq	r0, r0, r2, lsl r0
   10258:	00000028 	andeq	r0, r0, r8, lsr #32
	...
   10264:	00000012 	andeq	r0, r0, r2, lsl r0

Disassembly of section .dynstr:

00010268 <.dynstr>:
   10268:	6c5f5f00 	mrrcvs	15, 0, r5, pc, cr0	; <UNPREDICTABLE>
   1026c:	5f636269 	svcpl	0x00636269
   10270:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
   10274:	616d5f74 	smcvs	54772	; 0xd5f4
   10278:	5f006e69 	svcpl	0x00006e69
   1027c:	6f73695f 	svcvs	0x0073695f
   10280:	5f393963 	svcpl	0x00393963
   10284:	6e616373 	mcrvs	3, 3, r6, cr1, cr3, {3}
   10288:	62610066 	rsbvs	r0, r1, #102	; 0x66
   1028c:	0074726f 	rsbseq	r7, r4, pc, ror #4
   10290:	74735f5f 	ldrbtvc	r5, [r3], #-3935	; 0xfffff0a1
   10294:	5f6b6361 	svcpl	0x006b6361
   10298:	5f6b6863 	svcpl	0x006b6863
   1029c:	6c696166 	stfvse	f6, [r9], #-408	; 0xfffffe68
   102a0:	69727000 	ldmdbvs	r2!, {ip, sp, lr}^
   102a4:	0066746e 	rsbeq	r7, r6, lr, ror #8
   102a8:	74735f5f 	ldrbtvc	r5, [r3], #-3935	; 0xfffff0a1
   102ac:	5f6b6361 	svcpl	0x006b6361
   102b0:	5f6b6863 	svcpl	0x006b6863
   102b4:	72617567 	rsbvc	r7, r1, #432013312	; 0x19c00000
   102b8:	696c0064 	stmdbvs	ip!, {r2, r5, r6}^
   102bc:	732e6362 			; <UNDEFINED> instruction: 0x732e6362
   102c0:	00362e6f 	eorseq	r2, r6, pc, ror #28
   102c4:	6c2d646c 	cfstrsvs	mvf6, [sp], #-432	; 0xfffffe50
   102c8:	78756e69 	ldmdavc	r5!, {r0, r3, r5, r6, r9, sl, fp, sp, lr}^
   102cc:	2e6f732e 	cdpcs	3, 6, cr7, cr15, cr14, {1}
   102d0:	4c470033 	mcrrmi	0, 3, r0, r7, cr3
   102d4:	5f434249 	svcpl	0x00434249
   102d8:	00342e32 	eorseq	r2, r4, r2, lsr lr
   102dc:	42494c47 	submi	r4, r9, #18176	; 0x4700
   102e0:	2e325f43 	cdpcs	15, 3, cr5, cr2, cr3, {2}
   102e4:	4c470037 	mcrrmi	0, 3, r0, r7, cr7
   102e8:	5f434249 	svcpl	0x00434249
   102ec:	34332e32 	ldrtcc	r2, [r3], #-3634	; 0xfffff1ce
   102f0:	675f5f00 	ldrbvs	r5, [pc, -r0, lsl #30]
   102f4:	5f6e6f6d 	svcpl	0x006e6f6d
   102f8:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
   102fc:	005f5f74 	subseq	r5, pc, r4, ror pc	; <UNPREDICTABLE>

Disassembly of section .gnu.version:

00010300 <.gnu.version>:
   10300:	00010000 	andeq	r0, r1, r0
   10304:	00050004 	andeq	r0, r5, r4
   10308:	00030003 	andeq	r0, r3, r3
   1030c:	00030002 	andeq	r0, r3, r2

Disassembly of section .gnu.version_r:

00010310 <.gnu.version_r>:
   10310:	00010001 	andeq	r0, r1, r1
   10314:	0000005c 	andeq	r0, r0, ip, asr r0
   10318:	00000010 	andeq	r0, r0, r0, lsl r0
   1031c:	00000020 	andeq	r0, r0, r0, lsr #32
   10320:	0d696914 			; <UNDEFINED> instruction: 0x0d696914
   10324:	00040000 	andeq	r0, r4, r0
   10328:	0000006a 	andeq	r0, r0, sl, rrx
   1032c:	00000000 	andeq	r0, r0, r0
   10330:	00030001 	andeq	r0, r3, r1
   10334:	00000052 	andeq	r0, r0, r2, asr r0
   10338:	00000010 	andeq	r0, r0, r0, lsl r0
   1033c:	00000000 	andeq	r0, r0, r0
   10340:	0d696917 			; <UNDEFINED> instruction: 0x0d696917
   10344:	00050000 	andeq	r0, r5, r0
   10348:	00000074 	andeq	r0, r0, r4, ror r0
   1034c:	00000010 	andeq	r0, r0, r0, lsl r0
   10350:	0d696914 			; <UNDEFINED> instruction: 0x0d696914
   10354:	00030000 	andeq	r0, r3, r0
   10358:	0000006a 	andeq	r0, r0, sl, rrx
   1035c:	00000010 	andeq	r0, r0, r0, lsl r0
   10360:	069691b4 			; <UNDEFINED> instruction: 0x069691b4
   10364:	00020000 	andeq	r0, r2, r0
   10368:	0000007e 	andeq	r0, r0, lr, ror r0
   1036c:	00000000 	andeq	r0, r0, r0

Disassembly of section .rel.dyn:

00010370 <.rel.dyn>:
   10370:	00021024 	andeq	r1, r2, r4, lsr #32
   10374:	00000115 	andeq	r0, r0, r5, lsl r1
   10378:	00020f08 	andeq	r0, r2, r8, lsl #30
   1037c:	00000214 	andeq	r0, r0, r4, lsl r2

Disassembly of section .rel.plt:

00010380 <.rel.plt>:
   10380:	0002100c 	andeq	r1, r2, ip
   10384:	00000616 	andeq	r0, r0, r6, lsl r6
   10388:	00021010 	andeq	r1, r2, r0, lsl r0
   1038c:	00000416 	andeq	r0, r0, r6, lsl r4
   10390:	00021014 	andeq	r1, r2, r4, lsl r0
   10394:	00000716 	andeq	r0, r0, r6, lsl r7
   10398:	00021018 	andeq	r1, r2, r8, lsl r0
   1039c:	00000116 	andeq	r0, r0, r6, lsl r1
   103a0:	0002101c 	andeq	r1, r2, ip, lsl r0
   103a4:	00000316 	andeq	r0, r0, r6, lsl r3
   103a8:	00021020 	andeq	r1, r2, r0, lsr #32
   103ac:	00000516 	andeq	r0, r0, r6, lsl r5

Disassembly of section .init:

000103b0 <_init>:
   103b0:	e92d4008 	push	{r3, lr}
   103b4:	eb000028 	bl	1045c <call_weak_fn>
   103b8:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000103bc <.plt>:
   103bc:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
   103c0:	e59fe004 	ldr	lr, [pc, #4]	; 103cc <.plt+0x10>
   103c4:	e08fe00e 	add	lr, pc, lr
   103c8:	e5bef008 	ldr	pc, [lr, #8]!
   103cc:	00010c34 	andeq	r0, r1, r4, lsr ip

000103d0 <__libc_start_main@plt>:
   103d0:	e28fc600 	add	ip, pc, #0, 12
   103d4:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103d8:	e5bcfc34 	ldr	pc, [ip, #3124]!	; 0xc34

000103dc <printf@plt>:
   103dc:	e28fc600 	add	ip, pc, #0, 12
   103e0:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103e4:	e5bcfc2c 	ldr	pc, [ip, #3116]!	; 0xc2c

000103e8 <__stack_chk_fail@plt>:
   103e8:	e28fc600 	add	ip, pc, #0, 12
   103ec:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103f0:	e5bcfc24 	ldr	pc, [ip, #3108]!	; 0xc24

000103f4 <__gmon_start__@plt>:
   103f4:	e28fc600 	add	ip, pc, #0, 12
   103f8:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   103fc:	e5bcfc1c 	ldr	pc, [ip, #3100]!	; 0xc1c

00010400 <__isoc99_scanf@plt>:
   10400:	e28fc600 	add	ip, pc, #0, 12
   10404:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10408:	e5bcfc14 	ldr	pc, [ip, #3092]!	; 0xc14

0001040c <abort@plt>:
   1040c:	e28fc600 	add	ip, pc, #0, 12
   10410:	e28cca10 	add	ip, ip, #16, 20	; 0x10000
   10414:	e5bcfc0c 	ldr	pc, [ip, #3084]!	; 0xc0c

Disassembly of section .text:

00010418 <_start>:
   10418:	e3a0b000 	mov	fp, #0
   1041c:	e3a0e000 	mov	lr, #0
   10420:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
   10424:	e1a0200d 	mov	r2, sp
   10428:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
   1042c:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
   10430:	e59fa01c 	ldr	sl, [pc, #28]	; 10454 <_start+0x3c>
   10434:	e28f3018 	add	r3, pc, #24
   10438:	e08aa003 	add	sl, sl, r3
   1043c:	e3a03000 	mov	r3, #0
   10440:	e52d3004 	push	{r3}		; (str r3, [sp, #-4]!)
   10444:	e59f000c 	ldr	r0, [pc, #12]	; 10458 <_start+0x40>
   10448:	e79a0000 	ldr	r0, [sl, r0]
   1044c:	ebffffdf 	bl	103d0 <__libc_start_main@plt>
   10450:	ebffffed 	bl	1040c <abort@plt>
   10454:	00010bac 	andeq	r0, r1, ip, lsr #23
   10458:	00000028 	andeq	r0, r0, r8, lsr #32

0001045c <call_weak_fn>:
   1045c:	e59f3014 	ldr	r3, [pc, #20]	; 10478 <call_weak_fn+0x1c>
   10460:	e59f2014 	ldr	r2, [pc, #20]	; 1047c <call_weak_fn+0x20>
   10464:	e08f3003 	add	r3, pc, r3
   10468:	e7932002 	ldr	r2, [r3, r2]
   1046c:	e3520000 	cmp	r2, #0
   10470:	012fff1e 	bxeq	lr
   10474:	eaffffde 	b	103f4 <__gmon_start__@plt>
   10478:	00010b94 	muleq	r1, r4, fp
   1047c:	00000024 	andeq	r0, r0, r4, lsr #32

00010480 <deregister_tm_clones>:
   10480:	e59f0018 	ldr	r0, [pc, #24]	; 104a0 <deregister_tm_clones+0x20>
   10484:	e59f3018 	ldr	r3, [pc, #24]	; 104a4 <deregister_tm_clones+0x24>
   10488:	e1530000 	cmp	r3, r0
   1048c:	012fff1e 	bxeq	lr
   10490:	e59f3010 	ldr	r3, [pc, #16]	; 104a8 <deregister_tm_clones+0x28>
   10494:	e3530000 	cmp	r3, #0
   10498:	012fff1e 	bxeq	lr
   1049c:	e12fff13 	bx	r3
   104a0:	00021034 	andeq	r1, r2, r4, lsr r0
   104a4:	00021034 	andeq	r1, r2, r4, lsr r0
   104a8:	00000000 	andeq	r0, r0, r0

000104ac <register_tm_clones>:
   104ac:	e59f0024 	ldr	r0, [pc, #36]	; 104d8 <register_tm_clones+0x2c>
   104b0:	e59f3024 	ldr	r3, [pc, #36]	; 104dc <register_tm_clones+0x30>
   104b4:	e0433000 	sub	r3, r3, r0
   104b8:	e1a01fa3 	lsr	r1, r3, #31
   104bc:	e0811143 	add	r1, r1, r3, asr #2
   104c0:	e1b010c1 	asrs	r1, r1, #1
   104c4:	012fff1e 	bxeq	lr
   104c8:	e59f3010 	ldr	r3, [pc, #16]	; 104e0 <register_tm_clones+0x34>
   104cc:	e3530000 	cmp	r3, #0
   104d0:	012fff1e 	bxeq	lr
   104d4:	e12fff13 	bx	r3
   104d8:	00021034 	andeq	r1, r2, r4, lsr r0
   104dc:	00021034 	andeq	r1, r2, r4, lsr r0
   104e0:	00000000 	andeq	r0, r0, r0

000104e4 <__do_global_dtors_aux>:
   104e4:	e92d4010 	push	{r4, lr}
   104e8:	e59f4018 	ldr	r4, [pc, #24]	; 10508 <__do_global_dtors_aux+0x24>
   104ec:	e5d43000 	ldrb	r3, [r4]
   104f0:	e3530000 	cmp	r3, #0
   104f4:	18bd8010 	popne	{r4, pc}
   104f8:	ebffffe0 	bl	10480 <deregister_tm_clones>
   104fc:	e3a03001 	mov	r3, #1
   10500:	e5c43000 	strb	r3, [r4]
   10504:	e8bd8010 	pop	{r4, pc}
   10508:	00021034 	andeq	r1, r2, r4, lsr r0

0001050c <frame_dummy>:
   1050c:	eaffffe6 	b	104ac <register_tm_clones>

00010510 <main>:
   10510:	e92d4800 	push	{fp, lr}
   10514:	e28db004 	add	fp, sp, #4
   10518:	e24dd010 	sub	sp, sp, #16
   1051c:	e50b0010 	str	r0, [fp, #-16]
   10520:	e50b1014 	str	r1, [fp, #-20]	; 0xffffffec
   10524:	e59f3094 	ldr	r3, [pc, #148]	; 105c0 <main+0xb0>
   10528:	e5933000 	ldr	r3, [r3]
   1052c:	e50b3008 	str	r3, [fp, #-8]
   10530:	e3a03000 	mov	r3, #0
   10534:	e24b300c 	sub	r3, fp, #12
   10538:	e1a01003 	mov	r1, r3
   1053c:	e59f0080 	ldr	r0, [pc, #128]	; 105c4 <main+0xb4>
   10540:	ebffffae 	bl	10400 <__isoc99_scanf@plt>
   10544:	e51b300c 	ldr	r3, [fp, #-12]
   10548:	e3530000 	cmp	r3, #0
   1054c:	03a03001 	moveq	r3, #1
   10550:	13a03000 	movne	r3, #0
   10554:	e20330ff 	and	r3, r3, #255	; 0xff
   10558:	e3530000 	cmp	r3, #0
   1055c:	0a000006 	beq	1057c <main+0x6c>
   10560:	e3a01001 	mov	r1, #1
   10564:	e59f0058 	ldr	r0, [pc, #88]	; 105c4 <main+0xb4>
   10568:	ebffff9b 	bl	103dc <printf@plt>
   1056c:	e3a01002 	mov	r1, #2
   10570:	e59f0050 	ldr	r0, [pc, #80]	; 105c8 <main+0xb8>
   10574:	ebffff98 	bl	103dc <printf@plt>
   10578:	ea000005 	b	10594 <main+0x84>
   1057c:	e3a01005 	mov	r1, #5
   10580:	e59f003c 	ldr	r0, [pc, #60]	; 105c4 <main+0xb4>
   10584:	ebffff94 	bl	103dc <printf@plt>
   10588:	e3a01006 	mov	r1, #6
   1058c:	e59f0034 	ldr	r0, [pc, #52]	; 105c8 <main+0xb8>
   10590:	ebffff91 	bl	103dc <printf@plt>
   10594:	e3a03000 	mov	r3, #0
   10598:	e59f2020 	ldr	r2, [pc, #32]	; 105c0 <main+0xb0>
   1059c:	e5921000 	ldr	r1, [r2]
   105a0:	e51b2008 	ldr	r2, [fp, #-8]
   105a4:	e0321001 	eors	r1, r2, r1
   105a8:	e3a02000 	mov	r2, #0
   105ac:	0a000000 	beq	105b4 <main+0xa4>
   105b0:	ebffff8c 	bl	103e8 <__stack_chk_fail@plt>
   105b4:	e1a00003 	mov	r0, r3
   105b8:	e24bd004 	sub	sp, fp, #4
   105bc:	e8bd8800 	pop	{fp, pc}
   105c0:	00020f08 	andeq	r0, r2, r8, lsl #30
   105c4:	00010668 	andeq	r0, r1, r8, ror #12
   105c8:	0001066c 	andeq	r0, r1, ip, ror #12

Disassembly of section .fini:

000105cc <_fini>:
   105cc:	e92d4008 	push	{r3, lr}
   105d0:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

000105d4 <_IO_stdin_used>:
   105d4:	00020001 	andeq	r0, r2, r1

000105d8 <all_implied_fbits>:
   105d8:	0000003b 	andeq	r0, r0, fp, lsr r0
   105dc:	0000003e 	andeq	r0, r0, lr, lsr r0
   105e0:	0000000b 	andeq	r0, r0, fp
   105e4:	0000003e 	andeq	r0, r0, lr, lsr r0
   105e8:	00000010 	andeq	r0, r0, r0, lsl r0
   105ec:	0000003e 	andeq	r0, r0, lr, lsr r0
   105f0:	00000025 	andeq	r0, r0, r5, lsr #32
   105f4:	0000003e 	andeq	r0, r0, lr, lsr r0
   105f8:	00000033 	andeq	r0, r0, r3, lsr r0
   105fc:	0000003e 	andeq	r0, r0, lr, lsr r0
   10600:	00000003 	andeq	r0, r0, r3
   10604:	0000003e 	andeq	r0, r0, lr, lsr r0
   10608:	00000006 	andeq	r0, r0, r6
   1060c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10610:	00000014 	andeq	r0, r0, r4, lsl r0
   10614:	0000003e 	andeq	r0, r0, lr, lsr r0
   10618:	0000000e 	andeq	r0, r0, lr
   1061c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10620:	0000000d 	andeq	r0, r0, sp
   10624:	0000003e 	andeq	r0, r0, lr, lsr r0
   10628:	00000024 	andeq	r0, r0, r4, lsr #32
   1062c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10630:	00000012 	andeq	r0, r0, r2, lsl r0
   10634:	0000003e 	andeq	r0, r0, lr, lsr r0
   10638:	00000027 	andeq	r0, r0, r7, lsr #32
   1063c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10640:	00000002 	andeq	r0, r0, r2
   10644:	0000003e 	andeq	r0, r0, lr, lsr r0
   10648:	00000018 	andeq	r0, r0, r8, lsl r0
   1064c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10650:	00000009 	andeq	r0, r0, r9
   10654:	0000003e 	andeq	r0, r0, lr, lsr r0
   10658:	0000000a 	andeq	r0, r0, sl
   1065c:	0000003e 	andeq	r0, r0, lr, lsr r0
	...
   10668:	00006425 	andeq	r6, r0, r5, lsr #8
   1066c:	000a6425 	andeq	r6, sl, r5, lsr #8

00010670 <all_implied_fbits>:
   10670:	0000003b 	andeq	r0, r0, fp, lsr r0
   10674:	0000003e 	andeq	r0, r0, lr, lsr r0
   10678:	0000000b 	andeq	r0, r0, fp
   1067c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10680:	00000010 	andeq	r0, r0, r0, lsl r0
   10684:	0000003e 	andeq	r0, r0, lr, lsr r0
   10688:	00000025 	andeq	r0, r0, r5, lsr #32
   1068c:	0000003e 	andeq	r0, r0, lr, lsr r0
   10690:	00000033 	andeq	r0, r0, r3, lsr r0
   10694:	0000003e 	andeq	r0, r0, lr, lsr r0
   10698:	00000003 	andeq	r0, r0, r3
   1069c:	0000003e 	andeq	r0, r0, lr, lsr r0
   106a0:	00000006 	andeq	r0, r0, r6
   106a4:	0000003e 	andeq	r0, r0, lr, lsr r0
   106a8:	00000014 	andeq	r0, r0, r4, lsl r0
   106ac:	0000003e 	andeq	r0, r0, lr, lsr r0
   106b0:	0000000e 	andeq	r0, r0, lr
   106b4:	0000003e 	andeq	r0, r0, lr, lsr r0
   106b8:	0000000d 	andeq	r0, r0, sp
   106bc:	0000003e 	andeq	r0, r0, lr, lsr r0
   106c0:	00000024 	andeq	r0, r0, r4, lsr #32
   106c4:	0000003e 	andeq	r0, r0, lr, lsr r0
   106c8:	00000012 	andeq	r0, r0, r2, lsl r0
   106cc:	0000003e 	andeq	r0, r0, lr, lsr r0
   106d0:	00000027 	andeq	r0, r0, r7, lsr #32
   106d4:	0000003e 	andeq	r0, r0, lr, lsr r0
   106d8:	00000002 	andeq	r0, r0, r2
   106dc:	0000003e 	andeq	r0, r0, lr, lsr r0
   106e0:	00000018 	andeq	r0, r0, r8, lsl r0
   106e4:	0000003e 	andeq	r0, r0, lr, lsr r0
   106e8:	00000009 	andeq	r0, r0, r9
   106ec:	0000003e 	andeq	r0, r0, lr, lsr r0
   106f0:	0000000a 	andeq	r0, r0, sl
   106f4:	0000003e 	andeq	r0, r0, lr, lsr r0
	...

Disassembly of section .ARM.exidx:

00010700 <.ARM.exidx>:
   10700:	7ffffd18 	svcvc	0x00fffd18
   10704:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

00010708 <__FRAME_END__>:
   10708:	00000000 	andeq	r0, r0, r0

Disassembly of section .init_array:

00020f00 <__frame_dummy_init_array_entry>:
   20f00:	0001050c 	andeq	r0, r1, ip, lsl #10

Disassembly of section .fini_array:

00020f04 <__do_global_dtors_aux_fini_array_entry>:
   20f04:	000104e4 	andeq	r0, r1, r4, ror #9

Disassembly of section .data.rel.ro:

00020f08 <__stack_chk_guard@GLIBC_2.4>:
   20f08:	00000000 	andeq	r0, r0, r0

Disassembly of section .dynamic:

00020f0c <_DYNAMIC>:
   20f0c:	00000001 	andeq	r0, r0, r1
   20f10:	00000052 	andeq	r0, r0, r2, asr r0
   20f14:	00000001 	andeq	r0, r0, r1
   20f18:	0000005c 	andeq	r0, r0, ip, asr r0
   20f1c:	0000000c 	andeq	r0, r0, ip
   20f20:	000103b0 			; <UNDEFINED> instruction: 0x000103b0
   20f24:	0000000d 	andeq	r0, r0, sp
   20f28:	000105cc 	andeq	r0, r1, ip, asr #11
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
   20f68:	00000098 	muleq	r0, r8, r0
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
   20f98:	00010380 	andeq	r0, r1, r0, lsl #7
   20f9c:	00000011 	andeq	r0, r0, r1, lsl r0
   20fa0:	00010370 	andeq	r0, r1, r0, ror r3
   20fa4:	00000012 	andeq	r0, r0, r2, lsl r0
   20fa8:	00000010 	andeq	r0, r0, r0, lsl r0
   20fac:	00000013 	andeq	r0, r0, r3, lsl r0
   20fb0:	00000008 	andeq	r0, r0, r8
   20fb4:	6ffffffe 	svcvs	0x00fffffe
   20fb8:	00010310 	andeq	r0, r1, r0, lsl r3
   20fbc:	6fffffff 	svcvs	0x00ffffff
   20fc0:	00000002 	andeq	r0, r0, r2
   20fc4:	6ffffff0 	svcvs	0x00fffff0
   20fc8:	00010300 	andeq	r0, r1, r0, lsl #6
	...

Disassembly of section .got:

00021000 <_GLOBAL_OFFSET_TABLE_>:
   21000:	00020f0c 	andeq	r0, r2, ip, lsl #30
	...
   2100c:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   21010:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   21014:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   21018:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   2101c:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   21020:	000103bc 			; <UNDEFINED> instruction: 0x000103bc
   21024:	00000000 	andeq	r0, r0, r0
   21028:	00010510 	andeq	r0, r1, r0, lsl r5

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

