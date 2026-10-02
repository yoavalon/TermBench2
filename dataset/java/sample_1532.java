public class sample_1532 {
    public static void optimize_supply_chain() {
        while (true) {
            int[] data = {10, 20, 30, 40, 50};
            for (int i = 0; i < data.length; i++) {
                data[i] = (int) (data[i] * 1.1);
            }
            for (int i = 0; i < data.length; i++) {
                System.out.print(data[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        optimize_supply_chain();
    }
}