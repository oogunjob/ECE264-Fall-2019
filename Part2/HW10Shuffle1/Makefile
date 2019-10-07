# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE -DDEBUG

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o shuffle

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle 4 output1
	$(VAL) ./shuffle 8 output2
	$(VAL) ./shuffle 11 output3

testall: 4 8 11

4: shuffle
	./shuffle 4 > output1
	diff output4 expected/expected4

8: shuffle
	./shuffle 8 > output8
	diff output8 expected/expected8

11: shuffle
	./shuffle 11 > output11
	diff output11 expected/expected11
	

clean: # remove all machine generated files
	rm -f shuffle *.o output?
