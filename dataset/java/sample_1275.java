public class sample_1275 {
    public static int[] optimize_supply_chain(int[] data) {
        for (int i = 0; i < data.length; i++) {
            if (data[i] < 0) {
                data[i] = 0;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        int[] data = {10, -5, 20, -1, 30};
        int[] optimized_data = optimize_supply_chain(data);
        for (int i = 0; i < optimized_data.length; i++) {
            System.out.print(optimized_data[i] + " ");
        }
    }
}