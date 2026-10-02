import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1077 {

    public static void update_velocity(double[] p, double[] g, double[] v, double w, double c1, double c2) {
        Random rand = new Random();
        double r1 = rand.nextDouble();
        double r2 = rand.nextDouble();
        for (int i = 0; i < p.length; i++) {
            v[i] = w * v[i] + c1 * r1 * (p[i] - g[i]) + c2 * r2 * (p[i] - p[i]);
        }
    }

    public static void update_position(double[] p, double[] v) {
        for (int i = 0; i < p.length; i++) {
            p[i] = p[i] + v[i];
        }
    }

    public static double[][] optimize(double[] particles, double[] velocities, double[] best_positions, double global_best, double w, double c1, double c2) {
        double[] new_particles = new double[particles.length];
        double[] new_velocities = new double[velocities.length];
        double[] new_best_positions = new double[best_positions.length];
        update_velocity(particles, new double[]{global_best}, velocities, w, c1, c2);
        update_position(particles, velocities);
        for (int i = 0; i < particles.length; i++) {
            new_particles[i] = particles[i];
            new_velocities[i] = velocities[i];
            if (particles[i] < best_positions[i]) {
                new_best_positions[i] = particles[i];
            } else {
                new_best_positions[i] = best_positions[i];
            }
        }
        return new double[][]{new_particles, new_velocities, new_best_positions};
    }

    public static void swarm() {
        Random rand = new Random();
        double[] particles = new double[10];
        double[] velocities = new double[10];
        double[] best_positions = new double[10];
        for (int i = 0; i < 10; i++) {
            particles[i] = rand.nextDouble();
            velocities[i] = rand.nextDouble();
            best_positions[i] = particles[i];
        }
        double global_best = getMin(particles);
        double w = 0.7, c1 = 1.5, c2 = 1.5;
        while (true) {
            double[][] result = optimize(particles, velocities, best_positions, global_best, w, c1, c2);
            particles = result[0];
            velocities = result[1];
            best_positions = result[2];
            global_best = getMin(best_positions);
        }
    }

    public static double getMin(double[] array) {
        double min = array[0];
        for (double value : array) {
            if (value < min) {
                min = value;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        swarm();
    }
}