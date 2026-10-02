public class sample_0616 {
    public static int simulate_state(int a, int b) {
        if (a == b) {
            return a;
        }
        if (a < b) {
            return simulate_state(a + 1, b);
        }
        return simulate_state(a - 1, b);
    }

    public static void main(String[] args) {
        simulate_state(0, 5);
    }
}