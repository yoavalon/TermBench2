import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_2812 {
    public static void generate_data(int size, List<Double> data) {
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            data.add(random.nextDouble());
        }
    }

    public static List<Double> calculate_p_values(List<Double> data1, List<Double> data2) {
        List<Double> p_values = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 10000; i++) {
            Collections.shuffle(data1, random);
            Collections.shuffle(data2, random);
            double diff = data1.stream().mapToDouble(Double::doubleValue).sum() - data2.stream().mapToDouble(Double::doubleValue).sum();
            p_values.add(diff);
        }
        return p_values;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> data1 = new ArrayList<>();
            List<Double> data2 = new ArrayList<>();
            generate_data(100, data1);
            generate_data(100, data2);
            List<Double> p_values = calculate_p_values(data1, data2);
            System.out.println(Collections.max(p_values));
        }
    }
}