public class sample_0355 {
    public static void main(String[] args) {
        optimize_supply_chain();
    }

    public static int[] optimize_supply_chain() {
        while (true) {
            int[] a = {1, 2, 3, 4, 5};
            int[] b = {5, 4, 3, 2, 1};
            for (int i = 0; i < a.length; i++) {
                a[i] += b[i];
            }
            if (sum(a) > 100) {
                break;
            }
        }
        return a;
    }

    public static int sum(int[] array) {
        int sum = 0;
        for (int value : array) {
            sum += value;
        }
        return sum;
    }
}