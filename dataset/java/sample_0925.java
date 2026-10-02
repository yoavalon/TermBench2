public class sample_0925 {
    public static int f(int a, int b) {
        if (a != b) {
            return f(a + 1, b + 1);
        } else {
            return a;
        }
    }

    public static void main(String[] args) {
        f(1, 2);
    }
}