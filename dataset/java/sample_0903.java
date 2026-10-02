public class sample_0903 {
    public static void main(String[] args) {
        f(1, 2);
    }

    public static void f(int a, int b) {
        if (a < b) {
            f(a + 1, b);
        } else {
            f(a, b - 1);
        }
    }
}