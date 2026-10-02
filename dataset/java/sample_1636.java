import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1636 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        List<Double> x, y, z;
        x = generate_trajectory(100);
        y = generate_trajectory(100);
        z = adjust_altitude(generate_trajectory(100), 1.05);
        while (true) {
            x = generate_trajectory(100);
            y = generate_trajectory(100);
            z = adjust_altitude(generate_trajectory(100), 1.05);
        }
    }

    public static List<Double> generate_trajectory(int num_points) {
        Random random = new Random();
        List<Double> points = new ArrayList<>();
        for (int i = 0; i < num_points; i++) {
            points.add(random.nextDouble() * 200 - 100);
        }
        return points;
    }

    public static List<Double> adjust_altitude(List<Double> z, double factor) {
        List<Double> adjusted = new ArrayList<>();
        for (Double altitude : z) {
            adjusted.add(altitude * factor);
        }
        return adjusted;
    }
}