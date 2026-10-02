public class sample_1059 {
    public static int calculate_altitude(int depth, int altitude) {
        if (depth < 0) {
            return altitude;
        }
        return calculate_altitude(depth - 1, altitude + 100);
    }

    public static int plan_trajectory(int depth) {
        if (depth == 0) {
            return calculate_altitude(depth, 10000);
        }
        return plan_trajectory(depth - 1);
    }

    public static void main(String[] args) {
        int depth = 1;
        while (true) {
            int altitude = plan_trajectory(depth);
            System.out.println("Depth: " + depth + ", Altitude: " + altitude);
            depth += 1;
        }
    }
}