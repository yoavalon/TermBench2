import java.util.Arrays;

public class sample_1310 {
    public static double[] calculateRewardDecay(double initialReward, double decayRate, int timeSteps) {
        double[] rewards = new double[timeSteps];
        rewards[0] = initialReward;
        for (int t = 1; t < timeSteps; t++) {
            rewards[t] = rewards[t - 1] * (1 - decayRate);
        }
        return rewards;
    }

    public static boolean simulateTerminalCondition(double[] rewards, double threshold) {
        for (double reward : rewards) {
            if (reward < threshold) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        double initialReward = 1.0;
        double decayRate = 0.05;
        int timeSteps = 20;
        double threshold = 0.01;
        double[] rewards = calculateRewardDecay(initialReward, decayRate, timeSteps);
        boolean terminalCondition = simulateTerminalCondition(rewards, threshold);
        System.out.println("Terminal Condition Met: " + terminalCondition);
    }
}