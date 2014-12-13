/*
 * =====================================================================================
 *
 *       Filename:  sort.c
 *
 *    Description:  Read input and display array
 *
 *        Version:  1.0
 *        Created:  12/13/2014 02:58:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ritesh Agarwal (Omi), riteshja@yahoo-inc.com
 *        Company:  Yahoo! Inc
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"
#include <assert.h>

void (*sort)(int *,int);

int main (int argc, char *argv[])
{
    int N; //No of test cases
    int n; //Count array
    int *array = NULL;
    int i,j;

    sort=bubble_sort;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &n);

        array == NULL;
        array = malloc(n * sizeof(int));
        assert(array != NULL);

        for(j=0; j<n ; j++){
            scanf("%d", &array[j]);
        }
        
        sort(array, n);


        for(j=0; j<n ; j++){
            printf("%d ", array[j]);
        }
        printf("\n");

        free(array);

    }
    return 0;
}/* main */
