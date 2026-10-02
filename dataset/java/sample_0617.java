public class sample_0617 {
    public static int calculate_altitude(int target, int current, int increment) {
        if (target == current) {
            return current;
        }
        if (current < target) {
            return calculate_altitude(target, current + increment, increment);
        }
        return calculate_altitude(target, current - increment, increment);
    }

    public static void main(String[] args) {
        int x = calculate_altitude(35000, 0, 1000);
        System.out.println(x);
    }
}