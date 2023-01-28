#!/bin/sh
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build_macos -DIS_MACOS=1
