#!/bin/sh
#
# Run the GBD-01 full test suite, or individual tests

FLAGS="-Wall -Wextra -Wpointer-arith -Wcast-align -Wwrite-strings -Wswitch-default -Wunreachable-code -Winit-self -Wmissing-field-initializers -Wno-unknown-pragmas -Wstrict-prototype -Wundef -Wold-style-definition"
LIBS="cunit"
SRC_DIR="src/"
INCLUDE_DIR="include/"
TEST_DIR="test"
BUILD_DIR="build/test/"
OUTPUT="test/results/test_results.txt"

# Remove previous builds and test output
rm -f "$BUILD_DIR"*.o $OUTPUT

if [[ $# -ne 0 ]]; then
    MATCHER="*$1*.c"
else
    MATCHER="*.c"
fi

FILES=`find $TEST_DIR -type f -iname $MATCHER`

for f in $FILES; do
    if [ -f "$f" ]; then
        OBJ=`echo $f | sed -E 's/^test\/(.+)(.c)$/\\1.o/g'`
        COMPILED=`clang $f "$SRC_DIR"cpu.c "$SRC_DIR"instructions.c -I$INCLUDE_DIR -l$LIBS -o $BUILD_DIR/$OBJ`
        `./$BUILD_DIR$OBJ >> $OUTPUT`
    else
        echo "Unable to test $f!"
    fi
done
echo

SUITES_RUN=`grep "Suite" $OUTPUT | sed "s/Suite: //g"`
PASSED_COUNT=`grep -c passed $OUTPUT`
FAILED_COUNT=`grep -c FAILED $OUTPUT`
FAILED=`grep FAILED $OUTPUT`

echo "TEST RESULTS\n-----------------------"
echo "\nTEST SUITES RUN\n-----------------------"
echo "$SUITES_RUN"
echo "\n\nPASSED: $PASSED_COUNT\n-----------------------"
echo "\n\nFAILED: $FAILED_COUNT\n"
echo "$FAILED"
echo "\n\n-----------------------"
echo "\nDONE"
