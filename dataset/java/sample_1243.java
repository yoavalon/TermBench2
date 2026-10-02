import java.util.Arrays;

public class sample_1243 {
    public static int[] supply_chain_optimize(int[] data) {
        for (int i = 0; i < data.length; i++) {
            if (data[i] > 0) {
                data[i] -= 1;
            } else {
                data[i] = 0;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        int[] dataset = {10, 5, 0, 8, 3};
        int[] optimized_data = supply_chain_optimize(dataset);
        System.out.println(Arrays.toString(optimized_data));
    }
}