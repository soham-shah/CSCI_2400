#include <limits.h>
#include <stdio.h>

int logicalShift(int x, int n) {
	int mask = (1 << 31);
	printf("%#010x\n", mask);
	mask = mask >> (~n+1);
	printf("%#010x\n", mask);
	return ((x >> n) & mask);
}

int main()
{
	logicalShift(200000, 3);
}