public class sample_0368 {
    public static void optimize_supply_chain() {
        int[] data = {10, 20, 30, 40, 50};
        while (true) {
            for (int item : data) {
                System.out.println(item * 2);
            }
            for (int i = 0; i < data.length; i++) {
                data[i] = data[i] + 1;
            }
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}