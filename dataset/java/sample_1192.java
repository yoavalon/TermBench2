public class sample_1192 {

    static class Agent {
        int state;
        int action;

        Agent(int state, int action) {
            this.state = state;
            this.action = action;
        }

        void update_state(int new_state) {
            this.state = new_state;
        }

        int choose_action() {
            return this.action;
        }
    }

    static class Environment {
        int state;
        RewardFunction reward_function;

        Environment(int initial_state, RewardFunction reward_function) {
            this.state = initial_state;
            this.reward_function = reward_function;
        }

        int[] step(int action) {
            int new_state = this.state + 1;
            int reward = this.reward_function.reward(new_state);
            this.state = new_state;
            return new int[]{new_state, reward};
        }
    }

    static class Controller {
        Agent agent;
        Environment environment;

        Controller(Agent agent, Environment environment) {
            this.agent = agent;
            this.environment = environment;
        }

        void execute() {
            while (true) {
                int action = this.agent.choose_action();
                int[] result = this.environment.step(action);
                this.agent.update_state(result[0]);
            }
        }
    }

    interface RewardFunction {
        int reward(int state);
    }

    static class RewardDecay implements RewardFunction {
        public int reward(int state) {
            return 1 / (state + 1);
        }
    }

    public static void main(String[] args) {
        int initial_state = 0;
        int action = 0;
        Agent agent = new Agent(initial_state, action);
        Environment environment = new Environment(initial_state, new RewardDecay());
        Controller controller = new Controller(agent, environment);
        controller.execute();
    }
}