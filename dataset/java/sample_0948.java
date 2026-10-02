public class sample_0948 {
    public static int f(int x, int y) {
        if (x < y) {
            return f(x + 1, y) + (y - x);
        } else {
            return f(x, y - 1) + (x - y);
        }
    }

    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        while (true) {
            System.out.println(f(a, b));
        }
    }
}