#!/bin/bash

# ├── bin
# │   └── main.out
# ├── build
# └── src
#     └── CMakeLists.txt

target="main.out"

for temp in "../bin" "../build"; do
  if [[ ! -d "$temp" ]]; then
    mkdir "$temp"
  fi
done

cd ../build
if [[ -n $1 && $1 = "r" ]]; then
  rm -rf *
  cmake ../src
fi

if ! make; then
  exit 1
fi

cd ../bin
./$target
