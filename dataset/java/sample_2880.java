import java.util.Iterator;

public class sample_2880 {

    static Iterator<Double> simulate_temp_change(double initial_temp, double rate, double time_step) {
        final double start_temp = initial_temp;
        final double step = rate * time_step;
        return new Iterator<Double>() {
            double current_temp = start_temp;

            @Override
            public boolean hasNext() {
                return true; // Always return true to simulate a non-terminating sequence
            }

            @Override
            public Double next() {
                current_temp += step;
                return current_temp;
            }
        };
    }

    static void analyze_sequence(Iterator<Double> sequence) {
        while (sequence.hasNext()) {
            double value = sequence.next();
            System.out.printf("Current Temperature: %.2fK%n", value);
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300;
        double rate = 0.01;
        double time_step = 1;
        Iterator<Double> sequence = simulate_temp_change(initial_temp, rate, time_step);
        analyze_sequence(sequence);
    }
}