#source: sve-movprfx_12.s
#as: -march=armv8-a+sve -I$srcdir/$subdir
#objdump: -Dr -M notes

.* file format .*

Disassembly of section .*:

0+ <.*>:
[^:]+:	2598e3e0 	ptrue	p0.s
[^:]+:	04902461 	movprfx	z1.s, p1/z, z3.s
[^:]+:	0497a441 	neg	z1.s, p1/m, z2.s
[^:]+:	d65f03c0 	ret
