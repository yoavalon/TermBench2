import java.util.Arrays;

public class sample_1027 {
    static double update_velocity(double pos, double vel, double best_pos, double global_best) {
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        double r1 = 0.5;
        double r2 = 0.5;
        double new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos);
        return new_vel;
    }

    static double update_position(double pos, double vel) {
        return pos + vel;
    }

    static void optimize(Function<Double, Double> func, double[] bounds, int n_particles, int max_iter) {
        double[] particles = new double[n_particles];
        double[] velocities = new double[n_particles];
        double[] personal_best = new double[n_particles];
        double global_best;

        for (int i = 0; i < n_particles; i++) {
            particles[i] = bounds[0] + (bounds[1] - bounds[0]) * i / n_particles;
            velocities[i] = 0;
            personal_best[i] = particles[i];
        }
        global_best = Arrays.stream(particles).min().getAsDouble();

        iterate(func, particles, velocities, personal_best, global_best, 0, max_iter);
    }

    static void iterate(Function<Double, Double> func, double[] particles, double[] velocities, double[] personal_best, double global_best, int i, int max_iter) {
        if (i < max_iter) {
            for (int j = 0; j < particles.length; j++) {
                velocities[j] = update_velocity(particles[j], velocities[j], personal_best[j], global_best);
                particles[j] = update_position(particles[j], velocities[j]);
                if (func.apply(particles[j]) < func.apply(personal_best[j])) {
                    personal_best[j] = particles[j];
                }
            }
            global_best = Arrays.stream(personal_best).min().getAsDouble();
            iterate(func, particles, velocities, personal_best, global_best, i + 1, max_iter);
        }
    }

    static void main() {
        Function<Double, Double> test_func = x -> x * x;
        double[] bounds = {-100, 100};
        optimize(test_func, bounds, 30, 1000);
    }

    public static void main(String[] args) {
        main();
    }
}