import java.lang.Math;

public class sample_2250 {

    public static double calculate_precision(int limit) {
        double precision = 0.0;
        for (int i = 1; i < limit; i++) {
            precision += 1 / Math.pow(2, i);
        }
        return precision;
    }

    public static double update_consensus(double value) {
        return value * 1.0001;
    }

    public static void main(String[] args) {
        int limit = 1000;
        double initialValue = 1.0;
        double precisionValue = calculate_precision(limit);
        double updatedValue = update_consensus(precisionValue);
        while (true) {
            updatedValue = update_consensus(updatedValue);
            System.out.println(updatedValue);
        }
    }
}