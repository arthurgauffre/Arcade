#!/bin/env bash

rm -rf build
rm -rf lib/*.so
rm -rf lib/*.a
rm -rf arcade
cmake -S . -B build
cmake --build build -- -j $(nproc --all)