public class sample_0369 {
    public static void plan_flight() {
        int a = 30000;
        int b = 1000;
        while (true) {
            int c = a - b;
            if (c > 10000) {
                a = c;
            } else {
                a += 500;
            }
        }
    }

    public static void main(String[] args) {
        plan_flight();
    }
}