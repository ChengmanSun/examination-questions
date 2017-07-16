#include <stdio.h>

int main(void)
{
	struct {
		short a;
		short b;
		char c;
		char d;
	} t = {0, 0, 0, 0};

	sscanf("fffff fff", "%hx %Lx", &t.a, &t.c);
	printf("t.a=%d t.b= %d t.c=%d t.d=%d\n", t.a, t.b, t.c, t.d);
    fflush(stdout);
	getchar();
	return 0;
}
