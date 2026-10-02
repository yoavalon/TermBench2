public class sample_2025 {

    static class RewardSystem {
        double value;
        double decay_rate;

        RewardSystem(double initial_value, double decay_rate) {
            this.value = initial_value;
            this.decay_rate = decay_rate;
        }

        double decay() {
            this.value *= this.decay_rate;
            return this.value;
        }
    }

    static class Environment {
        RewardSystem reward_system;

        Environment(RewardSystem reward_system) {
            this.reward_system = reward_system;
        }

        double step() {
            double reward = this.reward_system.decay();
            return reward;
        }
    }

    static class Agent {
        Environment environment;

        Agent(Environment environment) {
            this.environment = environment;
        }

        double act() {
            return this.environment.step();
        }
    }

    public static void main(String[] args) {
        double initial_value = 1.0;
        double decay_rate = 0.99;
        RewardSystem reward_system = new RewardSystem(initial_value, decay_rate);
        Environment environment = new Environment(reward_system);
        Agent agent = new Agent(environment);
        double threshold = 0.01;
        int iterations = 0;
        while (true) {
            double reward = agent.act();
            iterations += 1;
            if (reward < threshold) {
                break;
            }
        }
        System.out.printf("Terminated after %d iterations with reward %.6f%n", iterations, reward);
    }
}