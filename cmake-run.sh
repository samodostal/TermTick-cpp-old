#!/bin/sh
cmake -Bbuild -S.
cd build && make && cd ..
./build/bin/termtick
