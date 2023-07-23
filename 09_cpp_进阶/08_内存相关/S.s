
a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 e1 2f 00 00 	mov    0x2fe1(%rip),%rax        # 3ff0 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 82 2f 00 00    	pushq  0x2f82(%rip)        # 3fa8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 83 2f 00 00 	bnd jmpq *0x2f83(%rip)        # 3fb0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
    1050:	f3 0f 1e fa          	endbr64 
    1054:	68 02 00 00 00       	pushq  $0x2
    1059:	f2 e9 c1 ff ff ff    	bnd jmpq 1020 <.plt>
    105f:	90                   	nop
    1060:	f3 0f 1e fa          	endbr64 
    1064:	68 03 00 00 00       	pushq  $0x3
    1069:	f2 e9 b1 ff ff ff    	bnd jmpq 1020 <.plt>
    106f:	90                   	nop

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 5d 2f 00 00 	bnd jmpq *0x2f5d(%rip)        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001080 <printf@plt>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	f2 ff 25 2d 2f 00 00 	bnd jmpq *0x2f2d(%rip)        # 3fb8 <printf@GLIBC_2.2.5>
    108b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001090 <_Znwm@plt>:
    1090:	f3 0f 1e fa          	endbr64 
    1094:	f2 ff 25 25 2f 00 00 	bnd jmpq *0x2f25(%rip)        # 3fc0 <_Znwm@GLIBCXX_3.4>
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <__stack_chk_fail@plt>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	f2 ff 25 1d 2f 00 00 	bnd jmpq *0x2f1d(%rip)        # 3fc8 <__stack_chk_fail@GLIBC_2.4>
    10ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010b0 <malloc@plt>:
    10b0:	f3 0f 1e fa          	endbr64 
    10b4:	f2 ff 25 15 2f 00 00 	bnd jmpq *0x2f15(%rip)        # 3fd0 <malloc@GLIBC_2.2.5>
    10bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

00000000000010c0 <_start>:
    10c0:	f3 0f 1e fa          	endbr64 
    10c4:	31 ed                	xor    %ebp,%ebp
    10c6:	49 89 d1             	mov    %rdx,%r9
    10c9:	5e                   	pop    %rsi
    10ca:	48 89 e2             	mov    %rsp,%rdx
    10cd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10d1:	50                   	push   %rax
    10d2:	54                   	push   %rsp
    10d3:	4c 8d 05 86 02 00 00 	lea    0x286(%rip),%r8        # 1360 <__libc_csu_fini>
    10da:	48 8d 0d 0f 02 00 00 	lea    0x20f(%rip),%rcx        # 12f0 <__libc_csu_init>
    10e1:	48 8d 3d c1 00 00 00 	lea    0xc1(%rip),%rdi        # 11a9 <main>
    10e8:	ff 15 fa 2e 00 00    	callq  *0x2efa(%rip)        # 3fe8 <__libc_start_main@GLIBC_2.2.5>
    10ee:	f4                   	hlt    
    10ef:	90                   	nop

