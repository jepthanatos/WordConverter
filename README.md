# Word Converter

Word Converter is a program to convert words numbers into digital numbers.

For example:

    one hundred and one.

Will be converted to:

    101.

Another example:

    I have one hundred apples.

The result will be:

    I have 100 apples.

## Installation

Download a zip and extract it:

    https://github.com/jepthanatos/WordConverter/archive/refs/heads/main.zip

Or clone the repository:

    git clone https://github.com/jepthanatos/WordConverter.git

Install gcc-8 in Linux in order to compile:
    ```bash
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo-apt get update
    sudo apt-get install gcc-8 g++-8
    ```

## Compile in Linux

Configure:
    ```bash
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc-8 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++-8 -S/local/practice/WordConverter -B/local/practice/WordConverter/build -G "Unix Makefiles"
    ```

Compile:
    ```bash
    cmake --build ./build --config Debug --target all -j 10 --
    ```

## Usage

    WordConverter_run -i <input_file> [-o] [<output_file]

## Test

    WordConverter_tst

Expected output:

```
[==========] Running 5 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 5 tests from TestConverter
[ RUN      ] TestConverter.convertToNumber
[       OK ] TestConverter.convertToNumber (0 ms)
[ RUN      ] TestConverter.maxNumberInt
[       OK ] TestConverter.maxNumberInt (0 ms)
[ RUN      ] TestConverter.maxNumberUnsignedInt
[       OK ] TestConverter.maxNumberUnsignedInt (0 ms)
[ RUN      ] TestConverter.mixedExample
[       OK ] TestConverter.mixedExample (0 ms)
[ RUN      ] TestConverter.mixedBlankSpaces
[       OK ] TestConverter.mixedBlankSpaces (0 ms)
[----------] 5 tests from TestConverter (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 5 tests.
```
## License

Attribution 4.0 International (CC BY 4.0)

https://creativecommons.org/licenses/by/4.0/
