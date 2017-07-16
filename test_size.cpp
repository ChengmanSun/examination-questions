#include <stdio.h>

int main()
{
    struct {
        long a;
        char c;
    }t;
    printf("struct:%d\n", sizeof(t));
    printf(" char:%d\n short:%d\n int:%d\n long:%d\n long long:%d\n float:%d\n double:%d\n void*:%d",
            sizeof(char), sizeof(short), sizeof(int), sizeof(long int), sizeof(long long),
            sizeof(float), sizeof(double),sizeof(void *));
    fflush(stdout);
    getchar();
    return 0;
}
