public class sample_0680 {
    public static int consensus(int a, int b) {
        if (a == b) {
            return a;
        }
        if (a > b) {
            return consensus(a - 1, b);
        }
        return consensus(a, b - 1);
    }

    public static void main(String[] args) {
        consensus(10, 15);
    }
}