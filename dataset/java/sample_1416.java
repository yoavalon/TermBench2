import java.util.Random;

public class sample_1416 {

    static class Environment {
        double[] state;

        Environment(int size) {
            this.state = new double[size];
        }

        double[] reset() {
            for (int i = 0; i < state.length; i++) {
                state[i] = 0;
            }
            return state;
        }

        double[] step(int action) {
            double reward = new Random().nextGaussian();
            state[action] += 1;
            boolean done = false;
            for (double s : state) {
                if (s > 10) {
                    done = true;
                    break;
                }
            }
            return new double[]{state[0], state[1], state[2], state[3], state[4], reward, done ? 1 : 0};
        }
    }

    static class Agent {
        int[] action_space;

        Agent(int[] action_space) {
            this.action_space = action_space;
        }

        int choose_action() {
            return action_space[new Random().nextInt(action_space.length)];
        }
    }

    static double[] train_agent(Environment env, Agent agent, int episodes, double decay_rate) {
        double[] rewards = new double[episodes];
        for (int episode = 0; episode < episodes; episode++) {
            double[] state = env.reset();
            double total_reward = 0;
            for (int t = 0; t < 100; t++) {
                int action = agent.choose_action();
                double[] result = env.step(action);
                total_reward += result[5];
                if (result[6] == 1) {
                    break;
                }
            }
            rewards[episode] = total_reward;
            if (episode > 0 && episode % 10 == 0) {
                for (int i = 0; i < rewards.length; i++) {
                    rewards[i] *= decay_rate;
                }
            }
        }
        return rewards;
    }

    public static void main(String[] args) {
        int env_size = 5;
        int[] action_space = new int[env_size];
        for (int i = 0; i < env_size; i++) {
            action_space[i] = i;
        }
        Environment env = new Environment(env_size);
        Agent agent = new Agent(action_space);
        int episodes = 50;
        double decay_rate = 0.9;
        train_agent(env, agent, episodes, decay_rate);
    }
}