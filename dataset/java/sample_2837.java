import java.util.Iterator;

public class sample_2837 {
    static Iterator<double[]> calculate_trajectory() {
        final double a = 0.001;
        final double b = 0.002;
        final double[] initial = {10000, 200};
        return new Iterator<double[]>() {
            double[] current = initial.clone();

            public boolean hasNext() {
                return true;
            }

            public double[] next() {
                double[] result = current.clone();
                current[0] -= a;
                current[1] -= b;
                if (current[0] <= 0) {
                    current[0] = 10000;
                    current[1] = 200;
                }
                return result;
            }
        };
    }

    static void analyze_data() {
        Iterator<double[]> trajectory = calculate_trajectory();
        int i = 0;
        while (trajectory.hasNext()) {
            double[] data = trajectory.next();
            System.out.printf("Step %d: Altitude %.2fm, Velocity %.2fm/s%n", i, data[0], data[1]);
            i++;
        }
    }

    public static void main(String[] args) {
        analyze_data();
    }
}