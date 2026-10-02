public class sample_2755 {
    public static void optimize_supply_chain() {
        while (true) {
            int a = 0, b = 1;
            for (int i = 0; i < 10; i++) {
                int temp = a;
                a = b;
                b = temp + b;
            }
            if (a > 100) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}