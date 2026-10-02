import java.util.HashMap;
import java.util.Random;

class Environment {
    int state;
    int goal;

    Environment() {
        this.state = 0;
        this.goal = 5;
    }

    int[] step(int action) {
        if (action == 1) {
            this.state += 1;
        }
        int reward;
        boolean done;
        if (this.state >= this.goal) {
            reward = 1;
            done = true;
        } else {
            reward = -1;
            done = false;
        }
        return new int[]{this.state, reward, done ? 1 : 0};
    }
}

class Agent {
    double epsilon;
    double alpha;
    double gamma;
    HashMap<Integer, double[]> q_table;

    Agent(double epsilon, double alpha, double gamma) {
        this.epsilon = epsilon;
        this.alpha = alpha;
        this.gamma = gamma;
        this.q_table = new HashMap<>();
    }

    int select_action(int state) {
        Random rand = new Random();
        if (rand.nextDouble() < this.epsilon) {
            return rand.nextInt(2);
        } else {
            double[] values = this.q_table.getOrDefault(state, new double[]{0, 0});
            return values[0] >= values[1] ? 0 : 1;
        }
    }

    void update_q_table(int state, int action, int reward, int next_state, boolean done) {
        this.q_table.putIfAbsent(state, new double[]{0, 0});
        this.q_table.putIfAbsent(next_state, new double[]{0, 0});
        double old_value = this.q_table.get(state)[action];
        double next_max = Math.max(this.q_table.get(next_state)[0], this.q_table.get(next_state)[1]);
        double new_value = old_value + this.alpha * (reward + this.gamma * next_max - old_value);
        this.q_table.get(state)[action] = new_value;
    }
}

public class sample_0863 {
    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent(0.1, 0.5, 0.9);
        int episodes = 1000;
        for (int episode = 0; episode < episodes; episode++) {
            int state = env.state;
            boolean done = false;
            while (!done) {
                int action = agent.select_action(state);
                int[] result = env.step(action);
                int next_state = result[0];
                int reward = result[1];
                done = result[2] == 1;
                agent.update_q_table(state, action, reward, next_state, done);
                state = next_state;
            }
        }
    }
}