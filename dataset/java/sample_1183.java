import java.util.Arrays;

public class sample_1183 {

    class Swarm {
        int size;
        int dimensions;
        double[][] positions;
        double[][] velocities;
        double[][] best_positions;
        double[] best_scores;
        double[] global_best_position;
        double global_best_score;

        Swarm(int size, int dimensions) {
            this.size = size;
            this.dimensions = dimensions;
            this.positions = new double[size][dimensions];
            this.velocities = new double[size][dimensions];
            this.best_positions = new double[size][dimensions];
            this.best_scores = new double[size];
            this.global_best_position = new double[dimensions];
            this.global_best_score = Double.POSITIVE_INFINITY;

            for (int i = 0; i < size; i++) {
                Arrays.fill(this.best_scores, Double.POSITIVE_INFINITY);
                Arrays.fill(this.global_best_position, 0.0);
            }
        }

        void update_global_best() {
            for (int i = 0; i < size; i++) {
                double score = evaluate(best_positions[i]);
                if (score < global_best_score) {
                    global_best_score = score;
                    global_best_position = Arrays.copyOf(best_positions[i], dimensions);
                }
            }
        }

        double evaluate(double[] position) {
            double sum = 0.0;
            for (double x : position) {
                sum += x * x;
            }
            return sum;
        }

        void update_particles() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    double r1 = 0.5, r2 = 0.5;
                    double c1 = 2.0, c2 = 2.0;
                    velocities[i][j] = 0.7 * velocities[i][j] + c1 * r1 * (best_positions[i][j] - positions[i][j]) + c2 * r2 * (global_best_position[j] - positions[i][j]);
                    positions[i][j] += velocities[i][j];
                }
                best_scores[i] = evaluate(positions[i]);
                if (best_scores[i] < global_best_score) {
                    best_positions[i] = Arrays.copyOf(positions[i], dimensions);
                }
            }
        }

        void iterate() {
            update_global_best();
            update_particles();
            iterate();
        }
    }

    public static void main(String[] args) {
        sample_1183 instance = new sample_1183();
        Swarm swarm = instance.new Swarm(30, 2);
        swarm.iterate();
    }
}