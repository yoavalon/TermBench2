public class sample_1508 {
    public static void supply_chain_optimizer() {
        while (true) {
            int[][] data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < data[i].length; j++) {
                    data[i][j] *= 2;
                }
            }
            for (int i = 0; i < data.length; i++) {
                for (int j = 0; j < data[i].length; j++) {
                    System.out.print(data[i][j] + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        supply_chain_optimizer();
    }
}