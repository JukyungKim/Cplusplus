	.file	"Factory.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.section	.text$_ZN8IFactoryD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8IFactoryD2Ev
	.def	_ZN8IFactoryD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8IFactoryD2Ev
_ZN8IFactoryD2Ev:
.LFB1574:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV8IFactory(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN8FactoryA6createEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8FactoryA6createEv
	.def	_ZN8FactoryA6createEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8FactoryA6createEv
_ZN8FactoryA6createEv:
.LFB1577:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN8FactoryAD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8FactoryAD1Ev
	.def	_ZN8FactoryAD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8FactoryAD1Ev
_ZN8FactoryAD1Ev:
.LFB1580:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV8FactoryA(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8IFactoryD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN8FactoryAD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8FactoryAD0Ev
	.def	_ZN8FactoryAD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8FactoryAD0Ev
_ZN8FactoryAD0Ev:
.LFB1581:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN8FactoryAD1Ev
	movl	$8, %edx
	movq	16(%rbp), %rcx
	call	_ZdlPvy
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN8IFactoryC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8IFactoryC2Ev
	.def	_ZN8IFactoryC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8IFactoryC2Ev
_ZN8IFactoryC2Ev:
.LFB1585:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV8IFactory(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN8FactoryAC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN8FactoryAC1Ev
	.def	_ZN8FactoryAC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8FactoryAC1Ev
_ZN8FactoryAC1Ev:
.LFB1588:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8IFactoryC2Ev
	leaq	16+_ZTV8FactoryA(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1582:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	movl	$8, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movq	$0, (%rbx)
	movq	%rbx, %rcx
	call	_ZN8FactoryAC1Ev
	movq	%rbx, -88(%rbp)
	movl	$0, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV8FactoryA
	.section	.rdata$_ZTV8FactoryA,"dr"
	.linkonce same_size
	.align 8
_ZTV8FactoryA:
	.quad	0
	.quad	_ZTI8FactoryA
	.quad	_ZN8FactoryA6createEv
	.quad	_ZN8FactoryAD1Ev
	.quad	_ZN8FactoryAD0Ev
	.globl	_ZTV8IFactory
	.section	.rdata$_ZTV8IFactory,"dr"
	.linkonce same_size
	.align 8
_ZTV8IFactory:
	.quad	0
	.quad	_ZTI8IFactory
	.quad	__cxa_pure_virtual
	.quad	0
	.quad	0
	.globl	_ZTI8FactoryA
	.section	.rdata$_ZTI8FactoryA,"dr"
	.linkonce same_size
	.align 8
_ZTI8FactoryA:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS8FactoryA
	.quad	_ZTI8IFactory
	.globl	_ZTS8FactoryA
	.section	.rdata$_ZTS8FactoryA,"dr"
	.linkonce same_size
	.align 8
_ZTS8FactoryA:
	.ascii "8FactoryA\0"
	.globl	_ZTI8IFactory
	.section	.rdata$_ZTI8IFactory,"dr"
	.linkonce same_size
	.align 8
_ZTI8IFactory:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS8IFactory
	.globl	_ZTS8IFactory
	.section	.rdata$_ZTS8IFactory,"dr"
	.linkonce same_size
	.align 8
_ZTS8IFactory:
	.ascii "8IFactory\0"
	.text
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2070:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2069:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L12
	cmpl	$65535, 24(%rbp)
	jne	.L12
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L12:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB2071:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__cxa_pure_virtual;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
