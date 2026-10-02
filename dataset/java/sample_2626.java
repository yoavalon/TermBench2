import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2626 {

    public static class Particle {
        List<Double> position;
        List<Double> velocity;
        List<Double> best_position;
        double best_score;

        public Particle(int dimensions, List<Double> position) {
            if (position != null) {
                this.position = position;
            } else {
                this.position = new ArrayList<>();
                Random random = new Random();
                for (int i = 0; i < dimensions; i++) {
                    this.position.add(random.nextDouble() * 2 - 1);
                }
            }
            this.velocity = new ArrayList<>();
            Random random = new Random();
            for (int i = 0; i < dimensions; i++) {
                this.velocity.add(random.nextDouble() * 2 - 1);
            }
            this.best_position = new ArrayList<>(this.position);
            this.best_score = Double.MAX_VALUE;
        }

        public void update_velocity(List<Double> global_best, double w, double c1, double c2) {
            Random random = new Random();
            for (int i = 0; i < this.position.size(); i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive = c1 * r1 * (this.best_position.get(i) - this.position.get(i));
                double social = c2 * r2 * (global_best.get(i) - this.position.get(i));
                this.velocity.set(i, w * this.velocity.get(i) + cognitive + social);
            }
        }

        public void update_position(List<Double> bounds) {
            for (int i = 0; i < this.position.size(); i++) {
                this.position.set(i, this.position.get(i) + this.velocity.get(i));
                if (bounds != null) {
                    this.position.set(i, Math.max(bounds.get(0), Math.min(bounds.get(1), this.position.get(i))));
                }
            }
        }

        public void evaluate(double[] function) {
            double current_score = 0;
            for (double xi : this.position) {
                current_score += xi * xi;
            }
            if (current_score < this.best_score) {
                this.best_score = current_score;
                this.best_position = new ArrayList<>(this.position);
            }
        }
    }

    public static class Swarm {
        List<Particle> particles;
        List<Double> global_best;
        double global_best_score;
        List<Double> bounds;

        public Swarm(int dimensions, int num_particles, List<Double> bounds) {
            this.particles = new ArrayList<>();
            for (int i = 0; i < num_particles; i++) {
                this.particles.add(new Particle(dimensions, null));
            }
            this.global_best = null;
            this.global_best_score = Double.MAX_VALUE;
            this.bounds = bounds;
        }

        public void update_global_best() {
            for (Particle particle : this.particles) {
                if (particle.best_score < this.global_best_score) {
                    this.global_best_score = particle.best_score;
                    this.global_best = new ArrayList<>(particle.best_position);
                }
            }
        }

        public void optimize(double[] function, int iterations) {
            for (int i = 0; i < iterations; i++) {
                update_global_best();
                for (Particle particle : this.particles) {
                    particle.update_velocity(this.global_best, 0.7, 1.5, 1.5);
                    particle.update_position(this.bounds);
                    particle.evaluate(function);
                }
            }
        }
    }

    public static double objective_function(double[] x) {
        double result = 0;
        for (double xi : x) {
            result += xi * xi;
        }
        return result;
    }

    public static void main(String[] args) {
        int dimensions = 2;
        int num_particles = 30;
        List<Double> bounds = List.of(-10.0, 10.0);
        int iterations = 100;
        Swarm swarm = new Swarm(dimensions, num_particles, bounds);
        double[] function = new double[dimensions];
        swarm.optimize(function, iterations);
        System.out.println("Global Best Position: " + swarm.global_best);
        System.out.println("Global Best Score: " + swarm.global_best_score);
    }
}