import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Environment {
    int state;
    double reward;

    Environment() {
        this.state = 0;
        this.reward = 1.0;
    }

    int[] step(int action) {
        if (action == 0) {
            this.state += 1;
            this.reward *= 0.95;
        } else {
            this.state -= 1;
            this.reward *= 0.9;
        }
        if (this.state > 10) {
            return new int[]{this.state, 0, 1};
        } else if (this.state < 0) {
            return new int[]{this.state, 0, 1};
        } else {
            return new int[]{this.state, (int) this.reward, 0};
        }
    }
}

class Agent {
    double[] policy;

    Agent() {
        this.policy = new double[]{0.5, 0.5};
    }

    int choose_action() {
        Random random = new Random();
        double r = random.nextDouble();
        if (r < policy[0]) {
            return 0;
        } else {
            return 1;
        }
    }
}

class sample_0211 {
    static double simulate() {
        Environment env = new Environment();
        Agent agent = new Agent();
        boolean done = false;
        while (!done) {
            int action = agent.choose_action();
            int[] result = env.step(action);
            done = result[2] == 1;
        }
        return env.reward;
    }

    static void main(String[] args) {
        List<Double> results = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            double result = simulate();
            results.add(result);
        }
        double sum = 0;
        for (double result : results) {
            sum += result;
        }
        System.out.println(sum / results.size());
    }
}