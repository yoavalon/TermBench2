public class sample_0565 {

    static class Swarm {
        int size;
        int dimensions;
        double[][] positions;
        double[][] velocities;

        Swarm(int size, int dimensions) {
            this.size = size;
            this.dimensions = dimensions;
            this.positions = new double[size][dimensions];
            this.velocities = new double[size][dimensions];
        }

        void update_positions() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    positions[i][j] += velocities[i][j];
                }
            }
        }

        void update_velocities(double[] global_best) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    velocities[i][j] = 0.5 * velocities[i][j] + 1.5 * (global_best[j] - positions[i][j]);
                }
            }
        }
    }

    static class Environment {
        Swarm swarm;
        double[] global_best;

        Environment(Swarm swarm) {
            this.swarm = swarm;
            this.global_best = new double[swarm.dimensions];
        }

        void evaluate() {
            for (double[] pos : swarm.positions) {
                double fitness = 0;
                for (double p : pos) {
                    fitness += p;
                }
                if (fitness > sum(global_best)) {
                    global_best = pos.clone();
                }
            }
        }

        void run() {
            while (true) {
                swarm.update_positions();
                evaluate();
                swarm.update_velocities(global_best);
            }
        }

        double sum(double[] array) {
            double sum = 0;
            for (double value : array) {
                sum += value;
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        Swarm swarm = new Swarm(10, 2);
        Environment env = new Environment(swarm);
        env.run();
    }
}