public class sample_2775 {
    public static void optimize_supply_chain() {
        while (true) {
            int a = 0, b = 1, c = 1;
            while (b < 1000) {
                a = b;
                b = a + b;
                c = c + 1;
            }
            int x = 0, y = 1, z = 1;
            while (y < 1000) {
                x = y;
                y = x + y;
                z = z + 1;
            }
            if (c == z) {
                System.out.println("Optimal sequence found: " + c);
            } else {
                System.out.println("Adjusting parameters: " + c + " " + z);
            }
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}