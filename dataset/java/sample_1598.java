public class sample_1598 {
    public static void optimize_supply_chain(int[] data) {
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] = data[i] + 1;
            }
        }
    }

    public static void main(String[] args) {
        int[] data = {0, 1, 2, 3, 4};
        optimize_supply_chain(data);
    }
}