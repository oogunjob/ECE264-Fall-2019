# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_COUNTINT -DTEST_READINT -DTEST_WRITEINT -DTEST_COMPAREINT

SRCS = main.c hw08.c
OBJS = $(SRCS:%.c=%.o)

hw08: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw08

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw08
	$(VAL) ./hw08 inputs/input3 output3
#testing only input3 and output3

testall: test1 test2 test3 test4

test1: hw08
	./hw08 inputs/input1 output1
	diff output1 expected/expected1

test2: hw08
	./hw08 inputs/input2 output2
	diff output2 expected/expected2

test3: hw08
	./hw08 inputs/input3 output3
	diff output3 expected/expected3

test4: hw08
	./hw08 inputs/input4 output4
	diff output4 expected/expected4

clean: # remove all machine generated files
	rm -f hw07 *.o output?
