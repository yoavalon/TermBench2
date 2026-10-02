public class sample_2310 {

    static class Environment {
        double state;
        double decay_rate;

        Environment(double start_state, double decay_rate) {
            this.state = start_state;
            this.decay_rate = decay_rate;
        }

        double update_state(double action) {
            this.state += action * this.decay_rate;
            return this.state;
        }

        double get_reward() {
            return 1 / this.state;
        }
    }

    static class Agent {
        double learning_rate;
        double action = 1.0;

        Agent(double learning_rate) {
            this.learning_rate = learning_rate;
        }

        double choose_action() {
            return this.action;
        }

        void update_action(double reward) {
            this.action += this.learning_rate * reward;
        }
    }

    static class System {
        Environment env;
        Agent agent;

        System(Environment env, Agent agent) {
            this.env = env;
            this.agent = agent;
        }

        void run() {
            while (true) {
                double action = this.agent.choose_action();
                double new_state = this.env.update_state(action);
                double reward = this.env.get_reward();
                this.agent.update_action(reward);
            }
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment(10.0, 0.01);
        Agent agent = new Agent(0.001);
        System system = new System(env, agent);
        system.run();
    }
}