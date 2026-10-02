import java.util.Random;

public class sample_2064 {

    static class Environment {
        int num_states;
        int num_actions;

        Environment(int num_states, int num_actions) {
            this.num_states = num_states;
            this.num_actions = num_actions;
        }

        int[] step(int state, int action) {
            int reward = _compute_reward(state, action);
            int next_state = _transition(state, action);
            boolean done = _is_done(next_state);
            return new int[]{next_state, reward, done ? 1 : 0};
        }

        int _compute_reward(int state, int action) {
            return (int) -Math.sqrt(Math.pow(state - action, 2));
        }

        int _transition(int state, int action) {
            return (state + action) % num_states;
        }

        boolean _is_done(int state) {
            return state == 0;
        }
    }

    static class Agent {
        int num_actions;
        double[] policy;

        Agent(int num_actions) {
            this.num_actions = num_actions;
            this.policy = new double[num_actions];
            for (int i = 0; i < num_actions; i++) {
                policy[i] = 1.0 / num_actions;
            }
        }

        int select_action(Random random) {
            double r = random.nextDouble();
            double cumulativeProbability = 0.0;
            for (int i = 0; i < num_actions; i++) {
                cumulativeProbability += policy[i];
                if (r <= cumulativeProbability) {
                    return i;
                }
            }
            return num_actions - 1; // Fallback in case of rounding error
        }

        void update_policy(int state, int action, int reward) {
            double meanPolicy = 0.0;
            for (double prob : policy) {
                meanPolicy += prob;
            }
            policy[action] += 0.1 * (reward - meanPolicy);
        }
    }

    public static void main(String[] args) {
        int num_states = 10;
        int num_actions = 5;
        int max_steps = 100;
        double gamma = 0.99;
        Environment env = new Environment(num_states, num_actions);
        Agent agent = new Agent(num_actions);
        Random random = new Random();
        int state = random.nextInt(num_states);
        for (int step = 0; step < max_steps; step++) {
            int action = agent.select_action(random);
            int[] result = env.step(state, action);
            int next_state = result[0];
            int reward = result[1];
            boolean done = result[2] == 1;
            agent.update_policy(state, action, reward);
            state = next_state;
            if (done) {
                break;
            }
        }
    }
}