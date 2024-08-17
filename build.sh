#!/bin/bash

AARCH64_TOOLCHAIN_FILE=./toolchain/aarch64-unknown-linux.cmake

rm -rf build
mkdir build
cd build

echo Building target x86_64-unknown-linux...

mkdir x86_64-unknown-linux
cd x86_64-unknown-linux
cmake ../..

if [$? -gt 0]; then
    echo Failed to run cmake for target x86_64-unknown-linux. See above for details.
    exit 1
fi

make

if [$? -gt 0]; then
    echo Failed to build target x86_64-unknown-linux. See above for details.
    exit 1
fi

cd ..

echo Building target aarch64-unknown-linux...

mkdir aarch64-unknown-linux
cd aarch64-unknown-linux
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=$AARCH64_TOOLCHAIN_FILE

if [$? -gt 0]; then
    echo Failed to run cmake for target aarch64-unknown-linux. See above for details.
    exit 1
fi

make

if [$? -gt 0]; then
    echo Failed to build target aarch64-unknown-linux. See above for details.
    exit 1
fi

echo Building complete.