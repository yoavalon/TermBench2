import java.util.ArrayList;
import java.util.List;

public class sample_2852 {
    public static double calculateAltitude(double t) {
        double g = 9.81;
        double v0 = 300;
        double h0 = 10000;
        return h0 + v0 * t - 0.5 * g * t * t;
    }

    public static void plotTrajectory() {
        List<Double> tValues = new ArrayList<>();
        List<Double> hValues = new ArrayList<>();
        double t = 0;
        while (true) {
            double h = calculateAltitude(t);
            if (h < 0) {
                break;
            }
            tValues.add(t);
            hValues.add(h);
            t += 1;
        }
        // Simulate plotting using System.out for simplicity
        for (int i = 0; i < tValues.size(); i++) {
            System.out.printf("Time (s): %.2f, Altitude (m): %.2f%n", tValues.get(i), hValues.get(i));
        }
    }

    public static void main(String[] args) {
        plotTrajectory();
    }
}