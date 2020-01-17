#include "mergeSortPointer.h"


void MergePointer(int* left, int* right, int* merged, size_t length){
    size_t l_index, r_index, merged_index;
    int l_length, r_length;
    l_length = length/2;
    r_length = length-l_length;

    l_index = 0;
    r_index = 0;
    merged_index = 0;

    while(l_index < l_length && r_index<r_length){
        if(left[l_index]<right[r_index]){
            merged[merged_index] = left[l_index];
            ++l_index;
        }else{
            merged[merged_index] = right[r_index];
            ++r_index;
        }
        ++merged_index;
    }
    while(l_index<l_length){
        merged[merged_index] = left[l_index];
        ++l_index;
        ++merged_index;
    }
    while(r_index<r_length){
        merged[merged_index] = right[r_index];
        ++r_index;
        ++merged_index;
    }
    free(left);
    free(right);
}

void MergeSortPointer(int* arr, size_t length){
    if(length > 1){
        size_t mid = length/2;
        int* left = (int*)malloc(sizeof(int)*mid);
        int* right = (int*)malloc(sizeof(int)*(length-mid));
        if(left == 0 || right == 0)
            return;
        size_t i;
        for(i = 0; i<mid;++i){
            left[i] = arr[i];
        }
        for(i=mid;i<length;++i){
            right[i-mid] = arr[i];
        }
        MergeSortPointer(left,mid);
        MergeSortPointer(right,length-mid);
        MergePointer(left,right,arr,length);
    }
}
