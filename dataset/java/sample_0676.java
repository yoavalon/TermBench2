public class sample_0676 {
    public static int plan_altitude(int target, int current, int step) {
        if (Math.abs(target - current) <= step) {
            return current;
        }
        if (target > current) {
            return plan_altitude(target, current + step, step);
        } else {
            return plan_altitude(target, current - step, step);
        }
    }

    public static void main(String[] args) {
        System.out.println(plan_altitude(35000, 10000, 5000));
    }
}