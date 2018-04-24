/*
********************************************************************************
*                              COPYRIGHT NOTICE
*                             Copyright (c) 2016
*                             All rights reserved
*
*  @FileName       : 浮点数大小以及隐式转换.c
*  @Author         : scm 351721714@qq.com
*  @Create         : 2018/04/24 21:54:33
*  @Last Modified  : 2018/04/24 22:49:37
********************************************************************************
*/

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    uint64_t value = 0x2000000;
    float add = 2;
    value += add;
    printf("%llx\n", value);
    return 0;
}

/*
 * 以上的代码输出为：0x2000000，为什么不是0x2000002呢？
 * 原因是浮点数与整数进行计算时，整数会隐式转换成浮点数，
 * 然后再进行计算。单精度浮点数float如果用来表示整数，则
 * 能表示的最大值为0x2000000。所以上面的代码中value被强
 * 转成了float，如果value的值大于0x2000000则会数据错乱，
 * 如果value的值正好等于0x2000000则会转换成相应大小的float。
 * 而大小为0x2000000的数已经是float能表示的最大整数，加
 * 上其他值也不会再增大，同时也不会变成负的单精度浮点数。
 * 想要得出正确的结果，则应该使用以下两种方法：
 */

//方法一：使用双精度浮点数，这样value就会隐式转换成double
/*
 * int main(int argc, char *argv[])
 * {
 *     uint64_t value = 0x2000000;
 *     double add = 2;
 *     value += add;
 *     printf("%llx\n", value);
 *     getchar();
 *     return 0;
 * }
 */

//方法二：将add强换成整数，这样value就不会被隐式转换成float
/*
 * int main(int argc, char *argv[])
 * {
 *     uint64_t value = 0x2000000;
 *     float add = 2;
 *     value += (int)add;
 *     printf("%llx\n", value);
 *     getchar();
 *     return 0;
 * }
 */

