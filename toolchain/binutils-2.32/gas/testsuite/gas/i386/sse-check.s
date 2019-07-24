# Check SSE instructions

	.text
_start:

# SSE instruction
	addps %xmm2,%xmm1

# SSE2 instruction
	addpd %xmm2,%xmm1

# SSE3 instruction
	addsubpd %xmm2,%xmm1

# SSSE3 instruction
	phaddw %xmm2,%xmm1

# SSE4 instructions
	blendvpd %xmm0,%xmm1,%xmm0
	pcmpgtq %xmm1,%xmm0

# PCMUL instruction
	pclmulqdq $-1,%xmm1,%xmm2

# AES instructions
	aesdec %xmm1,%xmm2

# GFNI instructions
	gf2p8mulb %xmm1,%xmm2
