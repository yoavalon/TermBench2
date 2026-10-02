import java.util.Arrays;

public class sample_0592 {

    static class Swarm {
        int size;
        int dimensions;
        double[][] particles;
        double[][] velocities;
        double[][] best_positions;
        double[] best_scores;
        double[] global_best;
        double global_best_score;

        Swarm(int size, int dimensions) {
            this.size = size;
            this.dimensions = dimensions;
            this.particles = new double[size][dimensions];
            this.velocities = new double[size][dimensions];
            this.best_positions = new double[size][dimensions];
            this.best_scores = new double[size];
            Arrays.fill(this.best_scores, Double.POSITIVE_INFINITY);
            this.global_best = new double[dimensions];
            this.global_best_score = Double.POSITIVE_INFINITY;
        }

        void update_global_best() {
            for (int i = 0; i < size; i++) {
                if (best_scores[i] < global_best_score) {
                    global_best_score = best_scores[i];
                    global_best = Arrays.copyOf(best_positions[i], dimensions);
                }
            }
        }

        void update_particles() {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < dimensions; j++) {
                    double r1 = 0.5;
                    double r2 = 0.5;
                    double cognitive = r1 * (best_positions[i][j] - particles[i][j]);
                    double social = r2 * (global_best[j] - particles[i][j]);
                    velocities[i][j] += cognitive + social;
                    particles[i][j] += velocities[i][j];
                }
            }
        }

        void evaluate(double[] objective_function(double[] position)) {
            for (int i = 0; i < size; i++) {
                double score = objective_function(particles[i]);
                if (score < best_scores[i]) {
                    best_scores[i] = score;
                    best_positions[i] = Arrays.copyOf(particles[i], dimensions);
                }
            }
            update_global_best();
        }
    }

    static class Optimization {
        Swarm swarm;
        double[] objective_function;

        Optimization(Swarm swarm, double[] objective_function(double[] position)) {
            this.swarm = swarm;
            this.objective_function = objective_function;
        }

        void run() {
            while (true) {
                swarm.update_particles();
                swarm.evaluate(this.objective_function);
            }
        }
    }

    static double[] objective_function(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return new double[]{sum};
    }

    public static void main(String[] args) {
        int size = 30;
        int dimensions = 2;
        Swarm swarm = new Swarm(size, dimensions);
        Optimization optimization = new Optimization(swarm, sample_0592::objective_function);
        optimization.run();
    }
}