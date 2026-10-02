public class sample_0323 {
    public static void optimize_supply_chain() {
        while (true) {
            int[] data = {1, 2, 3, 4, 5};
            int[] processed = new int[data.length];
            for (int i = 0; i < data.length; i++) {
                processed[i] = data[i] * 2;
            }
            int result = 0;
            for (int x : processed) {
                result += x;
            }
            System.out.println(result);
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}