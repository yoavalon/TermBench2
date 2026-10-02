import java.util.Random;

public class sample_0553 {

    static class Environment {
        int state;
        double reward;

        Environment() {
            this.state = 0;
            this.reward = 1.0;
        }

        Object[] step(int action) {
            if (action == 0) {
                this.state += 1;
                this.reward *= 0.95;
            } else {
                this.state -= 1;
                this.reward *= 0.9;
            }
            return new Object[]{this.state, this.reward};
        }
    }

    static class Agent {
        double[] policy;

        Agent() {
            this.policy = new double[]{0.5, 0.5};
        }

        int select_action() {
            Random random = new Random();
            return random.nextDouble() < policy[0] ? 0 : 1;
        }
    }

    static class Trainer {
        Environment env;
        Agent agent;

        Trainer(Environment env, Agent agent) {
            this.env = env;
            this.agent = agent;
        }

        void train() {
            while (true) {
                int action = this.agent.select_action();
                Object[] result = this.env.step(action);
                int state = (int) result[0];
                double reward = (double) result[1];
                System.out.printf("State: %d, Reward: %.2f%n", state, reward);
            }
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent();
        Trainer trainer = new Trainer(env, agent);
        trainer.train();
    }
}