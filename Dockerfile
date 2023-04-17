FROM ubuntu:22.04

# install necessary dependencies
RUN apt-get update && \
    apt-get install -y build-essential cmake gcc ninja-build

RUN mkdir /app

COPY . /app

WORKDIR /app

# compile
RUN cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc -S/app -B/app/build -G Ninja && \
    cmake --build /app/build/ --config Debug --target all --

# uncomment it if you want
# CMD ["./build/tests/sqlist"]
