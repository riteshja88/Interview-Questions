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

void sort(int *array, int n)
{
	qsort(array,0,n);
}

void qsort(int *array, int start, int end)
{

	int pivot;
	int i,j,k;
	if(end-start<=0) return;
	i = k = start+1;
	j= end;
	pivot = array[start]; //First elment as pivot
    while(1){
    	while(array[i]<=pivot)
    		i++;
    	while(array[j]>pivot)
    		j--;
    	if(i>=j) break;

    	{
    		int tmp = array[i];
    		array[i] = array[j];
    		array[j] = tmp;
    	}
    }
    {
        int tmp = array[start];
        array[start] = array[j];
        array[j] = tmp;
    }
    	qsort(array,start,j-1);
    	qsort(array,j+1,end);

}
