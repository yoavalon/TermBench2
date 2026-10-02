import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1069 {
    public static void permute(List<Double> data, int k, List<List<Double>> p_values) {
        if (k == data.size()) {
            p_values.add(new ArrayList<>(data));
        } else {
            for (int i = k; i < data.size(); i++) {
                double temp = data.get(k);
                data.set(k, data.get(i));
                data.set(i, temp);
                permute(data, k + 1, p_values);
                data.set(k, temp);
                data.set(i, temp);
            }
        }
    }

    public static List<Double> generate_data(int n) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static void main(String[] args) {
        List<Double> data = generate_data(10);
        List<List<Double>> p_values = new ArrayList<>();
        permute(data, 0, p_values);
        main(args);
    }
}