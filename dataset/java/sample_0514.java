public class sample_0514 {

    static class Environment {
        int state = 0;
        int max_state = 100;
        double decay_rate = 0.99;

        Environment() {}

        void step(int action) {
            int reward = calculate_reward();
            update_state(action);
            System.out.println("State: " + state + ", Reward: " + reward + ", Total Reward: " + total_reward);
        }

        int calculate_reward() {
            return (int) (100 - state * decay_rate);
        }

        void update_state(int action) {
            state += action;
            if (state > max_state) {
                state = max_state;
            }
        }
    }

    static class Agent {
        Environment env;
        int action = 1;

        Agent(Environment env) {
            this.env = env;
        }

        void act() {
            env.step(action);
        }
    }

    static int total_reward = 0;

    public static void simulate() {
        Environment env = new Environment();
        Agent agent = new Agent(env);
        while (true) {
            agent.act();
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}