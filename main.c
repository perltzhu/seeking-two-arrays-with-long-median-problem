#include <stdio.h>

#include <stdlib.h>

int main()

{

    //两个数组

    int len = 0;

    //获取数组的长度

    scanf("%d", &len);

    //动态分配数组

    int * a;

    int * b;

    a = (int *)malloc(sizeof(int) * len);

    b = (int *)malloc(sizeof(int) * len);

    //获取每个数组的元素

    for(int i=0; i < len; i++)

    {

        scanf("%d", &a[i]);

    }

    for(int j=0; j < len; j++)

    {

        scanf("%d", &b[j]);

    }

    //两个数组的左右端点的坐标

    int aLeft = 0;

    int aRight = len - 1;

    int bLeft = 0;

    int bRight = len - 1;

    //两数组中间坐标

    int aMid = 0;

    int bMid = 0;

    //迭代循环

    while(true)

    {

        //printf("a left is %d right is %d, and b left is %d right is %d.\n", aLeft, aRight, bLeft, bRight);

        //  如果两个数组都只剩下两个元素，则中位数一定在其中

        if( (aRight - aLeft) == 1 && (bRight - bLeft) == 1)

        {

            //  输出第一行的最大一个值

            printf("%d ", (a[aLeft]>=b[bLeft])?a[aLeft]:b[bLeft]);

            //  输出第一行的最小一个值

            printf("%d\n", (a[aRight]<=b[bRight])?a[aRight]:b[bRight]);

            //  结束循环

            break;

        }

        else

        {

            //  求解各个数组的中值

            aMid = (int)((aLeft + aRight)/2);

            bMid = (int)((bLeft + bRight)/2);

            //  如果A中值小于B中值

            if(a[aMid] < b[bMid])

            {

                //  如果B中现存的数列是偶数个，右边值加一

                if((bLeft + bRight + 1) % 2 == 0) {

                    aLeft = aMid;

                    bRight = bMid + 1;

                }

                else {

                    aLeft = aMid;

                    bRight = bMid;

                }

            }

            //  如果B中值小于A中值

            else

            {

                //  如果A中现存的数列是偶数个，右边值加一

                if((aLeft + aRight + 1) % 2 == 0) {

                    aRight = aMid + 1;

                    bLeft = bMid;

                }

                else {

                    aRight = aMid;

                    bLeft = bMid;

                }  

            }

        }

    }

    return 0;

}