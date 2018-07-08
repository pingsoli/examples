#!/bin/bash

JAVA_PATH="/usr/local/jdk1.8/include"
clang++ -fPIC -std=c++14 -I"$JAVA_PATH" -I"$JAVA_PATH/linux" -shared -o libTestJNI.so TestJNI.cpp

javac TestJNI.java
java -Djava.library.path=. TestJNI test 12
