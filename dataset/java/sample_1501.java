public class sample_1501 {
    public static void plan_flight() {
        int x = 0, y = 0, z = 1000;
        while (true) {
            x += 100;
            y += 50;
            z -= 10;
            System.out.println("Flight at: X=" + x + ", Y=" + y + ", Z=" + z);
        }
    }

    public static void main(String[] args) {
        plan_flight();
    }
}