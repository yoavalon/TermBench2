public class sample_0975 {
    public static void plan_altitude(int x, int y) {
        if (x > 1000) {
            plan_altitude(y, x + 1);
        } else {
            plan_altitude(x + 1, y);
        }
    }

    public static void main(String[] args) {
        plan_altitude(0, 0);
    }
}