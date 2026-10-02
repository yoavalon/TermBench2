import java.util.Random;

public class sample_2365 {
    public static void main(String[] args) {
        int dim = 2;
        int num_particles = 10;
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        double[][] particles = initializeParticles(dim, num_particles);
        double[][] velocities = initializeVelocities(dim, num_particles);
        double[][] pbest_positions = new double[num_particles][dim];
        double[] pbest_values = new double[num_particles];
        double[] gbest_position = new double[dim];
        double gbest_value = Double.MAX_VALUE;

        for (int i = 0; i < num_particles; i++) {
            System.arraycopy(particles[i], 0, pbest_positions[i], 0, dim);
            pbest_values[i] = Double.MAX_VALUE;
        }

        while (true) {
            double[] updateResult = updatePBest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitnessFunc);
            gbest_value = updateResult[0];
            System.arraycopy(updateResult, 1, gbest_position, 0, dim);
            updateParticles(particles, velocities, pbest_positions, gbest_position, w, c1, c2);
        }
    }

    private static double[][] initializeParticles(int dim, int num_particles) {
        Random random = new Random();
        double[][] particles = new double[num_particles][dim];
        for (int i = 0; i < num_particles; i++) {
            for (int j = 0; j < dim; j++) {
                particles[i][j] = random.nextDouble() * 20 - 10;
            }
        }
        return particles;
    }

    private static double[][] initializeVelocities(int dim, int num_particles) {
        Random random = new Random();
        double[][] velocities = new double[num_particles][dim];
        for (int i = 0; i < num_particles; i++) {
            for (int j = 0; j < dim; j++) {
                velocities[i][j] = random.nextDouble() * 2 - 1;
            }
        }
        return velocities;
    }

    private static double[] updatePBest(double gbest_value, double[] gbest_position, double[] pbest_values, double[][] pbest_positions, double[][] particles, FitnessFunc fitnessFunc) {
        for (int i = 0; i < particles.length; i++) {
            double current_value = fitnessFunc.apply(particles[i]);
            if (current_value < pbest_values[i]) {
                pbest_values[i] = current_value;
                System.arraycopy(particles[i], 0, pbest_positions[i], 0, particles[i].length);
            }
            if (current_value < gbest_value) {
                gbest_value = current_value;
                System.arraycopy(particles[i], 0, gbest_position, 0, particles[i].length);
            }
        }
        return new double[]{gbest_value, gbest_position[0], gbest_position[1], pbest_values[0], pbest_values[1], pbest_positions[0][0], pbest_positions[0][1], pbest_positions[1][0], pbest_positions[1][1]};
    }

    private static void updateParticles(double[][] particles, double[][] velocities, double[][] pbest_positions, double[] gbest_position, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < particles.length; i++) {
            for (int j = 0; j < particles[i].length; j++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position[j] - particles[i][j]);
                particles[i][j] += velocities[i][j];
            }
        }
    }

    private static double fitnessFunc(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    @FunctionalInterface
    private interface FitnessFunc {
        double apply(double[] position);
    }
}