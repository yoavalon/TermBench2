public class sample_0664 {
    public static double reward_decay(double reward, double discount, double threshold) {
        if (reward < threshold) {
            return reward;
        } else {
            return reward_decay(reward * discount, discount, threshold);
        }
    }

    public static void main(String[] args) {
        reward_decay(100, 0.9, 10);
    }
}