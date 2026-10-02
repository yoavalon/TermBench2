public class sample_1456 {

    static class Environment {
        int state;
        int max_steps;
        int step_count;

        Environment(int max_steps) {
            this.state = 0;
            this.max_steps = max_steps;
            this.step_count = 0;
        }

        void reset() {
            this.state = 0;
            this.step_count = 0;
        }

        int[] step(int action) {
            this.step_count += 1;
            int reward = calculate_reward(action);
            this.state = update_state(action);
            boolean done = this.step_count >= this.max_steps;
            return new int[]{this.state, reward, done ? 1 : 0};
        }

        int calculate_reward(int action) {
            return action == 1 ? 1 : -1;
        }

        int update_state(int action) {
            return (this.state + action) % 10;
        }
    }

    static class Agent {
        Environment env;
        int[] policy = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

        Agent(Environment env) {
            this.env = env;
        }

        int act(int state) {
            return this.policy[state];
        }
    }

    static int run_episode(Environment env, Agent agent) {
        env.reset();
        boolean done = false;
        int total_reward = 0;
        while (!done) {
            int state = env.state;
            int action = agent.act(state);
            int[] stepResult = env.step(action);
            total_reward += stepResult[1];
            done = stepResult[2] == 1;
        }
        return total_reward;
    }

    static void main() {
        Environment env = new Environment(20);
        Agent agent = new Agent(env);
        int total_episodes = 10;
        int[] episode_rewards = new int[total_episodes];
        for (int i = 0; i < total_episodes; i++) {
            int episode_reward = run_episode(env, agent);
            episode_rewards[i] = episode_reward;
        }
        System.out.print("Episode rewards: ");
        for (int reward : episode_rewards) {
            System.out.print(reward + " ");
        }
    }

    public static void main(String[] args) {
        main();
    }
}