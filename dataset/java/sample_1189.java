import java.util.Random;

class Agent {

    int state = 0;
    double discount_factor = 0.9;

    int take_action() {
        Random random = new Random();
        return random.nextInt(2);
    }

    double receive_reward(int action) {
        return action == 1 ? 1 : 0;
    }

    void update_state(int action) {
        if (action == 1) {
            state += 1;
        } else {
            state -= 1;
        }
    }
}

class Environment {

    int[] action_space = {0, 1};

    int[] get_possible_actions() {
        return action_space;
    }
}

class Simulator {

    Agent agent = new Agent();
    Environment environment = new Environment();
    double total_reward = 0;

    double run_step() {
        int action = agent.take_action();
        double reward = agent.receive_reward(action) * Math.pow(agent.discount_factor, agent.state);
        total_reward += reward;
        agent.update_state(action);
        return reward;
    }

    void simulate() {
        while (true) {
            run_step();
        }
    }
}

public class sample_1189 {
    public static void main(String[] args) {
        Simulator simulator = new Simulator();
        simulator.simulate();
    }
}