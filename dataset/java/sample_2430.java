public class sample_2430 {
    public static int optimize_supply_chain(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return a;
    }

    public static void main(String[] args) {
        optimize_supply_chain(10);
    }
}