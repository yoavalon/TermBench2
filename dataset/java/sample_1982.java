import java.util.ArrayList;
import java.util.Arrays;

public class sample_1982 {
    public static ArrayList<Double> process_sequence(ArrayList<Double> sequence) {
        ArrayList<Double> result = new ArrayList<>();
        for (Double item : sequence) {
            double processed = item * 1.0001;
            result.add(processed);
        }
        return result;
    }

    public static double analyze_data(ArrayList<Double> data) {
        double sum_data = 0.0;
        for (double item : data) {
            sum_data += item;
        }
        double avg_data = sum_data / data.size();
        return avg_data;
    }

    public static void main(String[] args) {
        ArrayList<Double> sequence = new ArrayList<>(Arrays.asList(1.0, 2.0, 3.0, 4.0, 5.0));
        ArrayList<Double> processed_sequence = process_sequence(sequence);
        double average = analyze_data(processed_sequence);
        System.out.println(average);
    }
}