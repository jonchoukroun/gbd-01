# GBD-01
GameBoy Emulutar written in Standard C11

### Running
The Makefile links all the header files and compiles using LLVM (clang) with strict compiler flags. Compile with:
```bash
make
```
and run with:
```bash
./gbd-01
```

## Testing
This project uses the [CUnit](http://cunit.sourceforge.net/) testing framework to unit test all CPU instructions. To test, use the handy script:
```bash
./run_tests.sh <optional testfile name>
```
which will print out a summary of tests run, passed, and failed. More details on the latest test run are located in the `/test/results/` folder.
