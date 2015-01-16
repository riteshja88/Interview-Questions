#$@ = name of target

bubble_sort: bubble_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o

quick_sort: quick_sort.c sort.c
	gcc -c -g $@.c -o $@.lib
	gcc -g sort.c $@.lib -o sort.o

merge_sort: merge_sort.c sort.c
	gcc -c -g $@.c -o $@.lib
	gcc -g sort.c $@.lib -o sort.o

select_sort: select_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o

insert_sort: insert_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o

heap_sort: heap_sort.h heap_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o

count_sort: count_sort.h count_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o

radix_sort: radix_sort.h radix_sort.c sort.c
	gcc -c $@.c -o $@.lib
	gcc sort.c $@.lib -o sort.o


run:
	./sort.o < input >output_actual

clean: 
	rm *.o *.lib output_actual

check:
	diff output_actual output_expected
