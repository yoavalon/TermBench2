public class sample_1360 {
    public static double[] compute_decay(double reward, double rate, int steps) {
        double[] decayed_rewards = new double[steps];
        for (int step = 0; step < steps; step++) {
            double decayed_reward = reward * Math.pow(rate, step);
            decayed_rewards[step] = decayed_reward;
            if (decayed_reward < 0.01) {
                break;
            }
        }
        return decayed_rewards;
    }

    public static double[] analyze_data(double[] data) {
        double total = 0;
        for (double value : data) {
            total += value;
        }
        double average = data.length > 0 ? total / data.length : 0;
        return new double[]{total, average};
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.95;
        int max_steps = 1000;
        double[] rewards = compute_decay(initial_reward, decay_rate, max_steps);
        double[] result = analyze_data(rewards);
        System.out.println("Total Reward: " + result[0] + ", Average Reward: " + result[1]);
    }
}