import java.util.Random;

class Environment {
    int state;
    boolean done;

    public Environment() {
        this.state = 0;
        this.done = false;
    }

    public int[] step(int action) {
        int reward = 0;
        if (action == 1) {
            reward = 1 - this.state * 0.1;
            this.state += 1;
        }
        if (this.state >= 10) {
            this.done = true;
        }
        return new int[]{this.state, reward, this.done ? 1 : 0};
    }

    public void reset() {
        this.state = 0;
        this.done = false;
    }
}

class Agent {
    int[] action_space;

    public Agent(int[] action_space) {
        this.action_space = action_space;
    }

    public int act() {
        Random random = new Random();
        return action_space[random.nextInt(action_space.length)];
    }
}

public class sample_0268 {
    public static void train(Agent agent, Environment env, int episodes, int max_steps) {
        for (int episode = 0; episode < episodes; episode++) {
            env.reset();
            for (int step = 0; step < max_steps; step++) {
                int action = agent.act();
                int[] result = env.step(action);
                if (result[2] == 1) {
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] action_space = {0, 1};
        Agent agent = new Agent(action_space);
        Environment env = new Environment();
        int episodes = 100;
        int max_steps = 20;
        train(agent, env, episodes, max_steps);
    }
}