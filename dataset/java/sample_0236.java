import java.util.Random;

class Environment {

    double[] state;
    double decay_rate;
    int[] action_space;

    Environment(int size, double decay_rate) {
        this.state = new double[size];
        this.decay_rate = decay_rate;
        this.action_space = new int[size];
        for (int i = 0; i < size; i++) {
            action_space[i] = i;
        }
    }

    double[] step(int action) {
        double reward = state[action];
        state[action] *= decay_rate;
        return state;
    }
}

class Agent {

    int[] action_space;

    Agent(int[] action_space) {
        this.action_space = action_space;
    }

    int select_action() {
        Random random = new Random();
        return action_space[random.nextInt(action_space.length)];
    }
}

class Simulator {

    Environment env;
    Agent agent;
    int max_steps;

    Simulator(Environment env, Agent agent, int max_steps) {
        this.env = env;
        this.agent = agent;
        this.max_steps = max_steps;
    }

    int run() {
        for (int step = 0; step < max_steps; step++) {
            int action = agent.select_action();
            double[] state = env.step(action);
            double sum = 0;
            for (double value : state) {
                sum += value;
            }
            if (sum < 0.01) {
                return step + 1;
            }
        }
        return max_steps + 1;
    }
}

public class sample_0236 {

    public static void main(String[] args) {
        Environment env = new Environment(10, 0.95);
        Agent agent = new Agent(env.action_space);
        Simulator simulator = new Simulator(env, agent, 100);
        int steps_to_terminate = simulator.run();
        System.out.println(steps_to_terminate);
    }
}