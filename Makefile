TARGET = gbd-01

SOURCE_DIR = src/
INCLUDE_DIR = include/
BUILD_DIR = build/

CC = clang

CFLAGS = -Wall
CFLAGS +=  -Wextra
CFLAGS +=  -Wpointer-arith
CFLAGS +=  -Wcast-align
CFLAGS +=  -Wwrite-strings
CFLAGS +=  -Wswitch-default
CFLAGS +=  -Wunreachable-code
CFLAGS +=  -Winit-self
CFLAGS +=  -Wmissing-field-initializers
CFLAGS +=  -Wno-unknown-pragmas
CFLAGS +=  -Wstrict-prototypes
CFLAGS +=  -Wundef
CFLAGS +=  -Wold-style-definition

_OBJ = instructions.o cpu.o main.o
OBJ = $(patsubst %,$(BUILD_DIR)%,$(_OBJ))

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -I$(INCLUDE_DIR)

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.c
	$(CC) -c -o $@ $< $(CFLAGS) -I$(INCLUDE_DIR)

# ---------------------------------------------------------
# Unit Testing
# ---------------------------------------------------------

TEST_DIR = test/
TEST_BUILD_DIR = build/test/
TEST_RESULTS = test/results/

TEST_LIBS = cunit

_TEST_OBJ = load_ops_test.o
TEST_OBJ = $(patsubst %,$(TEST_BUILD_DIR)%,$(_TEST_OBJ))

SUITES_RUN = `grep Suite $(TEST_RESULTS)*.txt | sed "s/Suite: //g"`

PASSED_COUNT = `grep -c passed $(TEST_RESULTS)*.txt`
FAILED_COUNT = `grep -c FAILED $(TEST_RESULTS)*.txt`
FAILED = `grep FAILED $(TEST_RESULTS)*.txt`

.PHONY: test
test: clean $(TEST_RESULTS)test_results.txt
	@echo "-----------------------\nTEST RESULTS\n-----------------------"
	@echo "\nSUITES\n-----------------------"
	@echo "$(SUITES_RUN)"
	@echo "\nFAILED: $(FAILED_COUNT)\n-----------------------"
	@echo "$(FAILED)"
	@echo "\nPASSED: $(PASSED_COUNT)\n-----------------------"
	@echo "\nDONE"

$(TEST_RESULTS)test_results.txt: $(TEST_OBJ)
	@for test in $(TEST_OBJ) ; do \
		./$$test >> $(TEST_RESULTS)test_results.txt ; done

$(TEST_BUILD_DIR)load_ops_test.o: $(TEST_DIR)load_ops_test.c
	$(CC) $< $(SOURCE_DIR)instructions.c -I$(INCLUDE_DIR) -l$(TEST_LIBS) -o $@


# ---------------------------------------------------------
# Misc
# ---------------------------------------------------------
#
.PHONY: clean

clean:
	rm -f $(TARGET) $(BUILD_DIR)*.o $(TEST_BUILD_DIR)*.o $(TEST_RESULTS)*.txt
