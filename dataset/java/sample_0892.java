import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0892 {
    static Random random = new Random();

    static List<List<Double>> initialize_particles(int size, int dimensions, double lower_bound, double upper_bound) {
        List<List<Double>> particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            List<Double> particle = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                particle.add(random.nextDouble() * (upper_bound - lower_bound) + lower_bound);
            }
            particles.add(particle);
        }
        return particles;
    }

    static List<Double> evaluate_fitness(List<List<Double>> particles, ObjectiveFunction objective_function) {
        List<Double> fitness = new ArrayList<>();
        for (List<Double> particle : particles) {
            fitness.add(objective_function.apply(particle));
        }
        return fitness;
    }

    static List<List<Double>> update_particles(List<List<Double>> particles, List<List<Double>> velocities, List<List<Double>> pbest, List<Double> gbest, double w, double c1, double c2) {
        List<List<Double>> new_particles = new ArrayList<>();
        for (int i = 0; i < particles.size(); i++) {
            List<Double> velocity = new ArrayList<>();
            for (int d = 0; d < particles.get(i).size(); d++) {
                velocity.add(w * velocities.get(i).get(d) + c1 * random.nextDouble() * (pbest.get(i).get(d) - particles.get(i).get(d)) + c2 * random.nextDouble() * (gbest.get(d) - particles.get(i).get(d)));
            }
            List<Double> new_position = new ArrayList<>();
            for (int d = 0; d < particles.get(i).size(); d++) {
                new_position.add(particles.get(i).get(d) + velocity.get(d));
            }
            new_particles.add(new_position);
        }
        return new_particles;
    }

    static List<Double> optimize(ObjectiveFunction objective_function, int dimensions, double[] bounds, int size, int iterations, double w, double c1, double c2) {
        List<List<Double>> particles = initialize_particles(size, dimensions, bounds[0], bounds[1]);
        List<List<Double>> velocities = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            List<Double> velocity = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                velocity.add(0.0);
            }
            velocities.add(velocity);
        }
        List<List<Double>> pbest = new ArrayList<>(particles);
        List<Double> pbest_fitness = evaluate_fitness(pbest, objective_function);
        List<Double> gbest = pbest.get(pbest_fitness.indexOf(min(pbest_fitness)));
        double gbest_fitness = min(pbest_fitness);
        for (int i = 0; i < iterations; i++) {
            particles = update_particles(particles, velocities, pbest, gbest, w, c1, c2);
            List<Double> fitness = evaluate_fitness(particles, objective_function);
            for (int j = 0; j < size; j++) {
                if (fitness.get(j) < pbest_fitness.get(j)) {
                    pbest.set(j, particles.get(j));
                    pbest_fitness.set(j, fitness.get(j));
                }
            }
            if (min(fitness) < gbest_fitness) {
                gbest = particles.get(fitness.indexOf(min(fitness)));
                gbest_fitness = min(fitness);
            }
        }
        return gbest;
    }

    static double sphere_function(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static double min(List<Double> list) {
        double min = list.get(0);
        for (double value : list) {
            if (value < min) {
                min = value;
            }
        }
        return min;
    }

    static void main() {
        int dimensions = 2;
        double[] bounds = {-10, 10};
        int size = 30;
        int iterations = 100;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        List<Double> best_solution = optimize((ObjectiveFunction) sample_0892::sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
        System.out.println("Best solution: " + best_solution);
        System.out.println("Best fitness: " + sphere_function(best_solution));
    }

    interface ObjectiveFunction {
        double apply(List<Double> x);
    }

    public static void main(String[] args) {
        main();
    }
}