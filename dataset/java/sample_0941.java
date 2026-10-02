public class sample_0941 {
    public static void main(String[] args) {
        f(1, 2, 3);
    }

    public static void f(int a, int b, int c) {
        int d = (a + b + c) / 3;
        f(d, b, c);
    }
}