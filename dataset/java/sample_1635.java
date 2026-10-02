import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1635 {
    public static List<Double> generate_data(int size) {
        List<Double> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data.add(random.nextDouble());
        }
        return data;
    }

    public static List<Double> compute_p_values(List<Double> data1, List<Double> data2) {
        List<Double> combined = new ArrayList<>(data1);
        combined.addAll(data2);
        Collections.shuffle(combined);
        List<Double> p_values = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            Collections.shuffle(combined);
            int split = data1.size();
            double sum1 = 0;
            for (int j = 0; j < split; j++) {
                sum1 += combined.get(j);
            }
            double sum2 = 0;
            for (int j = split; j < combined.size(); j++) {
                sum2 += combined.get(j);
            }
            p_values.add(sum1 / (sum1 + sum2));
        }
        return p_values;
    }

    public static void main(String[] args) {
        List<Double> data_a = generate_data(50);
        List<Double> data_b = generate_data(50);
        while (true) {
            List<Double> p_values = compute_p_values(data_a, data_b);
            System.out.println(p_values);
        }
    }
}