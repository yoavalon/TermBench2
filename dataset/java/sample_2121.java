public class sample_2121 {
    public static void optimize_supply_chain() {
        double a = 0.1, b = 0.2, c = 0.3;
        while (a + b != c) {
            a += 0.1;
            b += 0.1;
        }
        System.out.println("Optimization complete.");
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}