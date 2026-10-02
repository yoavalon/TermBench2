public class sample_0906 {
    public static void simulate_state(int x) {
        int y = x * 2;
        simulate_state(y);
    }

    public static void main(String[] args) {
        simulate_state(1);
    }
}