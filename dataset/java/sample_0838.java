import java.util.Random;

public class sample_0838 {

    static class Swarm {
        int size;
        int dimensions;
        double[][] bounds;
        double[][] positions;
        double[][] velocities;
        double[][] pbest_positions;
        double[] pbest_scores;
        double[] gbest_position;
        double gbest_score;
        Random random = new Random();

        Swarm(int size, int dimensions, double[][] bounds) {
            this.size = size;
            this.dimensions = dimensions;
            this.bounds = bounds;
            this.positions = new double[size][dimensions];
            this.velocities = new double[size][dimensions];
            this.pbest_positions = new double[size][dimensions];
            this.pbest_scores = new double[size];
            this.gbest_position = new double[dimensions];
            this.gbest_score = Double.MAX_VALUE;

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    pbest_scores[i] = Double.MAX_VALUE;
                }
            }
        }

        void initialize() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    positions[i][j] = (bounds[j][1] - bounds[j][0]) * random.nextDouble() + bounds[j][0];
                    velocities[i][j] = (bounds[j][1] - bounds[j][0]) * random.nextDouble() - (bounds[j][1] - bounds[j][0]) / 2;
                }
            }
        }

        void evaluate(double[] function) {
            for (int i = 0; i < size; i++) {
                double score = objective(positions[i]);
                if (score < pbest_scores[i]) {
                    pbest_scores[i] = score;
                    for (int j = 0; j < dimensions; j++) {
                        pbest_positions[i][j] = positions[i][j];
                    }
                }
                if (score < gbest_score) {
                    gbest_score = score;
                    for (int j = 0; j < dimensions; j++) {
                        gbest_position[j] = positions[i][j];
                    }
                }
            }
        }

        void update_velocities(double w, double c1, double c2) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    velocities[i][j] = w * velocities[i][j] + c1 * random.nextDouble() * (pbest_positions[i][j] - positions[i][j]) + c2 * random.nextDouble() * (gbest_position[j] - positions[i][j]);
                }
            }
        }

        void update_positions() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    positions[i][j] += velocities[i][j];
                    positions[i][j] = Math.max(bounds[j][0], Math.min(bounds[j][1], positions[i][j]));
                }
            }
        }

        double optimize(double[] function, int iterations) {
            initialize();
            for (int _ = 0; _ < iterations; _++) {
                evaluate(function);
                update_velocities(0.7, 1.5, 1.5);
                update_positions();
            }
            return gbest_score;
        }

        double objective(double[] x) {
            double sum = 0;
            for (double xi : x) {
                sum += Math.pow(xi - 0.5, 2);
            }
            return sum;
        }
    }

    static void main(String[] args) {
        int dimensions = 3;
        double[][] bounds = { {-10, 10}, {-10, 10}, {-10, 10} };
        int swarm_size = 30;
        int iterations = 100;
        Swarm swarm = new Swarm(swarm_size, dimensions, bounds);
        double best_score = swarm.optimize(new double[dimensions], iterations);
        System.out.println(best_score);
    }
}