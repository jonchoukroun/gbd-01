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
# Misc
# ---------------------------------------------------------
#
.PHONY: clean

clean:
	rm -f $(TARGET) $(BUILD_DIR)*.o $(TEST_BUILD_DIR)*.o $(TEST_RESULTS)*.txt
