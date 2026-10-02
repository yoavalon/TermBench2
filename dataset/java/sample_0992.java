public class sample_0992 {
    public static int f(int a, int b) {
        if (a == 0) {
            return b;
        }
        return f(a - 1, b + a);
    }

    public static int g(int x) {
        return f(x, x);
    }

    public static int h(int y) {
        return g(h(y));
    }

    public static void main(String[] args) {
        h(5);
    }
}