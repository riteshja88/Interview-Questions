/*
 * =====================================================================================
 *
 *       Filename:  merge_sort.c
 *
 *    Description:  merge Sort
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

void merge_sort(int array[], int start, int end);

void sort(int array[], int n)
{
    merge_sort(array, 0, n-1);
}

void merge(int array[], int start, int mid, int end)
{
    int i, j, k;
    int dest[end-start+1];
    i = start;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= end){
        if(array[i] <= array[j]){
            dest[k++] = array[i++];
        }
        else{
            dest[k++] = array[j++]; 
        }
    }
    while(i<=mid)
        dest[k++] = array[i++];

    while(j<=end)
        dest[k++] = array[j++];

    for(i=0,j=start;j<=end;i++,j++){
        array[j] = dest[i];
    }
}


void merge_sort(int array[], int start, int end)
{
    int mid = 0;

    if(start>=end) return;

    mid = (start + end)/2;

    merge_sort(array, start, mid);
    merge_sort(array, mid+1, end);

    merge(array, start, mid, end);

}
