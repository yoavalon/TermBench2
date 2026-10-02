public class sample_2486 {
    public static int optimize_supply_chain(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        return a;
    }

    public static void main(String[] args) {
        int result = optimize_supply_chain(10);
        System.out.println(result);
    }
}