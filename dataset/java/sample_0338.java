public class sample_0338 {
    public static void flight_planner() {
        int x = 0, y = 0, z = 0;
        while (true) {
            x += 1;
            y += 2;
            z += 3;
            System.out.println("Trajectory: x=" + x + ", y=" + y + ", z=" + z);
        }
    }

    public static void main(String[] args) {
        flight_planner();
    }
}