import java.util.Random;

class Environment {
    int current;
    int goal;
    double decay_rate;
    int time_step;

    Environment(int start, int goal, double decay_rate) {
        this.current = start;
        this.goal = goal;
        this.decay_rate = decay_rate;
        this.time_step = 0;
    }

    int[] step(int action) {
        this.current += action;
        this.time_step += 1;
        double reward = compute_reward();
        boolean done = is_done();
        return new int[]{this.current, (int) reward, done ? 1 : 0};
    }

    double compute_reward() {
        int distance = Math.abs(this.current - this.goal);
        double reward = 1.0 / (distance + 1);
        reward *= Math.pow(1 - this.decay_rate, this.time_step);
        return reward;
    }

    boolean is_done() {
        return this.current == this.goal || this.time_step > 1000;
    }
}

class Agent {
    Random action_space;

    Agent(Random action_space) {
        this.action_space = action_space;
    }

    int act(int observation) {
        return this.action_space.nextInt(2); // Assuming action space is {0, 1}
    }
}

public class sample_0281 {
    static double run_episode(Environment env, Agent agent) {
        int observation = env.current;
        double total_reward = 0;
        boolean done = false;
        while (!done) {
            int action = agent.act(observation);
            int[] result = env.step(action);
            observation = result[0];
            double reward = result[1];
            done = result[2] == 1;
            total_reward += reward;
        }
        return total_reward;
    }

    public static void main(String[] args) {
        Random np = new Random(42);
        Environment env = new Environment(0, 10, 0.01);
        Agent agent = new Agent(np);
        double episode_reward = run_episode(env, agent);
        System.out.println("Episode reward: " + episode_reward);
    }
}