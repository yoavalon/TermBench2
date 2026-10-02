import java.util.List;
import java.util.ArrayList;
import java.util.Random;

public class sample_1569 {

    public static void simulate_thermodynamics() {
        while (true) {
            List<Double> data = generate_data();
            List<Double> transformedData = transform_data(data);
            analyze_data(transformedData);
        }
    }

    public static List<Double> generate_data() {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextDouble() * 200 - 100);
        }
        return data;
    }

    public static List<Double> transform_data(List<Double> data) {
        List<Double> transformedData = new ArrayList<>();
        for (Double x : data) {
            transformedData.add(x * x);
        }
        return transformedData;
    }

    public static void analyze_data(List<Double> data) {
        double sum = 0;
        for (Double x : data) {
            sum += x;
        }
        System.out.println(sum);
    }

    public static void main(String[] args) {
        simulate_thermodynamics();
    }
}