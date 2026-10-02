import java.util.Random;

public class sample_0285 {

    static class Environment {
        private int state;
        private int[] action_space = {0, 1};
        private Random rand = new Random();

        public Environment() {
            this.state = rand.nextInt(10);
        }

        public int[] step(int action) {
            double reward = 0;
            if (action == 0) {
                reward = 1 - (double) this.state / 10.0;
            } else {
                reward = (double) this.state / 10.0;
            }
            this.state = rand.nextInt(10);
            return new int[]{this.state, (int) reward, this.is_done() ? 1 : 0};
        }

        public boolean is_done() {
            return rand.nextDouble() < 0.05;
        }
    }

    static class Agent {
        private int[] action_space;
        private double epsilon = 1.0;
        private Random rand = new Random();

        public Agent(int[] action_space) {
            this.action_space = action_space;
        }

        public int choose_action(int state) {
            if (rand.nextDouble() < this.epsilon) {
                return action_space[rand.nextInt(action_space.length)];
            } else {
                return this.policy(state);
            }
        }

        public int policy(int state) {
            return state < 5 ? 0 : 1;
        }
    }

    public static void train(Agent agent, Environment env, int episodes) {
        for (int episode = 0; episode < episodes; episode++) {
            int[] state = env.step(-1); // Resetting state is not shown in Python, assuming initial state is reset
            boolean done = false;
            while (!done) {
                int action = agent.choose_action(state[0]);
                int[] next_state = env.step(action);
                state = next_state;
                done = next_state[2] == 1;
            }
            agent.epsilon = Math.max(0.01, agent.epsilon * 0.99);
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent(env.action_space);
        int episodes = 1000;
        train(agent, env, episodes);
    }
}