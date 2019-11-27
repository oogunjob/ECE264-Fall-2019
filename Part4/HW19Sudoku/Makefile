WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose --track-origins=yes

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw19: $(OBJS)
	$(GCC) $(OBJS) -o hw19

testmemory: hw19
	$(VAL) ./hw19 inputs/test1 output1
	$(VAL) ./hw19 inputs/test2 output2
	$(VAL) ./hw19 inputs/test3 output3
	$(VAL) ./hw19 inputs/test4 output4
	$(VAL) ./hw19 inputs/test5 output5
	$(VAL) ./hw19 inputs/test6 output6

testall: test1 test2 test3 test4 test5 test6

test1: hw19
	./hw19 inputs/test1 > output1
	diff -w output1 expected/expected1	

test2: hw19
	./hw19 inputs/test2 > output2
	diff -w output2 expected/expected2

test3: hw19
	./hw19 inputs/test3 > output3
	diff -w output3 expected/expected3

test4: hw19
	./hw19 inputs/test4 > output4
	diff -w output4 expected/expected4
	
test5: hw19
	./hw19 inputs/test5 > output5
	diff -w output5 expected/expected5
	
test6: hw19
	./hw19 inputs/test6 > output6
	diff -w output6 expected/expected6
	
clean: # remove all machine generated files
	rm -f hw19 *.o output?
