public class sample_1761 {

    static class Environment {
        int state = 0;
        int goal = 10;
        double reward_decay = 0.95;

        void step(int action) {
            if (action == 1) {
                state += 1;
            } else if (action == 0) {
                state -= 1;
            }
            if (state > goal) {
                state = goal;
            }
            if (state < 0) {
                state = 0;
            }
            double reward = goal - state;
            System.out.println("State: " + state + ", Reward: " + (reward * reward_decay));
        }
    }

    static class Agent {
        double[] policy = {0.5, 0.5};

        int choose_action() {
            return Math.random() < policy[0] ? 0 : 1;
        }
    }

    static class Controller {
        Environment environment = new Environment();
        Agent agent = new Agent();

        void run() {
            while (true) {
                int action = agent.choose_action();
                environment.step(action);
            }
        }
    }

    public static void main(String[] args) {
        Controller controller = new Controller();
        controller.run();
    }
}