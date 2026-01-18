#!/bin/zsh

FILE_INPUT=$1

BASE_NAME=$(basename "${FILE_INPUT%.*}")

shift

mkdir -p ./build
clang++ -std=c++20 "./src/$FILE_INPUT" -o "./build/$BASE_NAME" "$@" && "./build/$BASE_NAME"
