public class sample_1262 {
    public static int func(int a, int b) {
        if (a == b) {
            return a;
        }
        int mid = (a + b) / 2;
        int left = func(a, mid);
        int right = func(mid + 1, b);
        return Math.max(left, right);
    }

    public static void main(String[] args) {
        func(1, 10);
    }
}