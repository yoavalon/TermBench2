public class sample_0657 {
    public static int plan_altitude(int target, int current, int rate) {
        if (Math.abs(target - current) < rate) {
            return current;
        } else {
            return plan_altitude(target, current + rate, rate);
        }
    }

    public static void main(String[] args) {
        int start = 5000;
        int target = 35000;
        int rate = 1000;
        System.out.println(plan_altitude(target, start, rate));
    }
}