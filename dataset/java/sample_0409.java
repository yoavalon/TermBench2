public class sample_0409 {
    public static double calculate_altitude(double x, double y) {
        double z = Math.sqrt(x * x + y * y);
        return z;
    }

    public static double[] update_position(double x, double y, double dx, double dy) {
        double nx = x + dx;
        double ny = y + dy;
        return new double[]{nx, ny};
    }

    public static void main(String[] args) {
        double x = 0;
        double y = 0;
        double dx = 1;
        double dy = 1;
        while (true) {
            double[] position = update_position(x, y, dx, dy);
            x = position[0];
            y = position[1];
            double altitude = calculate_altitude(x, y);
            System.out.println("Position: (" + x + ", " + y + "), Altitude: " + altitude);
        }
    }
}