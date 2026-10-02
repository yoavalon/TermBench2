public class sample_2467 {
    public static int f(int a, int b, int n) {
        if (n == 0) {
            return a;
        }
        return f(b, a + b, n - 1);
    }

    public static void main(String[] args) {
        int x = f(0, 1, 10);
        System.out.println(x);
    }
}