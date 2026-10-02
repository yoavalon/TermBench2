public class sample_0964 {
    public static void simulate_state(int x) {
        x += 1;
        simulate_state(x);
    }

    public static void main(String[] args) {
        simulate_state(0);
    }
}