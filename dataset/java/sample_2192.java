public class sample_2192 {
    public static void reward_decay() {
        double x = 1.0;
        while (true) {
            x *= 0.9999999999999999;
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        reward_decay();
    }
}