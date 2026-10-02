import java.util.Random;

public class sample_0421 {
    public static double[][] initialize_particles(int dim, int num_particles) {
        Random random = new Random();
        double[][] particles = new double[num_particles][dim];
        double[][] velocities = new double[num_particles][dim];
        double[][] best_positions = new double[num_particles][dim];
        double[] best_scores = new double[num_particles];
        
        for (int i = 0; i < num_particles; i++) {
            for (int j = 0; j < dim; j++) {
                particles[i][j] = random.nextDouble();
                velocities[i][j] = random.nextDouble();
                best_positions[i][j] = particles[i][j];
            }
            best_scores[i] = Double.POSITIVE_INFINITY;
        }
        
        return new double[][]{particles, velocities, best_positions, best_scores};
    }

    public static double[][] update_particles(double[][] particles, double[][] velocities, double[][] best_positions, double[] best_scores, double[] global_best, double omega, double phi_p, double phi_g, double[] bounds) {
        Random random = new Random();
        int num_particles = particles.length;
        int dim = particles[0].length;
        
        for (int i = 0; i < num_particles; i++) {
            for (int j = 0; j < dim; j++) {
                double r_p = random.nextDouble();
                double r_g = random.nextDouble();
                velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j]);
                particles[i][j] += velocities[i][j];
                particles[i][j] = Math.max(bounds[0], Math.min(bounds[1], particles[i][j]));
            }
        }
        
        return new double[][]{particles, velocities};
    }

    public static void main(String[] args) {
        int dim = 2;
        int num_particles = 10;
        double[][] result = initialize_particles(dim, num_particles);
        double[][] particles = result[0];
        double[][] velocities = result[1];
        double[][] best_positions = result[2];
        double[] best_scores = result[3];
        double[] global_best = new double[dim];
        
        for (int i = 0; i < dim; i++) {
            global_best[i] = Double.POSITIVE_INFINITY;
        }
        
        double omega = 0.7;
        double phi_p = 0.2;
        double phi_g = 0.3;
        double[] bounds = {0, 1};
        
        while (true) {
            double[][] updated = update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds);
            particles = updated[0];
            velocities = updated[1];
        }
    }
}