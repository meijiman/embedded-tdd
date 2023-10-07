PRJ = LedDriver
BD = ./build
TD = $(BD)/tests
CC = gcc
CFLAGS = -g -Wall

UNITY_ROOT = /home/meijiman/Unity
TEST_CC = gcc
TEST_INC = -I$(UNITY_ROOT)/src -Iinc
TEST_SRCS = tests/LedDriverTest.c $(UNITY_ROOT)/src/unity.c src/LedDriver.c
TEST_OBJS = $(TEST_SRCS:%=$(BD)/%.o)

TEST_CFLAGS = -g
TEST_CFLAGS += -Wall

tests: $(TD)/$(PRJ)

$(TD)/$(PRJ): $(TEST_OBJS)
	$(TEST_CC) $(TEST_CFLAGS) $(TEST_INC) $(TEST_OBJS) -o $@ 

$(BD)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(TEST_CC) $(TEST_CFLAGS) $(TEST_INC) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BD)
