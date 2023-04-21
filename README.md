# Data Structures and Algorithms in C and C++

This repo includes the implementation C code of basic `Data Structures` and essential `Must-learn Algorithms` during the preparation of `Graduate Entrance Examination`.

<p align="center">
<img src="https://raw.githubusercontent.com/danielhu19/mypicgocloud/master/img/202304172032097.jpeg" width="50%" height="50%">
</p>

## Welcome to Contribute

Due to the tight schedule, there may be some deficiencies or errors in the code, if you find any, **_please feel free to submit an issue_**.

Also, **_Everyone is welcome to submit a pull request_**, contribute your own code, and make progress together!

## Requires

- cmake
- make
- gcc/clang

> If you encounter any problem, google it before submitting a issue.

## Tested on

- MacOS Ventura 13.0
- Linux: tested on docker Ubuntu 22.04

> Windows: Not tested yet, theoretically can be run on Windows if you use proper compiler.

## Local Build

### Get source code

```shell
git clone https://github.com/danielhu19/datastructures-algorithms.git
cd datastructures-algorithms
```

### Compile and Run

> I strongly recommended using VSCode (trust me, I used to be a huge fan of vim and terminal) with `CMake` and `CMake Tools` extension to build.

#### For VSCode user:

Press `Command + Shift + p`(on mac) / `Ctrl + Shift + p`(on windows):

1. `CMake: Select a Kit` then choose clang/gcc
2. `CMake: Build` or `F7`
3. `CMake: Run without Debugging` or `shift + F5`
4. `CMake: Debug` or `F5` (optional)

#### CLI

> If you are terminal fan like I was, just compile like this:

```shell
cmake -S . -B build
cmake --build build
./build/tests/$EXE // choose one
```

Here I put the commands in vscode cmake in case you got some problems:

```shell
/opt/homebrew/bin/cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/opt/homebrew/opt/llvm/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/opt/homebrew/opt/llvm/bin/clang++ -S/Users/danielhu/Code/danielhu19/DataStructures-C -B/Users/danielhu/Code/danielhu19/DataStructures-C/build -G Ninja
/opt/homebrew/bin/cmake --build /Users/danielhu/Code/danielhu19/DataStructures-C/build --config Debug --target all --
cd ./build/tests
```

# Docker Support

> I'm not so familiar with docker actually, just on the way of learning.

You can use Docker if you don't want to deal with setting up the environment.
Here is an example:

```shell
# tag name: whatever you like
docker build -t datastructures:queue .
docker run -it --rm datastructures:queue /bin/bash -c "cd /app;./build/tests/sqlist"
```

# Recommended Repos

- chatgpt in terminal: https://github.com/nitefood/ai-bash-gpt
- fuck chaoxing: https://github.com/cxOrz/chaoxing-sign-cli
- for algorithms: https://github.com/labuladong/fucking-algorithm
- dsa in c++: https://github.com/TheAlgorithms/C-Plus-Plus/tree/master/data_structures
- dsa in c: https://github.com/TheAlgorithms/C/tree/master/data_structures
