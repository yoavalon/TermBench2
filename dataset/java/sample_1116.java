public class sample_1116 {

    static class Environment {
        int state = 0;
        int max_state = 10;

        int[] step(int action) {
            if (action == 1 && state < max_state) {
                state += 1;
                int reward = 1;
                return new int[]{state, reward};
            } else {
                int reward = 0;
                return new int[]{state, reward};
            }
        }
    }

    static class Agent {
        double learning_rate;
        double discount_factor;
        double[] q_values = new double[11];

        Agent(double learning_rate, double discount_factor) {
            this.learning_rate = learning_rate;
            this.discount_factor = discount_factor;
        }

        int choose_action(int state) {
            return state < 10 ? 1 : 0;
        }

        void update_q_value(int state, int action, int reward, int next_state) {
            double old_value = q_values[state];
            double next_max = 0;
            for (double q_value : q_values) {
                if (q_value > next_max) {
                    next_max = q_value;
                }
            }
            double new_value = (1 - learning_rate) * old_value + learning_rate * (reward + discount_factor * next_max);
            q_values[state] = new_value;
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent(0.1, 0.9);
        while (true) {
            int state = env.state;
            int action = agent.choose_action(state);
            int[] result = env.step(action);
            int next_state = result[0];
            int reward = result[1];
            agent.update_q_value(state, action, reward, next_state);
        }
    }
}