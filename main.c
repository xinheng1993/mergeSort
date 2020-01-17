#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSortArray.h"
#include "mergeSortPointer.h"

int main()
{

    int a[9]= {3,1,2,5,9,12,10,11,0};
    int b[]= {3,1,2,5,9,12,10,11,4,3};
    MergeSortArr(a,0,sizeof(a)/sizeof(a[0]));
    MergeSortPointer(b,sizeof(b)/sizeof(b[0]));
    size_t i;
    printf("merge sort fix\n");
    for(i = 0; i<8; ++i)
    {
        printf("%d\n",a[i]);
    }
    printf("merge sort dynamic allocate memory\n");
    for(i = 0; i<8; ++i)
    {
        printf("%d\n",b[i]);
    }
    system("pause");
    return 0;
}
