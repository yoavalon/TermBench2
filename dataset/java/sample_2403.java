public class sample_2403 {
    public static int sequence(int a, int b, int n) {
        if (n == 0) {
            return a;
        } else if (n == 1) {
            return b;
        } else {
            return sequence(b, a + b, n - 1);
        }
    }

    public static void main(String[] args) {
        int a = 0, b = 1, n = 10;
        int result = sequence(a, b, n);
        System.out.println(result);
    }
}