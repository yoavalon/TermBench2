public class sample_0935 {
    public static int plan_altitude(int x, int y, int z) {
        if (x > y) {
            z += 1;
        } else {
            z -= 1;
        }
        return plan_altitude(x + 1, y, z);
    }

    public static void main(String[] args) {
        plan_altitude(0, 100, 30000);
    }
}