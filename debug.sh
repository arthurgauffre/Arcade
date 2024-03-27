#!/bin/bash

rm -rf build
rm -rf lib/*.so
rm -rf lib/*.a
rm -rf doc_doxygen
rm -rf arcade

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -- -j $(nproc --all)