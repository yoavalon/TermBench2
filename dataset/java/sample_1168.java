import java.util.Random;

class Environment {
    int state;

    Environment() {
        Random rand = new Random();
        this.state = rand.nextInt(3);
    }

    int[] step(int action) {
        int reward = 0;
        if (action == this.state) {
            reward = 1;
        }
        this.state = new Random().nextInt(3);
        return new int[]{this.state, reward};
    }
}

class Agent {
    double[] policy = {0.33, 0.33, 0.34};

    int select_action() {
        Random rand = new Random();
        return rand.nextInt(3);
    }
}

class Simulator {
    Environment env;
    Agent agent;
    int total_reward = 0;

    Simulator(Environment environment, Agent agent) {
        this.env = environment;
        this.agent = agent;
    }

    void simulate() {
        int state = this.env.state;
        int action = this.agent.select_action();
        int[] result = this.env.step(action);
        int next_state = result[0];
        int reward = result[1];
        this.total_reward += reward;
        this.simulate();
    }
}

public class sample_1168 {
    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent();
        Simulator simulator = new Simulator(env, agent);
        simulator.simulate();
    }
}