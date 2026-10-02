public class sample_0962 {
    public static void simulate_state(int x, int y) {
        int z = x + y;
        simulate_state(z, x);
    }

    public static void main(String[] args) {
        simulate_state(1, 1);
    }
}