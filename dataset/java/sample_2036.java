import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2036 {

    static class Particle {
        List<Double> position;
        List<Double> velocity;
        List<Double> best_position;
        double best_score;

        Particle(int dimensions, double lower_bound, double upper_bound) {
            Random rand = new Random();
            this.position = new ArrayList<>();
            this.velocity = new ArrayList<>();
            this.best_position = new ArrayList<>();
            this.best_score = Double.MAX_VALUE;
            for (int i = 0; i < dimensions; i++) {
                double pos = rand.nextDouble() * (upper_bound - lower_bound) + lower_bound;
                this.position.add(pos);
                this.velocity.add(rand.nextDouble() * 2 - 1);
                this.best_position.add(pos);
            }
        }

        void update_velocity(List<Double> global_best_position, double w, double c1, double c2) {
            Random rand = new Random();
            for (int i = 0; i < position.size(); i++) {
                double r1 = rand.nextDouble();
                double r2 = rand.nextDouble();
                double new_velocity = w * velocity.get(i) + c1 * r1 * (best_position.get(i) - position.get(i)) + c2 * r2 * (global_best_position.get(i) - position.get(i));
                velocity.set(i, new_velocity);
            }
        }

        void update_position() {
            for (int i = 0; i < position.size(); i++) {
                double new_position = position.get(i) + velocity.get(i);
                position.set(i, new_position);
            }
        }

        void evaluate(double[] fitness_function) {
            double current_score = fitness_function(position);
            if (current_score < best_score) {
                best_score = current_score;
                best_position = new ArrayList<>(position);
            }
        }
    }

    static class Swarm {
        List<Particle> particles;
        List<Double> global_best_position;
        double global_best_score;

        Swarm(int size, int dimensions, double lower_bound, double upper_bound) {
            Random rand = new Random();
            this.particles = new ArrayList<>();
            this.global_best_position = new ArrayList<>();
            this.global_best_score = Double.MAX_VALUE;
            for (int i = 0; i < size; i++) {
                particles.add(new Particle(dimensions, lower_bound, upper_bound));
            }
            for (int i = 0; i < dimensions; i++) {
                global_best_position.add(rand.nextDouble() * (upper_bound - lower_bound) + lower_bound);
            }
        }

        void update_global_best() {
            for (Particle particle : particles) {
                if (particle.best_score < global_best_score) {
                    global_best_score = particle.best_score;
                    global_best_position = new ArrayList<>(particle.best_position);
                }
            }
        }

        void iterate(double[] fitness_function, double w, double c1, double c2) {
            for (Particle particle : particles) {
                particle.update_velocity(global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate(fitness_function);
            }
            update_global_best();
        }
    }

    static double fitness_function(List<Double> position) {
        double sum = 0;
        for (double x : position) {
            sum += Math.pow(x, 2);
        }
        return sum;
    }

    public static void main(String[] args) {
        int dimensions = 2;
        double lower_bound = -10;
        double upper_bound = 10;
        int swarm_size = 30;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 100;
        Swarm swarm = new Swarm(swarm_size, dimensions, lower_bound, upper_bound);
        for (int i = 0; i < iterations; i++) {
            swarm.iterate(new double[]{0}, w, c1, c2);
        }
        System.out.println("Global best score: " + swarm.global_best_score);
        System.out.println("Global best position: " + swarm.global_best_position);
    }
}