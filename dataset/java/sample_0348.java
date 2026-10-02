public class sample_0348 {
    public static void simulate_state() {
        int x = 0, y = 1;
        while (true) {
            int temp = y;
            y = x + y;
            x = temp;
        }
    }

    public static void main(String[] args) {
        simulate_state();
    }
}