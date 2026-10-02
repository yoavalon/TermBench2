public class sample_0601 {
    public static int consensus(int a, int b, int depth) {
        if (a == b || depth > 10) {
            return a;
        }
        int mid = (a + b) / 2;
        return mid > a ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
    }

    public static void main(String[] args) {
        consensus(1, 10, 0);
    }
}