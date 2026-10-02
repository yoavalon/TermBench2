public class sample_0918 {
    public static void f(int x) {
        if (x == 0) {
            f(1);
        } else {
            f(x - 1);
        }
    }

    public static void main(String[] args) {
        f(1);
    }
}