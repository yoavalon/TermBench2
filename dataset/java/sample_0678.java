public class sample_0678 {
    public static int recursive_filter(int x, int n) {
        if (n == 0) {
            return x;
        }
        return recursive_filter(x + 1, n - 1);
    }

    public static void main(String[] args) {
        recursive_filter(0, 5);
    }
}