00000000000010f0 <deregister_tm_clones>:
    10f0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4040 <__TMC_END__>
    10f7:	48 8d 05 42 2f 00 00 	lea    0x2f42(%rip),%rax        # 4040 <__TMC_END__>
    10fe:	48 39 f8             	cmp    %rdi,%rax
    1101:	74 15                	je     1118 <deregister_tm_clones+0x28>
    1103:	48 8b 05 d6 2e 00 00 	mov    0x2ed6(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable>
    110a:	48 85 c0             	test   %rax,%rax
    110d:	74 09                	je     1118 <deregister_tm_clones+0x28>
    110f:	ff e0                	jmpq   *%rax
    1111:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <register_tm_clones>:
    1120:	48 8d 3d 19 2f 00 00 	lea    0x2f19(%rip),%rdi        # 4040 <__TMC_END__>
    1127:	48 8d 35 12 2f 00 00 	lea    0x2f12(%rip),%rsi        # 4040 <__TMC_END__>
    112e:	48 29 fe             	sub    %rdi,%rsi
    1131:	48 89 f0             	mov    %rsi,%rax
    1134:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1138:	48 c1 f8 03          	sar    $0x3,%rax
    113c:	48 01 c6             	add    %rax,%rsi
    113f:	48 d1 fe             	sar    %rsi
    1142:	74 14                	je     1158 <register_tm_clones+0x38>
    1144:	48 8b 05 ad 2e 00 00 	mov    0x2ead(%rip),%rax        # 3ff8 <_ITM_registerTMCloneTable>
    114b:	48 85 c0             	test   %rax,%rax
    114e:	74 08                	je     1158 <register_tm_clones+0x38>
    1150:	ff e0                	jmpq   *%rax
    1152:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <__do_global_dtors_aux>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	80 3d d5 2e 00 00 00 	cmpb   $0x0,0x2ed5(%rip)        # 4040 <__TMC_END__>
    116b:	75 2b                	jne    1198 <__do_global_dtors_aux+0x38>
    116d:	55                   	push   %rbp
    116e:	48 83 3d 62 2e 00 00 	cmpq   $0x0,0x2e62(%rip)        # 3fd8 <__cxa_finalize@GLIBC_2.2.5>
    1175:	00 
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	74 0c                	je     1187 <__do_global_dtors_aux+0x27>
    117b:	48 8b 3d 86 2e 00 00 	mov    0x2e86(%rip),%rdi        # 4008 <__dso_handle>
    1182:	e8 e9 fe ff ff       	callq  1070 <__cxa_finalize@plt>
    1187:	e8 64 ff ff ff       	callq  10f0 <deregister_tm_clones>
    118c:	c6 05 ad 2e 00 00 01 	movb   $0x1,0x2ead(%rip)        # 4040 <__TMC_END__>
    1193:	5d                   	pop    %rbp
    1194:	c3                   	retq   
    1195:	0f 1f 00             	nopl   (%rax)
    1198:	c3                   	retq   
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <frame_dummy>:
    11a0:	f3 0f 1e fa          	endbr64 
    11a4:	e9 77 ff ff ff       	jmpq   1120 <register_tm_clones>

00000000000011a9 <main>:
int a8 [] = {1, 2, 3, 4}; //.data

int *pp = (int *)malloc(sizeof(int) * 4); //.bss段

int main() //.text段
{
    11a9:	f3 0f 1e fa          	endbr64 
    11ad:	55                   	push   %rbp
    11ae:	48 89 e5             	mov    %rsp,%rbp
    11b1:	53                   	push   %rbx
    11b2:	48 83 ec 28          	sub    $0x28,%rsp
    11b6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    11bd:	00 00 
    11bf:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    11c3:	31 c0                	xor    %eax,%eax
    *pp = 7;
    11c5:	48 8b 05 84 2e 00 00 	mov    0x2e84(%rip),%rax        # 4050 <pp>
    11cc:	c7 00 07 00 00 00    	movl   $0x7,(%rax)

    int b1 = 1;
    11d2:	c7 45 d4 01 00 00 00 	movl   $0x1,-0x2c(%rbp)

    char sss[] = "abc";     
    11d9:	c7 45 e4 61 62 63 00 	movl   $0x636261,-0x1c(%rbp)

    Person *person = new Person(18);
    11e0:	bf 04 00 00 00       	mov    $0x4,%edi
    11e5:	e8 a6 fe ff ff       	callq  1090 <_Znwm@plt>
    11ea:	48 89 c3             	mov    %rax,%rbx
    11ed:	be 12 00 00 00       	mov    $0x12,%esi
    11f2:	48 89 df             	mov    %rbx,%rdi
    11f5:	e8 cc 00 00 00       	callq  12c6 <_ZN6PersonC1Ei>
    11fa:	48 89 5d d8          	mov    %rbx,-0x28(%rbp)

    printf("a1=%d, a2=%d, a3=%d\n", a1, a2, a3);
    11fe:	8b 0d 48 2e 00 00    	mov    0x2e48(%rip),%ecx        # 404c <a3>
    1204:	8b 15 3e 2e 00 00    	mov    0x2e3e(%rip),%edx        # 4048 <a2>
    120a:	8b 05 00 2e 00 00    	mov    0x2e00(%rip),%eax        # 4010 <a1>
    1210:	89 c6                	mov    %eax,%esi
    1212:	48 8d 3d 01 0e 00 00 	lea    0xe01(%rip),%rdi        # 201a <_ZL2a5+0x16>
    1219:	b8 00 00 00 00       	mov    $0x0,%eax
    121e:	e8 5d fe ff ff       	callq  1080 <printf@plt>
    printf("*pp=%d\n", *pp);
    1223:	48 8b 05 26 2e 00 00 	mov    0x2e26(%rip),%rax        # 4050 <pp>
    122a:	8b 00                	mov    (%rax),%eax
    122c:	89 c6                	mov    %eax,%esi
    122e:	48 8d 3d fa 0d 00 00 	lea    0xdfa(%rip),%rdi        # 202f <_ZL2a5+0x2b>
    1235:	b8 00 00 00 00       	mov    $0x0,%eax
    123a:	e8 41 fe ff ff       	callq  1080 <printf@plt>
    printf("person age=%d\n", person->age);
    123f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1243:	8b 00                	mov    (%rax),%eax
    1245:	89 c6                	mov    %eax,%esi
    1247:	48 8d 3d e9 0d 00 00 	lea    0xde9(%rip),%rdi        # 2037 <_ZL2a5+0x33>
    124e:	b8 00 00 00 00       	mov    $0x0,%eax
    1253:	e8 28 fe ff ff       	callq  1080 <printf@plt>

    return 0;
    1258:	b8 00 00 00 00       	mov    $0x0,%eax
}
    125d:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    1261:	64 48 33 14 25 28 00 	xor    %fs:0x28,%rdx
    1268:	00 00 
    126a:	74 05                	je     1271 <main+0xc8>
    126c:	e8 2f fe ff ff       	callq  10a0 <__stack_chk_fail@plt>
    1271:	48 83 c4 28          	add    $0x28,%rsp
    1275:	5b                   	pop    %rbx
    1276:	5d                   	pop    %rbp
    1277:	c3                   	retq   

0000000000001278 <_Z41__static_initialization_and_destruction_0ii>:
    1278:	f3 0f 1e fa          	endbr64 
    127c:	55                   	push   %rbp
    127d:	48 89 e5             	mov    %rsp,%rbp
    1280:	48 83 ec 10          	sub    $0x10,%rsp
    1284:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1287:	89 75 f8             	mov    %esi,-0x8(%rbp)
    128a:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    128e:	75 1a                	jne    12aa <_Z41__static_initialization_and_destruction_0ii+0x32>
    1290:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
    1297:	75 11                	jne    12aa <_Z41__static_initialization_and_destruction_0ii+0x32>
int *pp = (int *)malloc(sizeof(int) * 4); //.bss段
    1299:	bf 10 00 00 00       	mov    $0x10,%edi
    129e:	e8 0d fe ff ff       	callq  10b0 <malloc@plt>
    12a3:	48 89 05 a6 2d 00 00 	mov    %rax,0x2da6(%rip)        # 4050 <pp>
}
    12aa:	90                   	nop
    12ab:	c9                   	leaveq 
    12ac:	c3                   	retq   

