import java.util.ArrayList;
import java.util.List;

public class sample_1408 {

    static class RewardDecay {
        double current_reward;
        double decay_rate;

        RewardDecay(double initial_reward, double decay_rate) {
            this.current_reward = initial_reward;
            this.decay_rate = decay_rate;
        }

        void update_reward() {
            this.current_reward *= 1 - this.decay_rate;
        }

        double get_current_reward() {
            return this.current_reward;
        }
    }

    static class Agent {
        RewardDecay reward_decay;
        int action_count;

        Agent(RewardDecay reward_decay) {
            this.reward_decay = reward_decay;
            this.action_count = 0;
        }

        void take_action() {
            this.action_count += 1;
            this.reward_decay.update_reward();
        }

        double get_reward() {
            return this.reward_decay.get_current_reward();
        }
    }

    static List<Double> simulate_environment(Agent agent, int max_actions) {
        List<Double> rewards = new ArrayList<>();
        for (int i = 0; i < max_actions; i++) {
            agent.take_action();
            rewards.add(agent.get_reward());
        }
        return rewards;
    }

    public static void main(String[] args) {
        double initial_reward = 1.0;
        double decay_rate = 0.01;
        int max_actions = 1000;
        RewardDecay reward_decay = new RewardDecay(initial_reward, decay_rate);
        Agent agent = new Agent(reward_decay);
        List<Double> rewards = simulate_environment(agent, max_actions);
        System.out.println(rewards);
    }
}