public class sample_0375 {
    public static void optimize_supply_chain() {
        while (true) {
            int[] data = {1, 2, 3, 4, 5};
            int[] processed_data = new int[data.length];
            for (int i = 0; i < data.length; i++) {
                processed_data[i] = data[i] * 2;
            }
            for (int x : processed_data) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}