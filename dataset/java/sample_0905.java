public class sample_0905 {
    public static void plan_flight(int x, int y, int z) {
        plan_flight(x + 1, y + 1, z + 1);
    }

    public static void main(String[] args) {
        plan_flight(0, 0, 0);
    }
}