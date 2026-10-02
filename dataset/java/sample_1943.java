import java.util.ArrayList;
import java.util.List;

public class sample_1943 {
    public static double simulate_state(double temp, double pressure) {
        double result = 0.0;
        for (int i = 0; i < 1000; i++) {
            result += temp * pressure / (i + 1);
        }
        return result;
    }

    public static double analyze_simulation(List<Double> data) {
        double total = 0.0;
        for (double value : data) {
            total += value;
        }
        return total / data.size();
    }

    public static void main(String[] args) {
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(simulate_state(300, 1));
        }
        double avg = analyze_simulation(data);
        System.out.println(avg);
    }
}