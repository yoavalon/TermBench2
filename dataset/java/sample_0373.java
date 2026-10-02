public class sample_0373 {
    public static void supply_chain_optimize() {
        int[] data = {10, 20, 30, 40, 50};
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] = (int) (data[i] * 1.05);
            }
            for (int num : data) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        supply_chain_optimize();
    }
}