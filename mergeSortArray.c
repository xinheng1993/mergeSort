#include "mergeSortArray.h"

void Merge(int arr[],size_t l,size_t m,size_t r)
{

    int l_length = m - l + 1;
    int left[l_length];

    int r_length = r-m;
    int right[r_length];

    size_t i,j;
    for(i = 0; i<l_length; ++i)
    {
        left[i] = arr[l+i];
    }
    for(j = 0; j<r_length; ++j)
    {
        right[j] = arr[m+1+j];
    }

    size_t l_index, r_index,merged_index;

    l_index = 0;
    r_index = 0;
    merged_index = l;

    while(l_index < l_length && r_index < r_length)
    {
        if(left[l_index] < right[r_index])
        {
            arr[merged_index] = left[l_index];

            ++l_index;
        }
        else
        {
            arr[merged_index] = right[r_index];
            ++r_index;
        }
        ++merged_index;
    }

    while(l_index < l_length)
    {
        arr[merged_index] = left[l_index];
        ++l_index;
        ++merged_index;

    }

    while(r_index < r_length)
    {

        arr[merged_index] = right[r_index];
        ++r_index;
        ++merged_index;
    }
}
void MergeSortArr(int arr[], size_t l, size_t r)
{
    size_t m = (l+r)/2;
    if(l<r)
    {
        MergeSortArr(arr,l,m);
        MergeSortArr(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}
