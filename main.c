#include <stdio.h>

#include <stdlib.h>

int main()

{

    //��������

    int len = 0;

    //��ȡ����ĳ���

    scanf("%d", &len);

    //��̬��������

    int * a;

    int * b;

    a = (int *)malloc(sizeof(int) * len);

    b = (int *)malloc(sizeof(int) * len);

    //��ȡÿ�������Ԫ��

    for(int i=0; i < len; i++)

    {

        scanf("%d", &a[i]);

    }

    for(int j=0; j < len; j++)

    {

        scanf("%d", &b[j]);

    }

    //������������Ҷ˵������

    int aLeft = 0;

    int aRight = len - 1;

    int bLeft = 0;

    int bRight = len - 1;

    //�������м�����

    int aMid = 0;

    int bMid = 0;

    //����ѭ��

    while(true)

    {

        //printf("a left is %d right is %d, and b left is %d right is %d.\n", aLeft, aRight, bLeft, bRight);

        //  ����������鶼ֻʣ������Ԫ�أ�����λ��һ��������

        if( (aRight - aLeft) == 1 && (bRight - bLeft) == 1)

        {

            //  �����һ�е����һ��ֵ

            printf("%d ", (a[aLeft]>=b[bLeft])?a[aLeft]:b[bLeft]);

            //  �����һ�е���Сһ��ֵ

            printf("%d\n", (a[aRight]<=b[bRight])?a[aRight]:b[bRight]);

            //  ����ѭ��

            break;

        }

        else

        {

            //  �������������ֵ

            aMid = (int)((aLeft + aRight)/2);

            bMid = (int)((bLeft + bRight)/2);

            //  ���A��ֵС��B��ֵ

            if(a[aMid] < b[bMid])

            {

                //  ���B���ִ��������ż�������ұ�ֵ��һ

                if((bLeft + bRight + 1) % 2 == 0) {

                    aLeft = aMid;

                    bRight = bMid + 1;

                }

                else {

                    aLeft = aMid;

                    bRight = bMid;

                }

            }

            //  ���B��ֵС��A��ֵ

            else

            {

                //  ���A���ִ��������ż�������ұ�ֵ��һ

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