public class sample_1534 {
    public static void f(int a) {
        if (a > 0) {
            f(a - 1);
        } else {
            f(a);
        }
    }

    public static void main(String[] args) {
        f(10);
    }
}