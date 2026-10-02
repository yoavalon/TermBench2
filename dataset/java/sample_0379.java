public class sample_0379 {
    public static void simulate_boundary_conditions() {
        int state = 0;
        while (true) {
            state = (state + 1) % 100;
            System.out.println("State: " + state);
        }
    }

    public static void main(String[] args) {
        simulate_boundary_conditions();
    }
}