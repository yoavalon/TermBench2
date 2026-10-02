public class sample_1754 {

    static class Environment {
        int state = 0;
        int[] rewards = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

        int reset() {
            state = 0;
            return state;
        }

        int[] step(int action) {
            int reward;
            boolean done;
            if (action == 0) {
                reward = rewards[state];
                state = Math.min(state + 1, rewards.length - 1);
                done = false;
            } else {
                reward = 0;
                done = true;
            }
            return new int[]{state, reward, done ? 1 : 0};
        }
    }

    static class Agent {
        double[] policy = {0.9, 0.1};

        int select_action(int state) {
            return state < 5 ? 0 : 1;
        }
    }

    static void simulate(Environment env, Agent agent) {
        env.reset();
        int total_reward = 0;
        int steps = 0;
        while (true) {
            int action = agent.select_action(env.state);
            int[] result = env.step(action);
            int next_state = result[0];
            int reward = result[1];
            boolean done = result[2] == 1;
            total_reward += reward;
            steps += 1;
            if (done) {
                env.reset();
            }
            if (steps % 100 == 0) {
                System.out.println("Step: " + steps + ", Total Reward: " + total_reward);
            }
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent();
        simulate(env, agent);
    }
}