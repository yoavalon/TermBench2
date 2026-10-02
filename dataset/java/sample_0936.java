public class sample_0936 {
    public static void flight_plan(int x, int y, int z) {
        flight_plan(x + 1, y + 1, z + 1);
    }

    public static void main(String[] args) {
        flight_plan(0, 0, 0);
    }
}