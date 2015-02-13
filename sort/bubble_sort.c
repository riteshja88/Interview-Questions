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

void sort(int *array, int n)
{
    int i,j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}
