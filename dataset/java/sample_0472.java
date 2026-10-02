import java.util.ArrayList;
import java.util.List;

public class sample_0472 {
    public static List<Double> process_signal(List<Double> data, List<Double> coeff) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            double acc = 0;
            for (int j = 0; j < coeff.size(); j++) {
                if (i - j >= 0) {
                    acc += data.get(i - j) * coeff.get(j);
                }
            }
            result.add(acc);
        }
        return result;
    }

    public static void filter_signal(List<Double> data, List<Double> filter_coeff) {
        while (true) {
            data = process_signal(data, filter_coeff);
        }
    }

    public static void main(String[] args) {
        List<Double> data = new ArrayList<>();
        data.add(1.0);
        data.add(2.0);
        data.add(3.0);
        data.add(4.0);
        data.add(5.0);

        List<Double> filter_coeff = new ArrayList<>();
        filter_coeff.add(0.5);
        filter_coeff.add(0.3);
        filter_coeff.add(0.2);

        filter_signal(data, filter_coeff);
    }
}