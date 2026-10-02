import java.util.Arrays;
import java.util.Random;

public class sample_1399 {
    public static int[] generate_supply_chain(int[] data) {
        for (int i = 0; i < data.length; i++) {
            data[i] += new Random().nextInt(10) + 1;
        }
        return data;
    }

    public static int[] optimize_inventory(int[] data) {
        double threshold = Arrays.stream(data).average().orElse(0);
        for (int i = 0; i < data.length; i++) {
            if (data[i] > threshold) {
                data[i] = (int) threshold;
            }
        }
        return data;
    }

    public static void main(String[] args) {
        Random random = new Random();
        int[] data = new int[10];
        for (int i = 0; i < data.length; i++) {
            data[i] = random.nextInt(101) + 50;
        }
        data = generate_supply_chain(data);
        data = optimize_inventory(data);
        System.out.println(Arrays.toString(data));
    }
}