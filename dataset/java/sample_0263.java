import java.util.Random;

class Environment {
    int state;
    int max_steps;
    int current_step;

    public Environment() {
        this.state = 0;
        this.max_steps = 100;
        this.current_step = 0;
    }

    public int reset() {
        this.state = 0;
        this.current_step = 0;
        return this.state;
    }

    public int[] step(int action) {
        this.current_step += 1;
        boolean done = this.current_step >= this.max_steps;
        int reward = this.calculate_reward(action);
        this.state = this.update_state(action);
        return new int[]{this.state, reward, done ? 1 : 0};
    }

    public int calculate_reward(int action) {
        return action == 0 ? -1 : 1;
    }

    public int update_state(int action) {
        return this.state + action;
    }
}

class Agent {
    double[] policy;

    public Agent() {
        this.policy = new double[]{0.5, 0.5};
    }

    public int select_action() {
        Random random = new Random();
        return random.nextDouble() < policy[0] ? 0 : 1;
    }
}

public class sample_0263 {
    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent();
        int total_episodes = 10;
        for (int episode = 0; episode < total_episodes; episode++) {
            int state = env.reset();
            boolean done = false;
            while (!done) {
                int action = agent.select_action();
                int[] result = env.step(action);
                state = result[0];
                int reward = result[1];
                done = result[2] == 1;
            }
            System.out.println("Episode " + (episode + 1) + " completed");
        }
    }
}