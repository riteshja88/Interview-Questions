/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *
 *    Description:  quick Sort
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

void qsort(int *, int, int);

void sort(int array[], int n)
{
	qsort(array,0,n-1);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int array[], int start, int end)
{
	int pivot;
	int i,j;
	i = start+1;
	j = end;
	pivot = array[start]; //First elment as pivot
    while(1){
    	while(array[i]<=pivot)
    		i++;
    	while(array[j]>pivot)
    		j--;
    	if(i>=j) break;

        swap(&array[i], &array[j]);
    }
    swap(&array[start], &array[j]);
    return j;
    
}

void qsort(int array[], int start, int end)
{

	if(end-start<=0) return;
    int v = partition(array, start, end);
    qsort(array,start,v-1);
    qsort(array,v+1,end);

}
