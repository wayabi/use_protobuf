#!/bin/sh

#install
#wget https://github.com/google/protobuf/releases/download/v2.6.1/protobuf-2.6.1.tar.gz

protoc a.proto --cpp_out="./src"
mv src/a.pb.cc src/a.pb.cpp
make
./a.out
