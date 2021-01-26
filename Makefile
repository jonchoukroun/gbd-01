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

_TEST_OBJ = cpu_test.o
_TEST_OBJ += LD_r_r_test.o
_TEST_OBJ += LD_r_n_test.o
_TEST_OBJ += LD_r_HL_test.o
_TEST_OBJ += LD_HL_r_test.o
_TEST_OBJ += LD_A_rr_test.o
_TEST_OBJ += LD_rr_A_test.o
_TEST_OBJ += LD_HL_ID_test.o
_TEST_OBJ += LD_rr_nn_test.o
_TEST_OBJ += PP_rr_test.o
_TEST_OBJ += ADD_8_test.o
# _TEST_OBJ += 16bit_ALU_test.o
# _TEST_OBJ += misc_arithmetic_test.o
# _TEST_OBJ += rotate_test.o
# _TEST_OBJ += bit_shift_test.o

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

$(TEST_BUILD_DIR)cpu_test.o: $(TEST_DIR)cpu_test.c
	$(CC) $< $(SOURCE_DIR)cpu.c -I$(INCLUDE_DIR) -l$(TEST_LIBS) -o $@

INSTRUCTIONS_TEST_COMPILE_OPTS = $(CC) $< $(SOURCE_DIR)cpu.c $(SOURCE_DIR)instructions.c -I$(INCLUDE_DIR) -l$(TEST_LIBS) -o $@

$(TEST_BUILD_DIR)LD_r_r_test.o: $(TEST_DIR)LD_r_r_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_r_n_test.o: $(TEST_DIR)LD_r_n_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_r_HL_test.o: $(TEST_DIR)LD_r_HL_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_HL_r_test.o: $(TEST_DIR)LD_HL_r_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_A_rr_test.o: $(TEST_DIR)LD_A_rr_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_rr_A_test.o: $(TEST_DIR)LD_rr_A_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_HL_ID_test.o: $(TEST_DIR)LD_HL_ID_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)LD_rr_nn_test.o: $(TEST_DIR)LD_rr_nn_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)PP_rr_test.o: $(TEST_DIR)PP_rr_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

$(TEST_BUILD_DIR)ADD_8_test.o: $(TEST_DIR)ADD_8_test.c
	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

# $(TEST_BUILD_DIR)16bit_ALU_test.o: $(TEST_DIR)16bit_ALU_test.c
# 	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

# $(TEST_BUILD_DIR)misc_arithmetic_test.o: $(TEST_DIR)misc_arithmetic_test.c
# 	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

# $(TEST_BUILD_DIR)rotate_test.o: $(TEST_DIR)rotate_test.c
# 	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

# $(TEST_BUILD_DIR)bit_shift_test.o: $(TEST_DIR)bit_shift_test.c
# 	$(INSTRUCTIONS_TEST_COMPILE_OPTS)

# ---------------------------------------------------------
# Misc
# ---------------------------------------------------------
#
.PHONY: clean

clean:
	rm -f $(TARGET) $(BUILD_DIR)*.o $(TEST_BUILD_DIR)*.o $(TEST_RESULTS)*.txt
