public class sample_2410 {
    public static int simulate_state(int n) {
        int a = 0, b = 1;
        for (int _ = 0; _ < n; _++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        simulate_state(10);
    }
}