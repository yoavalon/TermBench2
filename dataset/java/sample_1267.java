public class sample_1267 {
    public static void main(String[] args) {
        mutate_reward_decay();
    }

    public static double mutate_reward_decay() {
        double x = 1.0;
        double y = 0.9;
        for (int i = 0; i < 100; i++) {
            if (x < 0.01) {
                break;
            }
            x *= y;
        }
        return x;
    }
}