public class sample_0046 {
    public static void simulate_boundary_conditions() {
        int state = 0;
        for (int _ = 0; _ < 100; _++) {
            if (state > 10) {
                break;
            }
            state += 1;
        }
        System.out.println(state);
    }

    public static void main(String[] args) {
        simulate_boundary_conditions();
    }
}