00000000000012ad <_GLOBAL__sub_I_a1>:
    12ad:	f3 0f 1e fa          	endbr64 
    12b1:	55                   	push   %rbp
    12b2:	48 89 e5             	mov    %rsp,%rbp
    12b5:	be ff ff 00 00       	mov    $0xffff,%esi
    12ba:	bf 01 00 00 00       	mov    $0x1,%edi
    12bf:	e8 b4 ff ff ff       	callq  1278 <_Z41__static_initialization_and_destruction_0ii>
    12c4:	5d                   	pop    %rbp
    12c5:	c3                   	retq   

00000000000012c6 <_ZN6PersonC1Ei>:
    Person(int age) : age(age)
    12c6:	f3 0f 1e fa          	endbr64 
    12ca:	55                   	push   %rbp
    12cb:	48 89 e5             	mov    %rsp,%rbp
    12ce:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    12d2:	89 75 f4             	mov    %esi,-0xc(%rbp)
    12d5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    12d9:	8b 55 f4             	mov    -0xc(%rbp),%edx
    12dc:	89 10                	mov    %edx,(%rax)
    }
    12de:	90                   	nop
    12df:	5d                   	pop    %rbp
    12e0:	c3                   	retq   
    12e1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    12e8:	00 00 00 
    12eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000012f0 <__libc_csu_init>:
    12f0:	f3 0f 1e fa          	endbr64 
    12f4:	41 57                	push   %r15
    12f6:	4c 8d 3d 8b 2a 00 00 	lea    0x2a8b(%rip),%r15        # 3d88 <__frame_dummy_init_array_entry>
    12fd:	41 56                	push   %r14
    12ff:	49 89 d6             	mov    %rdx,%r14
    1302:	41 55                	push   %r13
    1304:	49 89 f5             	mov    %rsi,%r13
    1307:	41 54                	push   %r12
    1309:	41 89 fc             	mov    %edi,%r12d
    130c:	55                   	push   %rbp
    130d:	48 8d 2d 84 2a 00 00 	lea    0x2a84(%rip),%rbp        # 3d98 <__do_global_dtors_aux_fini_array_entry>
    1314:	53                   	push   %rbx
    1315:	4c 29 fd             	sub    %r15,%rbp
    1318:	48 83 ec 08          	sub    $0x8,%rsp
    131c:	e8 df fc ff ff       	callq  1000 <_init>
    1321:	48 c1 fd 03          	sar    $0x3,%rbp
    1325:	74 1f                	je     1346 <__libc_csu_init+0x56>
    1327:	31 db                	xor    %ebx,%ebx
    1329:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1330:	4c 89 f2             	mov    %r14,%rdx
    1333:	4c 89 ee             	mov    %r13,%rsi
    1336:	44 89 e7             	mov    %r12d,%edi
    1339:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    133d:	48 83 c3 01          	add    $0x1,%rbx
    1341:	48 39 dd             	cmp    %rbx,%rbp
    1344:	75 ea                	jne    1330 <__libc_csu_init+0x40>
    1346:	48 83 c4 08          	add    $0x8,%rsp
    134a:	5b                   	pop    %rbx
    134b:	5d                   	pop    %rbp
    134c:	41 5c                	pop    %r12
    134e:	41 5d                	pop    %r13
    1350:	41 5e                	pop    %r14
    1352:	41 5f                	pop    %r15
    1354:	c3                   	retq   
    1355:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    135c:	00 00 00 00 

0000000000001360 <__libc_csu_fini>:
    1360:	f3 0f 1e fa          	endbr64 
    1364:	c3                   	retq   

Disassembly of section .fini:

0000000000001368 <_fini>:
    1368:	f3 0f 1e fa          	endbr64 
    136c:	48 83 ec 08          	sub    $0x8,%rsp
    1370:	48 83 c4 08          	add    $0x8,%rsp
    1374:	c3                   	retq   
