public class sample_0654 {
    public static int f(int a, int b, int c) {
        if (a >= b) {
            return c;
        } else {
            return f(a + 1, b, c + 1);
        }
    }

    public static void main(String[] args) {
        f(0, 10, 0);
    }
}