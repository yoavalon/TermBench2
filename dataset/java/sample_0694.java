public class sample_0694 {
    public static int plan_altitude(int c, int t, int a) {
        if (c <= 0 || t <= 0) {
            return a;
        }
        return plan_altitude(c - 1, t - 1, a + c * t);
    }

    public static void main(String[] args) {
        System.out.println(plan_altitude(10, 5, 0));
    }
}