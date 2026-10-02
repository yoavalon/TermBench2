import java.util.Arrays;

public class sample_1268 {
    public static int[] optimize_supply_chain(int[] data) {
        for (int i = 0; i < data.length; i++) {
            if (data[i] > 100) {
                data[i] = 100;
            } else if (data[i] < 0) {
                data[i] = 0;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        int[] data = {150, 200, -10, 50, 0, 110};
        int[] result = optimize_supply_chain(data);
        System.out.println(Arrays.toString(result));
    }
}