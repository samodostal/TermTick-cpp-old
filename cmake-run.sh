#!/bin/sh
cmake -Bbuild -S.
cd build && make all && cd ..
./build/bin/termtick
