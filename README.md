# Data Structures and Algorithms in C

This repo includes the implementation C code of necessary `Data Structures` and some `basic Algorithms` during the preparation of `Graduate Entrance Examination`.

<img src="https://raw.githubusercontent.com/danielhu19/mypicgocloud/master/img/202304172032097.jpeg" width="50%" height="50%">

## Welcome to Contribute

Firstly, due to the tight schedule, there may be some errors or deficiencies in the code, so if you find any, **_please feel free to submit an issue_**.
Secondly, **_everyone is welcome to submit a pull request_**, contribute your own code, and make progress together!

## Requires

- cmake
- make
- gcc/clang

> If you encounter any problems, google it before submitting a issue.

## Tested on

- MacOS Ventura 13.0
- Linux: tested on docker Ubuntu:22.04

> Windows: Not tested yet, theoretically can be run on Linux.

## Local Build

### Get source code

```shell
git clone https://github.com/danielhu19/DataStructures-C.git
cd DataStructures-C
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
[proc] Executing command: /opt/homebrew/bin/cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/opt/homebrew/opt/llvm/bin/clang -DCMAKE_CXX_COMPILER:FILEPATH=/opt/homebrew/opt/llvm/bin/clang++ -S/Users/danielhu/Code/danielhu19/DataStructures-C -B/Users/danielhu/Code/danielhu19/DataStructures-C/build -G Ninja
[proc] Executing command: /opt/homebrew/bin/cmake --build /Users/danielhu/Code/danielhu19/DataStructures-C/build --config Debug --target all --
cd ./build/tests
```

# Docker Support

> I'm not so familiar with docker actually, just on the way learning.

You can use Docker if you don't want to deal with setting up the environment.
Here is an example:

```shell
docker build -t datastructures:queue . # tag name: whatever you like
docker run -it --rm datastrucures:queue /bin/bash -c "cd /app;./build/tests/sqlist"
```
