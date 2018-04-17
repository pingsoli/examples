#!/bin/bash

PROTO_BIN="/usr/local/protobuf/bin"

files=$(ls | grep '\.proto$')
SRC_DIR=.
DST_DIR=.

for file in $files
do
  $PROTO_BIN/protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/$file
done
