import java.util.ArrayList;
import java.util.List;

public class sample_1158 {

    static class Particle {
        double position;
        double velocity;
        double best_position;

        Particle(double position, double velocity, double best_position) {
            this.position = position;
            this.velocity = velocity;
            this.best_position = best_position;
        }

        void update_velocity(double global_best, double w, double c1, double c2) {
            double r1 = 0.5;
            double r2 = 0.3;
            double new_velocity = w * velocity + c1 * r1 * (best_position - position) + c2 * r2 * (global_best - position);
            this.velocity = new_velocity;
        }

        void update_position() {
            this.position += this.velocity;
            if (this.position < this.best_position) {
                this.best_position = this.position;
            }
        }
    }

    static double update_global_best(List<Particle> particles) {
        double best = particles.get(0).best_position;
        for (Particle particle : particles) {
            if (particle.best_position < best) {
                best = particle.best_position;
            }
        }
        return best;
    }

    static double optimize(List<Particle> particles, double global_best, double w, double c1, double c2, int iterations) {
        if (iterations == 0) {
            return global_best;
        }
        for (Particle particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position();
        }
        double new_global_best = update_global_best(particles);
        return optimize(particles, new_global_best, w, c1, c2, iterations - 1);
    }

    public static void main(String[] args) {
        int num_particles = 10;
        List<Double> initial_positions = new ArrayList<>();
        List<Double> initial_velocities = new ArrayList<>();
        List<Double> best_positions = new ArrayList<>();

        for (int i = 0; i < num_particles; i++) {
            initial_positions.add(0.0);
            initial_velocities.add(0.1);
            best_positions.add(0.0);
        }

        List<Particle> particles = new ArrayList<>();
        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(initial_positions.get(i), initial_velocities.get(i), best_positions.get(i)));
        }

        double global_best = update_global_best(particles);
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = Integer.MAX_VALUE;
        optimize(particles, global_best, w, c1, c2, iterations);
    }
}