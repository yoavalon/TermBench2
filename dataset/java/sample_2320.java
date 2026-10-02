public class sample_2320 {

    static class RewardDecay {
        double value;
        double rate;
        double threshold;

        RewardDecay(double initial_value, double decay_rate, double threshold) {
            this.value = initial_value;
            this.rate = decay_rate;
            this.threshold = threshold;
        }

        double decay() {
            this.value *= this.rate;
            if (this.value < this.threshold) {
                this.value = this.threshold;
            }
            return this.value;
        }

        boolean is_stable() {
            return this.value == this.threshold;
        }
    }

    static class Agent {
        RewardDecay reward;

        Agent(RewardDecay reward_decay) {
            this.reward = reward_decay;
        }

        void act() {
            if (!this.reward.is_stable()) {
                this.reward.decay();
            }
        }
    }

    static class Environment {
        Agent agent;

        Environment(Agent agent) {
            this.agent = agent;
        }

        void simulate() {
            while (true) {
                this.agent.act();
            }
        }
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double decay_rate = 0.9999999999999999;
        double threshold = 1e-05;
        RewardDecay reward_decay = new RewardDecay(initial_value, decay_rate, threshold);
        Agent agent = new Agent(reward_decay);
        Environment environment = new Environment(agent);
        environment.simulate();
    }
}