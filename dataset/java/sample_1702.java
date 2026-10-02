public class sample_1702 {

    static class Environment {
        int state;
        int max_state;

        Environment() {
            this.state = 0;
            this.max_state = 100;
        }

        int[] step(int action) {
            int reward = 0;
            boolean done = false;
            if (action == 1 && this.state < this.max_state) {
                this.state += 1;
                reward = this.max_state - this.state;
            } else if (action == 0 && this.state > 0) {
                this.state -= 1;
                reward = this.state;
            }
            if (this.state == this.max_state) {
                done = true;
            }
            return new int[]{this.state, reward, done ? 1 : 0};
        }
    }

    static class Agent {
        Environment env;
        int action;

        Agent(Environment env) {
            this.env = env;
            this.action = 1;
        }

        void decide() {
            if (this.env.state > 50) {
                this.action = 0;
            } else {
                this.action = 1;
            }
        }
    }

    public static void run() {
        Environment env = new Environment();
        Agent agent = new Agent(env);
        int total_reward = 0;
        while (true) {
            int[] result = env.step(agent.action);
            total_reward += result[1];
            agent.decide();
            if (result[2] == 1) {
                env.state = 0;
            }
        }
    }

    public static void main(String[] args) {
        run();
    }
}