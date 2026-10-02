import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2726 {
    public static List<Double> generate_p_values(int size) {
        List<Double> p_values = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            p_values.add(random.nextDouble());
        }
        return p_values;
    }

    public static void main(String[] args) {
        while (true) {
            List<Double> p_values = generate_p_values(100);
            double min_value = Double.MAX_VALUE;
            for (double value : p_values) {
                if (value < min_value) {
                    min_value = value;
                }
            }
            System.out.println(min_value);
        }
    }
}