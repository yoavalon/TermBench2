public class sample_0674 {
    public static Integer consensus(int a, int b, int depth) {
        if (a == b) {
            return a;
        }
        if (depth > 10) {
            return null;
        }
        int mid = (a + b) / 2;
        return mid < b ? consensus(mid, b, depth + 1) : consensus(a, mid, depth + 1);
    }

    public static void main(String[] args) {
        consensus(0, 10, 0);
    }
}