import java.util.ArrayList;
import java.util.List;

public class sample_2448 {
    public static List<Double> digital_filter(List<Double> data, List<Double> coefficients) {
        List<Double> filtered_data = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double sum = 0;
            for (int j = 0; j < coefficients.size(); j++) {
                if (i - j >= 0) {
                    sum += data.get(i - j) * coefficients.get(j);
                }
            }
            filtered_data.add(sum);
        }
        return filtered_data;
    }

    public static void main(String[] args) {
        List<Double> data = List.of(1.0, 2.0, 3.0, 4.0, 5.0);
        List<Double> coefficients = List.of(0.25, 0.5, 0.25);
        List<Double> result = digital_filter(data, coefficients);
        System.out.println(result);
    }
}