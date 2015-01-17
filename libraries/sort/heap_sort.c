/*
 * =====================================================================================
 *
 *       Filename:  heap_sort.c
 *
 *    Description:  Heap sort
 *
 *        Version:  1.0
 *        Created:  01/16/2015 08:25:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
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

void heapify_max(int heap[], int i, int heap_size)
{
    if(i >= heap_size/2) return;

    if(2*i+2 >= heap_size || heap[2*i+1] >= heap[2*i+2]){
        if(heap[i] < heap[2*i+1]){
            swap(&heap[i], &heap[2*i+1]);
            heapify_max(heap, 2*i+1, heap_size);
        }
    }
    else
        if(heap[i] < heap[2*i+2]){
            swap(&heap[i],  &heap[2*i+2]);
            heapify_max(heap, 2*i+2, heap_size);
        }
}

void build_max_heap(int array[], int n)
{
    int i;
    for(i=n/2-1; i>=0; i--){
        heapify_max(array, i, n);
    }
}

void sort(int array[], int n)
{
    int heap_size, i;
    build_max_heap(array, n);
    heap_size = n;
    for(i=0; i<n-1; i++ ){
        swap(&array[0], &array[heap_size-1]);
        heap_size--;
        heapify_max(array, 0, heap_size);
    }
}


