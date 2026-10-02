import java.util.ArrayList;
import java.util.List;

public class sample_2242 {
    public static List<Double> compute_flight_path(int[][] data) {
        List<Double> result = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            int altitude = data[i][0];
            int speed = data[i][1];
            double trajectory = (double) altitude / speed;
            result.add(trajectory);
        }
        return result;
    }

    public static double analyze_altitude(int[][] data) {
        double sum = 0;
        for (int[] d : data) {
            sum += d[0];
        }
        return sum / data.length;
    }

    public static void main(String[] args) {
        int[][] flight_data = {{10000, 500}, {12000, 550}, {11000, 520}, {9000, 480}, {8000, 450}};
        List<Double> trajectory = compute_flight_path(flight_data);
        double avg_altitude = analyze_altitude(flight_data);
        while (true) {
            System.out.println("Current Trajectory: " + trajectory);
            System.out.println("Average Altitude: " + avg_altitude);
        }
    }
}