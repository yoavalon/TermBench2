import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2398 {

    static class Particle {
        List<Double> position;
        List<Double> velocity;
        List<Double> best_position;
        double best_fitness;

        public Particle(int dimensions, double lower_bound, double upper_bound) {
            Random random = new Random();
            position = new ArrayList<>();
            velocity = new ArrayList<>();
            best_position = new ArrayList<>();
            for (int i = 0; i < dimensions; i++) {
                position.add(random.nextDouble() * (upper_bound - lower_bound) + lower_bound);
                velocity.add(random.nextDouble() * 2 - 1);
            }
            best_position.addAll(position);
            best_fitness = Double.MAX_VALUE;
        }

        public void update_velocity(List<Double> global_best_position, double w, double c1, double c2) {
            Random random = new Random();
            for (int i = 0; i < position.size(); i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive_velocity = c1 * r1 * (best_position.get(i) - position.get(i));
                double social_velocity = c2 * r2 * (global_best_position.get(i) - position.get(i));
                velocity.set(i, w * velocity.get(i) + cognitive_velocity + social_velocity);
            }
        }

        public void update_position(double lower_bound, double upper_bound) {
            for (int i = 0; i < position.size(); i++) {
                position.set(i, position.get(i) + velocity.get(i));
                position.set(i, Math.max(lower_bound, Math.min(upper_bound, position.get(i))));
            }
        }
    }

    static class Swarm {
        List<Particle> particles;
        List<Double> global_best_position;
        double global_best_fitness;

        public Swarm(int num_particles, int dimensions, double lower_bound, double upper_bound) {
            particles = new ArrayList<>();
            Random random = new Random();
            for (int i = 0; i < num_particles; i++) {
                particles.add(new Particle(dimensions, lower_bound, upper_bound));
            }
            global_best_position = new ArrayList<>();
            for (int i = 0; i < dimensions; i++) {
                global_best_position.add(random.nextDouble() * (upper_bound - lower_bound) + lower_bound);
            }
            global_best_fitness = Double.MAX_VALUE;
        }

        public void evaluate_fitness(double[] objective_function(Particle p)) {
            for (Particle particle : particles) {
                double fitness = objective_function(particle);
                if (fitness < particle.best_fitness) {
                    particle.best_fitness = fitness;
                    particle.best_position = new ArrayList<>(particle.position);
                }
                if (fitness < global_best_fitness) {
                    global_best_fitness = fitness;
                    global_best_position = new ArrayList<>(particle.position);
                }
            }
        }

        public void update_particles(double w, double c1, double c2) {
            for (Particle particle : particles) {
                particle.update_velocity(global_best_position, w, c1, c2);
                particle.update_position(-10, 10);
            }
        }
    }

    public static double objective_function(List<Double> x) {
        double sum = 0;
        for (int i = 0; i < x.size(); i++) {
            sum += Math.sin(x.get(i)) * Math.sin(x.get(i) + (i + 1) * Math.PI / x.size());
        }
        return sum;
    }

    public static void main(String[] args) {
        int num_particles = 30;
        int dimensions = 30;
        double lower_bound = -10;
        double upper_bound = 10;
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        Swarm swarm = new Swarm(num_particles, dimensions, lower_bound, upper_bound);
        while (true) {
            swarm.evaluate_fitness(sample_2398::objective_function);
            swarm.update_particles(w, c1, c2);
        }
    }
}