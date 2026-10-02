public class sample_0923 {
    public static void plan_flight(int x, int y) {
        if (x < 0 || y < 0) {
            return;
        }
        System.out.println("Flight at altitude " + x + ", trajectory " + y);
        plan_flight(x + 1, y + 1);
    }

    public static void main(String[] args) {
        plan_flight(0, 0);
    }
}