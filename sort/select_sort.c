/*
 * =====================================================================================
 *
 *       Filename:  bubble_sort.c
 *
 *    Description:  Bubble Sort
 *
 *        Version:  1.0
 *        Created:  12/13/2014 03:21:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ritesh Agarwal (Omi), riteshja@yahoo-inc.com
 *        Company:  Yahoo! Inc
 *
 * =====================================================================================
 */

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int array[], int n)
{
    int i,j;
    int min_index;
    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1; j<n; j++){
           if(array[j] < array[min_index]){
                min_index = j;
           }
        }
        swap(&array[i], &array[min_index]);
    }
}
