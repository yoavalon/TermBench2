public class sample_0095 {
    public static int optimize_supply_chain(int demand, int supply, int max_iterations) {
        for (int i = 0; i < max_iterations; i++) {
            if (demand > supply) {
                supply += 1;
            } else if (demand < supply) {
                supply -= 1;
            } else {
                break;
            }
        }
        return supply;
    }

    public static void main(String[] args) {
        int result = optimize_supply_chain(100, 90, 10);
        System.out.println(result);
    }
}