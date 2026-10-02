public class sample_0289 {

    static class Environment {
        int max_steps;
        int current_step;

        Environment(int max_steps) {
            this.max_steps = max_steps;
            this.current_step = 0;
        }

        int[] step(int action) {
            this.current_step += 1;
            int reward = calculate_reward();
            boolean done = this.current_step >= this.max_steps;
            return new int[]{reward, done ? 1 : 0};
        }

        int calculate_reward() {
            return 1 - this.current_step / this.max_steps;
        }
    }

    static class Agent {
        Environment environment;

        Agent(Environment environment) {
            this.environment = environment;
        }

        int[] act() {
            int action = 0;
            int[] result = this.environment.step(action);
            return result;
        }
    }

    public static void main(String[] args) {
        int max_steps = 50;
        Environment env = new Environment(max_steps);
        Agent agent = new Agent(env);
        int total_reward = 0;
        while (true) {
            int[] result = agent.act();
            total_reward += result[0];
            if (result[1] == 1) {
                break;
            }
        }
        System.out.println(total_reward);
    }
}