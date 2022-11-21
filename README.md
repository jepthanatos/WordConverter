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

## Compile in Windows

At least GCC 8 and CMake are needed.

Install MSYS2 from https://www.msys2.org/

https://github.com/msys2/msys2-installer/releases/download/2022-10-28/msys2-x86_64-20221028.exe

On the open console launch this command:

```
    pacman -S mingw-w64-ucrt-x86_64-gcc
```

Follow the update guide: https://www.msys2.org/docs/updating/

Configure using Cmake:

```
    "C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=G:\Programs\MSYS2\ucrt64\bin\x86_64-w64-mingw32-gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=G:\Programs\MSYS2\ucrt64\bin\x86_64-w64-mingw32-g++.exe -Sc:/Users/Thanatos/Desktop/repos/WordConverter -Bc:/<directory>/WordConverter/build -G "MinGW Makefiles"
```
**Pay attention to directories**

Compile:

```
    "C:\Program Files\CMake\bin\cmake.exe" --build c:<directory>/WordConverter/build --config Debug --target all -j 6 --
```
**Pay attention to directories**
## Compile in Linux

At least GCC 8 and CMake are needed.

Install GCC 8:

```
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo-apt get update
    sudo apt-get install gcc-8 g++-8
```

Configure using Cmake:

```
    cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc-8 -DCMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++-8 -S/<directory>/WordConverter -B/<directory>/WordConverter/build -G "Unix Makefiles"
```
**Pay attention to directories**

Compile:

```
    cmake --build ./build --config Debug --target all -j 10 --
```
**Pay attention to directories**
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
