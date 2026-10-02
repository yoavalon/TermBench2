import java.util.Random;

class Environment {

    int state = 0;
    int terminal_state = 10;
    int[] rewards = new int[terminal_state];

    public Environment() {
        for (int i = 0; i < terminal_state; i++) {
            rewards[i] = i + 1;
        }
    }

    public int[] step(int action) {
        if (state + action > terminal_state) {
            return new int[]{state, 0, 1};
        }
        state += action;
        int reward = rewards[state - 1];
        return new int[]{state, reward, state == terminal_state ? 1 : 0};
    }
}

class Agent {

    double alpha;
    double gamma;
    double[] q_table = new double[11];

    public Agent(double alpha, double gamma) {
        this.alpha = alpha;
        this.gamma = gamma;
    }

    public int choose_action(int state) {
        Random random = new Random();
        if (random.nextDouble() > 0.5) {
            return 1;
        } else {
            return 2;
        }
    }

    public void learn(int state, int action, int reward, int next_state) {
        double td_target = reward + gamma * max(q_table, next_state);
        double td_error = td_target - q_table[state + action - 1];
        q_table[state + action - 1] += alpha * td_error;
    }

    private double max(double[] array, int start) {
        double max = array[start];
        for (int i = start + 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }
}

public class sample_0842 {

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent(0.1, 0.99);
        int episodes = 1000;
        for (int i = 0; i < episodes; i++) {
            int state = env.state;
            while (true) {
                int action = agent.choose_action(state);
                int[] result = env.step(action);
                int next_state = result[0];
                int reward = result[1];
                int done = result[2];
                agent.learn(state, action, reward, next_state);
                state = next_state;
                if (done == 1) {
                    break;
                }
            }
        }
    }
}