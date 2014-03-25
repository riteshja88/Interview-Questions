/*
 * =====================================================================================
 *
 *       Filename:  rainfall.c
 *
 *    Description:  Rainfall program for Palantir FTE
 *
 *        Version:  1.0
 *        Created:  03/22/2014 05:39:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ritesh Agarwal (Omi), ragarw8@uic.edu
 *        Company:  University of Illinois, Chicago
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_S 1000


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  allocate_square_matrix(int s)
 *  Description:  Allocates a square matrix of size s, all values initialized with 0.
 * =====================================================================================
 */
unsigned int ** allocate_square_matrix(int s)
{
    unsigned int **mat;
    unsigned int i;
    mat = malloc(s * sizeof(int *));
    assert(mat!=NULL);
    for(i=0; i<s; i++){
        mat[i] = calloc(s, sizeof(int));
        assert(mat[i]!=NULL);
    }

    return mat;
}/* allocate_square_matrix(int s) */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_input(int **alt_matrix, int s)
 *  Description:  Reads input from STDIN in the said format
 * =====================================================================================
 */
void read_input(unsigned int ***alt_matrix_in, int *s)
{
    unsigned int **alt_matrix = NULL;
    unsigned int i,j;
    scanf("%u", s);
    alt_matrix = (unsigned int **)allocate_square_matrix(*s);
    for(i=0; i<*s; i++)
        for(j=0; j<*s; j++)
            scanf("%u",&alt_matrix[i][j]);

    *alt_matrix_in = alt_matrix;
    return ;
}/* read_input(int **alt_matrix, int s) */


/* 
* ===  FUNCTION  ======================================================================
*         Name:  find_lowest_alt
*  Description:  Function simply returns the row and column of the lowest altitude
* =====================================================================================
*/
void find_lowest_alt(unsigned int **alt_matrix, unsigned int s, unsigned int *row,unsigned int *col)
{
    unsigned int min_alt = -1;
    unsigned int i,j;

    for(i=0; i<s; i++){
        for(j=0; j<s; j++) {
            if(alt_matrix[i][j] <= min_alt) {
                *row = i; *col = j; min_alt = alt_matrix[i][j];
            }
        }
    }
    return ;
}/* find_lowest_alt */


/* 
* ===  FUNCTION  ======================================================================
*         Name:  find_next_lowest_unknown_alt
*  Description:  Function simply returns the row and column of the next altitude after row, col specified and modifies the same.
* =====================================================================================
*/

#define END_OF_UNKNOWN_ALTITUDE -1
void find_next_lowest_unknown_alt(unsigned int **alt_matrix, unsigned int s, unsigned int sink_flag[][MAX_S], unsigned int *row, unsigned int *col)
{
    unsigned int i,j;
    unsigned int current_alt = alt_matrix[*row][*col];
    unsigned int next_min_alt =-1;
    unsigned int flag_changed = 0;
    for(i=0; i<s; i++){
        for(j=0; j<s ; j++)
        {
            if(sink_flag[i][j] != 0 /* Not unknown */) continue; /* Can be optimized more by including in for loop test condition */

            if(alt_matrix[i][j] >= current_alt && alt_matrix[i][j] < next_min_alt) {
                *row = i; *col = j; next_min_alt = alt_matrix[i][j];
                flag_changed = 1;
            }

        }
    }
    if(!flag_changed)
        *row = END_OF_UNKNOWN_ALTITUDE; /* This means that we have marked every block in some zone*/
    return ;
}/* find_next_lowest_unknown_alt */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  is_sink
 *  Description:  Returns 1 if the specified cell is a sink otherwise returns 0
 * =====================================================================================
 */
