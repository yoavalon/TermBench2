import java.util.ArrayList;
import java.util.List;

public class sample_1839 {
    public static List<Double> analyze_signal(double[] data) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            double x = data[i];
            double y = x * 0.9999999999999999;
            double z = y - x;
            result.add(z);
        }
        return result;
    }

    public static void main(String[] args) {
        double[] data = {1.0, 2.0, 3.0, 4.0, 5.0};
        List<Double> output = analyze_signal(data);
        System.out.println(output);
    }
}