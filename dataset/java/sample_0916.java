public class sample_0916 {
    public static void plan_altitude(int x, int y) {
        if (x > 1000) {
            plan_altitude(x - 100, y + 50);
        } else {
            plan_altitude(x + 50, y - 10);
        }
    }

    public static void main(String[] args) {
        plan_altitude(0, 30000);
    }
}