int is_sink(unsigned int **alt_matrix, unsigned int s, unsigned int row, unsigned int col)
{

    unsigned int cell_value = alt_matrix[row][col];
    int cnt;


    assert(row <= s-1);
    assert(col <= s-1);

    assert(row >= 0);
    assert(col >= 0);

    cnt=0;

    if(row>=(s-1) || alt_matrix[row+1][col] > cell_value)
        cnt++;

    if(row<=0 || alt_matrix[row-1][col] > cell_value)
        cnt++;

    if(col<=0 || alt_matrix[row][col-1] > cell_value)
        cnt++;

    if(col>=(s-1) || alt_matrix[row][col+1] > cell_value)
        cnt++;

    if( (row == (s-1) || col == (s-1)) || alt_matrix[row+1][col+1] > cell_value)
        cnt++;

    if( (row == 0 || col == (s-1)) || alt_matrix[row-1][col+1] > cell_value)
        cnt++;

    if( (row == (s-1) || col == 0) || alt_matrix[row+1][col-1] > cell_value)
        cnt++;

    if( (row == 0 || col == 0) || alt_matrix[row-1][col-1] > cell_value)
        cnt++;

    if(cnt==8) 
        return 1;
    else
        return 0;
}/* is_sink */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  mark_neighbours_with_zone
 *  Description:  Will mark neighbours with zone no. specified if it is not already marked.
 * =====================================================================================
 */
void mark_neighbours_with_zone(unsigned int zone_matrix[][MAX_S], unsigned int s, unsigned int row, unsigned int col, unsigned int sink_flags[][MAX_S])
{

    unsigned int zone_value = zone_matrix[row][col];

    if(row<(s-1))
        if(sink_flags[row+1][col] == 0 /* Unknown */){
            zone_matrix[row+1][col] = zone_value;
            sink_flags[row+1][col] = 2 /* Non-sink */;
        }

    if(row>0)
        if(sink_flags[row-1][col] == 0){
            zone_matrix[row-1][col] = zone_value;
            sink_flags[row-1][col] = 2;
        }

    if(col>0)
        if(sink_flags[row][col-1] == 0){
            zone_matrix[row][col-1] = zone_value;
            sink_flags[row][col-1] = 2;
        }

    if(col<(s-1)) 
        if(sink_flags[row][col+1] == 0){
            zone_matrix[row][col+1] = zone_value;
            sink_flags[row][col+1] = 2;
        }

    if(row<(s-1) && col<(s-1)) 
        if(sink_flags[row+1][col+1] == 0){
            zone_matrix[row+1][col+1] = zone_value;
            sink_flags[row+1][col+1] = 2;
        }

    if(row>0 && col<(s-1))
        if(sink_flags[row-1][col+1] == 0){
            zone_matrix[row-1][col+1] = zone_value;
            sink_flags[row-1][col+1] = 2;
        }

    if(row<(s-1) && col>0)
        if(sink_flags[row+1][col-1] == 0){
            zone_matrix[row+1][col-1] = zone_value;
            sink_flags[row+1][col-1] = 2;
        }

    if(row>0 && col>0)
        if(sink_flags[row-1][col-1] == 0){
            zone_matrix[row-1][col-1] = zone_value;
            sink_flags[row-1][col-1] = 2;
        }

    return ;
}/* mark_neighbours_with_zone */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  find_lowest_unique_neighbour
 *  Description:  Returns the position of the lowest unique neighbour
 * =====================================================================================
 */
void find_lowest_unique_neighbour(unsigned int **alt_matrix, unsigned int s, unsigned int sink_flag[][MAX_S],unsigned int *r,unsigned int *c)
{
    unsigned int row = *r, col =*c;
    unsigned int min_neighbour_value=-1;

    if(row<(s-1) && alt_matrix[row+1][col] < min_neighbour_value)
        *r = row + 1, *c = col, min_neighbour_value = alt_matrix[row+1][col];

    if(row>0 && alt_matrix[row-1][col] < min_neighbour_value)
        *r = row - 1, *c = col, min_neighbour_value = alt_matrix[row-1][col];;

    if(col>0 && alt_matrix[row][col-1] < min_neighbour_value)
        *c = col - 1, *r = row, min_neighbour_value = alt_matrix[row][col-1];;

    if(col<(s-1) && alt_matrix[row][col+1] < min_neighbour_value)
        *c = col + 1, *r = row, min_neighbour_value = alt_matrix[row][col+1];;

    if(row<(s-1) && col<(s-1) && alt_matrix[row+1][col+1] < min_neighbour_value){
        *r = row + 1;
        *c = col + 1;
        min_neighbour_value = alt_matrix[row+1][col+1];
    }

    if(row>0 && col<(s-1) && alt_matrix[row-1][col+1] < min_neighbour_value){
        *r = row - 1;
        *c = col + 1;
        min_neighbour_value = alt_matrix[row-1][col+1];
    }

    if(row<(s-1) && col>0 && alt_matrix[row+1][col-1] < min_neighbour_value){
        *r = row + 1;
        *c = col - 1;
        min_neighbour_value = alt_matrix[row+1][col-1];
    }

    if(row>0 && col>0 && alt_matrix[row-1][col-1] < min_neighbour_value){
        *r = row - 1;
        *c = col - 1;
        min_neighbour_value = alt_matrix[row-1][col-1];
    }
}/* find_lowest_unique_neighbour*/


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_zone_counts
 *  Description:  Returns an array with total no. of elements = total no. of zones and 
 *                  each item indicating count of altitutes in the zone
 * =====================================================================================
 */
