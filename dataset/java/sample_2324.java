import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_fitness;

    public Particle(int dim, double lb, double ub) {
        Random random = new Random();
        this.position = new ArrayList<>(dim);
        this.velocity = new ArrayList<>(dim);
        this.best_position = new ArrayList<>(dim);
        this.best_fitness = Double.MAX_VALUE;

        for (int i = 0; i < dim; i++) {
            this.position.add(random.nextDouble() * (ub - lb) + lb);
            this.velocity.add(random.nextDouble() * 2 - 1);
            this.best_position.add(this.position.get(i));
        }
    }

    public void update_velocity(List<Double> global_best, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < this.velocity.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (this.best_position.get(i) - this.position.get(i));
            double social = c2 * r2 * (global_best.get(i) - this.position.get(i));
            this.velocity.set(i, w * this.velocity.get(i) + cognitive + social);
        }
    }

    public void update_position(double lb, double ub) {
        for (int i = 0; i < this.position.size(); i++) {
            this.position.set(i, this.position.get(i) + this.velocity.get(i));
            if (this.position.get(i) < lb) {
                this.position.set(i, lb);
            }
            if (this.position.get(i) > ub) {
                this.position.set(i, ub);
            }
        }
    }
}

public class sample_2324 {

    public static double fitness_function(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    public static List<Object> optimize(int dim, double lb, double ub, int num_particles, double w, double c1, double c2, int max_iter) {
        List<Particle> particles = new ArrayList<>(num_particles);
        List<Double> global_best = new ArrayList<>(dim);
        double global_best_fitness = Double.MAX_VALUE;

        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(dim, lb, ub));
        }

        for (int i = 0; i < dim; i++) {
            global_best.add(Double.MAX_VALUE);
        }

        for (int i = 0; i < max_iter; i++) {
            for (Particle particle : particles) {
                double current_fitness = fitness_function(particle.position);
                if (current_fitness < particle.best_fitness) {
                    particle.best_fitness = current_fitness;
                    particle.best_position = new ArrayList<>(particle.position);
                }
                if (current_fitness < global_best_fitness) {
                    global_best_fitness = current_fitness;
                    global_best = new ArrayList<>(particle.position);
                }
            }
            for (Particle particle : particles) {
                particle.update_velocity(global_best, w, c1, c2);
                particle.update_position(lb, ub);
            }
        }
        return List.of(global_best, global_best_fitness);
    }

    public static void main(String[] args) {
        int dim = 30;
        double lb = -100, ub = 100;
        int num_particles = 50;
        double w = 0.7, c1 = 1.5, c2 = 1.5;
        int max_iter = 10000;
        List<Object> result = optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter);
        List<Double> best_position = (List<Double>) result.get(0);
        double best_fitness = (double) result.get(1);
        System.out.println("Best position: " + best_position);
        System.out.println("Best fitness: " + best_fitness);
    }
}