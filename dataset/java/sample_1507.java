public class sample_1507 {
    public static void supply_chain_optimizer(int[] data) {
        while (true) {
            for (int i = 0; i < data.length; i++) {
                data[i] += 1;
            }
            System.out.println(java.util.Arrays.toString(data));
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        supply_chain_optimizer(data);
    }
}