void get_zone_counts(unsigned int basin_zone_matrix[][MAX_S], unsigned int s, unsigned int *zone_cnt)
{
    unsigned int i,j;
    for(i=0; i<s; i++)
        for(j=0; j<s; j++)
            zone_cnt[ basin_zone_matrix[i][j]-1 ]++;

    return ;
}/* get_zone_counts */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  rainfall_partition
 *  Description:  Function that returns an array of zone sizes
 * =====================================================================================
 */

unsigned int basin_zone_matrix[MAX_S][MAX_S];
unsigned int sink_flag[MAX_S][MAX_S]; /* 0 : unknown, 1 : sink, 2 : non-sink */
void rainfall_partition(unsigned int **alt_matrix, unsigned int s, unsigned int *zone_cnt, unsigned int *arr_size)
{
    unsigned int current_zone_no=0;
    unsigned int r=0,c=0;
    //memset(basin_zone_matrix, 0, sizeof(basin_zone_matrix)); /* 0 means unknown zone */

    memset(sink_flag, 0, sizeof(sink_flag)); 
    
    /* First sink */
    find_lowest_alt(alt_matrix, s, &r, &c);
    sink_flag[r][c] = 1; /*Sink*/
    basin_zone_matrix[r][c] = ++current_zone_no;
    mark_neighbours_with_zone(basin_zone_matrix, s, r, c, sink_flag);

    /* Find next lowest unknown altitude block and start working on it */
    do
    {
        find_next_lowest_unknown_alt(alt_matrix, s, sink_flag, &r, &c);
        if(r == END_OF_UNKNOWN_ALTITUDE) break;

        if(is_sink(alt_matrix, s, r, c)){
            sink_flag[r][c] = 1; /*Sink*/;
            basin_zone_matrix[r][c] = ++current_zone_no;
            mark_neighbours_with_zone(basin_zone_matrix, s, r, c, sink_flag);
        }
        else{
            int row, col;
            row=r;
            col=c;
            sink_flag[r][c] = 2 /*Not-Sink*/;
            find_lowest_unique_neighbour(alt_matrix, s, sink_flag, &row, &col);
            assert( basin_zone_matrix[row][col] != 0);
            basin_zone_matrix[r][c] = basin_zone_matrix[row][col]; /*Will flow to lowest neighbour alt */
        }


    }while(1);

    get_zone_counts(basin_zone_matrix, s, zone_cnt);

    *arr_size = current_zone_no; 
    return ;
}/* rainfall_partition */

int cmp_func(const void *a, const void *b)
{
       return ( *(int*)b - *(int*)a );
}

int main (int argc, char *argv[])
{
    unsigned int s,i; /* Dimension of Square Altitude Matrix */
    unsigned int **altitude_matrix;
    unsigned int zone_cnt_arr[MAX_S*100], arr_size;
    memset(zone_cnt_arr, 0 , sizeof(zone_cnt_arr));

    read_input(&altitude_matrix, &s);

    rainfall_partition(altitude_matrix, s, zone_cnt_arr, &arr_size);
    
    qsort(zone_cnt_arr, arr_size, sizeof(int), cmp_func);

    for(i=0; i<(arr_size-1); i++){
        printf("%u ", zone_cnt_arr[i]);
    }
    printf("%u", zone_cnt_arr[i]);

 
 return 0;
}/* main */
