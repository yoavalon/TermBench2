import java.util.ArrayList;
import java.util.List;

public class sample_1868 {
    public static List<Double> optimize_supply_chain(double[] data, double precision) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            double value = data[i];
            double adjusted_value = Math.round(value / precision) * precision;
            result.add(adjusted_value);
        }
        return result;
    }

    public static void main(String[] args) {
        double[] data = {123.456, 789.123, 456.789};
        double precision = 0.01;
        List<Double> optimized_data = optimize_supply_chain(data, precision);
        System.out.println(optimized_data);
    }
}