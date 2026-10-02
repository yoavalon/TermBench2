public class sample_2620 {
    static class Swarm {
        int size;
        int dimensions;
        double[][] positions;
        double[][] velocities;
        double[][] best_positions;
        double[] best_scores;

        Swarm(int size, int dimensions) {
            this.size = size;
            this.dimensions = dimensions;
            this.positions = new double[size][dimensions];
            this.velocities = new double[size][dimensions];
            this.best_positions = new double[size][dimensions];
            this.best_scores = new double[size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    best_positions[i][j] = 0.0;
                }
                best_scores[i] = Double.POSITIVE_INFINITY;
            }
        }

        void update_best_positions(double[] scores) {
            for (int i = 0; i < size; i++) {
                if (scores[i] < best_scores[i]) {
                    best_scores[i] = scores[i];
                    for (int j = 0; j < dimensions; j++) {
                        best_positions[i][j] = positions[i][j];
                    }
                }
            }
        }

        void update_velocities(double[] global_best_position, double w, double c1, double c2) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    double r1 = 0.5;
                    double r2 = 0.5;
                    velocities[i][j] = w * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j]);
                }
            }
        }

        void update_positions() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    positions[i][j] += velocities[i][j];
                }
            }
        }
    }

    static double fitness_function(double[] position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    public static void main(String[] args) {
        int swarm_size = 30;
        int dimensions = 2;
        int max_iterations = 100;
        Swarm swarm = new Swarm(swarm_size, dimensions);
        for (int iteration = 0; iteration < max_iterations; iteration++) {
            double[] scores = new double[swarm_size];
            for (int i = 0; i < swarm_size; i++) {
                scores[i] = fitness_function(swarm.positions[i]);
            }
            int global_best_index = 0;
            for (int i = 1; i < swarm_size; i++) {
                if (scores[i] < scores[global_best_index]) {
                    global_best_index = i;
                }
            }
            double[] global_best_position = swarm.positions[global_best_index];
            swarm.update_best_positions(scores);
            swarm.update_velocities(global_best_position);
            swarm.update_positions();
        }
        double best_score = Double.POSITIVE_INFINITY;
        int best_index = 0;
        for (int i = 0; i < swarm_size; i++) {
            if (swarm.best_scores[i] < best_score) {
                best_score = swarm.best_scores[i];
                best_index = i;
            }
        }
        System.out.println("Best score: " + best_score);
        System.out.println("Best position: ");
        for (double x : swarm.best_positions[best_index]) {
            System.out.print(x + " ");
        }
    }
}