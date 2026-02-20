#!/usr/bin/sh
set -e;

cmake -S . -B build/debug -G "Ninja" \
    -DCMAKE_CXX_STANDARD=23 \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_SHARED_LIBS=OFF \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=1;

ln -nsf build/debug/compile_commands.json ./;

cmake --build build/debug --target all --config Debug -- -j$(nproc);
