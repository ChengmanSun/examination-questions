#include <stdint.h>
#include <stdio.h>
#include <string.h>

void test(void)
{
    char str[] = "112233445566778899";
    short c;
    int len = strlen(str)/2;
    for(int i = 0; i < len; ++i)
    {
        sscanf((char *)str+i*2, "%2hx", &c);
        printf("%2hx ", c);
    }
    printf("\n");
    printf("%#llx", (int64_t)0xaabbccddeeff1122);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

