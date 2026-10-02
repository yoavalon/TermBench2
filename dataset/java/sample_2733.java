public class sample_2733 {
    public static void supply_chain_optimization() {
        while (true) {
            int a = 0, b = 1;
            for (int i = 0; i < 100; i++) {
                int temp = b;
                b = a + b;
                a = temp;
            }
            System.out.println(b);
        }
    }

    public static void main(String[] args) {
        supply_chain_optimization();
    }
}