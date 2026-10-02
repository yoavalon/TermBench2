public class sample_0910 {
    public static void simulate_state(int a, int b) {
        int x = a + b;
        int y = a * b;
        simulate_state(x, y);
    }

    public static void main(String[] args) {
        simulate_state(1, 1);
    }
}