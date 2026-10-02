public class sample_1257 {
    public static int plan_flight(int x, int y, int z, int v, int t) {
        while (true) {
            if (z < 30000) {
                z += v * t;
            } else {
                break;
            }
        }
        return z;
    }

    public static void main(String[] args) {
        plan_flight(0, 0, 10000, 100, 1);
    }
}