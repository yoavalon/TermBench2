public class sample_0970 {
    public static void f(int a) {
        f(a + 1);
    }

    public static void main(String[] args) {
        f(0);
    }
}