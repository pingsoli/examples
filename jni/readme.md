## Learning about JNI programming

### Description
if you want to learn more about JNI programming, please click [here](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html).  
  
first directory contains the simplest example of beginning of JNI programming.  
second directory contains more complicated example, it cover the following content.  
1. creating a new java object in c++ code, and manipulating the member variable.  
2. calling the specific method from the java instance paramter.  
3. creating a new thread from c++ and attach to jvm, let it run in background.  
  
### Precautions  
1. Remember to release the resources when the New<Type> object is not used.  
2. Take care the lifetime of local reference.  

## references
[1] http://www.latkin.org/blog/2016/02/01/jni-object-lifetimes-quick-reference/  
