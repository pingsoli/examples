package com.pingsoli.testjni;

public class TestJNI {

    static {
        System.loadLibrary("TestJNI");
    }

    public static final class InnerClass {
        public String message;
        public int count;

        public InnerClass() {
            System.out.println("create instance");
        }

        public void print() {
            for (int i = 0; i < count; i++) {
                System.out.println("print by java method: " + message + ", " + i);
            }
        }

        public static void staticPrint() {
            System.out.println("this is InnerClass's staticPrint method");
        }
    }

    // 创建并返回一个InnerClass的实例，将message和count填入实例中
    public static native InnerClass nativeCreateInnerClassInstance(String message, int count);

    // 根据传入的InnerClass实例，将InnerClass中的message打印count次
    public static native void nativePrintInnerClassInstance(InnerClass instance);

    // 根据传入的InnerClass实例，调用其print方法
    public static native void nativePrintInnerClassInstanceByCallingJavaMethod(InnerClass instance);

    // 在这个方法里创建一个 c++ 线程，以线程中循环调用 InnerClass 的 static 方法 staticPrint
    public static native void nativeCallInnerClassStaticPrintMethodNativeThread();

    public static native void memoryLeakByUnreleaseLocalRef();

//    public static void main(String args[]) {
//        if (args.length != 2) {
//            System.out.println("Usage: java TestJNI [message] [count]");
//            return;
//        }
//
//        // 动态库名称叫TestJNI，windows上为TestJNI.dll，linux上为libTestJNI.so
//        System.loadLibrary("TestJNI");
//
//        String message = args[0];
//        int count = Integer.parseInt(args[1]);
//
//        System.out.println(message + " " + count);
//
//        InnerClass instance = nativeCreateInnerClassInstance(message, count);
//
//        System.out.println(instance.message + " " + instance.count);
//
//        nativePrintInnerClassInstance(instance);
//
//        nativePrintInnerClassInstanceByCallingJavaMethod(instance);
//
//        nativeCallInnerClassStaticPrintMethodNativeThread();
//    }
}