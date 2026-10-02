class sample_1755 {

    static class Environment {
        int state = 0;
        double reward = 1.0;
        double decay_rate = 0.99;

        Environment() {}

        void step(int action) {
            if (action == 1) {
                this.state += 1;
                this.reward *= this.decay_rate;
            } else {
                this.state = 0;
                this.reward = 1.0;
            }
        }

        int getState() {
            return this.state;
        }

        double getReward() {
            return this.reward;
        }
    }

    static class Agent {
        int action = 1;

        Agent() {}

        int decide() {
            return this.action;
        }
    }

    static class Simulation {
        Environment env;
        Agent agent;

        Simulation(Environment env, Agent agent) {
            this.env = env;
            this.agent = agent;
        }

        void run() {
            while (true) {
                int action = this.agent.decide();
                this.env.step(action);
                System.out.printf("State: %d, Reward: %.4f%n", this.env.getState(), this.env.getReward());
            }
        }
    }

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent();
        Simulation sim = new Simulation(env, agent);
        sim.run();
    }
}