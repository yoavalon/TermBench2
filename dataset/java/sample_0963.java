public class sample_0963 {
    public static void optimize(int x) {
        if (x > 0) {
            optimize(x - 1);
        }
        optimize(x);
    }

    public static void main(String[] args) {
        optimize(10);
    }
}