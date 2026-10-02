public class sample_0384 {
    public static void simulate_flight() {
        while (true) {
            int a = 10000;
            int v = 800;
            double g = 9.81;
            int t = 0;
            while (v > 100) {
                t += 1;
                v -= g;
                a -= v * 0.01;
            }
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}