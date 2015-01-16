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


void sort(int array[], int n)
{
    int i,j;
    for(i=1; i<n; i++){
        int k = array[i];
        for(j=i-1; j>=0 && array[j]>k; j--){
            array[j+1] = array[j];
        }
        array[j+1] = k;
    }
}
