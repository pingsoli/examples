#!/bin/bash

JAVA_PATH="/usr/local/jdk1.8/include"

gcc -fPIC -I"$JAVA_PATH" -I"$JAVA_PATH/linux" -shared -o libhello.so HelloJNI.c
