#include <stdio.h>

void show(const char *format, ...)
{
    char **pfmt = (char **)&format;
    long long *a = (long long *)(pfmt + 1);
    long long *b = a + 1;
    long long *c = b + 1;
    double *f = (double *)(c + 1);

    printf("%d, %d, %d, %lf\n", *a, *b, *c, *f);
}

int main(void)
{
    char a = 8;
    char b = 9;
    float f = 1.2;
    char c = 2;
    show("%d, %d, %d, %f\n", a, b, c, f);
    printf("%d\n", (10 & ~11));
    fflush(stdout);
    getchar();
    return 0;
}
