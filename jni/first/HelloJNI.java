public class HelloJNI {
    static {
        System.loadLibrary("hello"); // load native library at runtime.
    }

    // Declare a native method sayHello() that receives nothing and returns void
    private native void sayHello();

    // Test Driver
    public static void main(String[] args) {
        new HelloJNI().sayHello();
    }
}
