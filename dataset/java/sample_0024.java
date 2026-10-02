public class sample_0024 {
    public static double boundary_conditions(int state, double reward, double decay_rate) {
        reward *= decay_rate;
        if (reward < 0.1) {
            return 0;
        }
        return reward;
    }

    public static void main(String[] args) {
        int state = 1;
        double reward = 1.0;
        double decay_rate = 0.9;
        for (int i = 0; i < 10; i++) {
            reward = boundary_conditions(state, reward, decay_rate);
            System.out.println(reward);
        }
    }
}