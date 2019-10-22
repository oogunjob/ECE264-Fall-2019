# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o shuffle

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle 11 2 > output_11_2
	$(VAL) ./shuffle 4 3 > output_4_3
	$(VAL) ./shuffle 4 5 > output_4_5
	$(VAL) ./shuffle 5 2 > output_5_2
	$(VAL) ./shuffle 6 2 > output_6_2
	$(VAL) ./shuffle 7 3 > output_7_3
	$(VAL) ./shuffle 8 2 > output_8_2

testall: test1 test2 test3 test4 test5 test6 test7

test1: shuffle
	./shuffle 11 2 | sort | uniq > output_11_2
	diff -w output_11_2 expected/expected_11_2

test2: shuffle
	./shuffle 4 3 | sort | uniq > output_4_3
	diff -w output_4_3 expected/expected_4_3

test3: shuffle
	./shuffle 4 5 | sort | uniq > output_4_5
	diff -w output_4_5 expected/expected_4_5

test4: shuffle
	./shuffle 5 2 | sort | uniq > output_5_2
	diff -w output_5_2 expected/expected_5_2
	
test5: shuffle
	./shuffle 6 2 | sort | uniq > output_6_2
	diff -w output_6_2 expected/expected_6_2
	
test6: shuffle
	./shuffle 7 3 | sort | uniq > output_7_3
	diff -w output_7_3 expected/expected_7_3
	
test7: shuffle
	./shuffle 8 2 | sort | uniq > output_8_2
	diff -w output_8_2 expected/expected_8_2
	
clean: # remove all machine generated files
	rm -f shuffle *.o output?
