import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class PSOSettings {
    int dimensions;
    int population_size;
    int max_iterations;
    double c1 = 2.0;
    double c2 = 2.0;
    double w = 0.7;

    PSOSettings(int dimensions, int population_size, int max_iterations) {
        this.dimensions = dimensions;
        this.population_size = population_size;
        this.max_iterations = max_iterations;
    }
}

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_fitness;

    Particle(int dimensions, double lower_bound, double upper_bound) {
        Random rand = new Random();
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        best_position = new ArrayList<>();
        best_fitness = Double.POSITIVE_INFINITY;

        for (int i = 0; i < dimensions; i++) {
            position.add(rand.nextDouble() * (upper_bound - lower_bound) + lower_bound);
            velocity.add(rand.nextDouble() * 2 - 1);
            best_position.add(position.get(i));
        }
    }
}

public class sample_0225 {

    static double fitness(List<Double> position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    static void updateVelocity(Particle particle, List<Double> global_best, PSOSettings settings) {
        Random rand = new Random();
        for (int i = 0; i < settings.dimensions; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = settings.c1 * r1 * (particle.best_position.get(i) - particle.position.get(i));
            double social = settings.c2 * r2 * (global_best.get(i) - particle.position.get(i));
            particle.velocity.set(i, settings.w * particle.velocity.get(i) + cognitive + social);
        }
    }

    static void updatePosition(Particle particle, PSOSettings settings) {
        for (int i = 0; i < settings.dimensions; i++) {
            particle.position.set(i, particle.position.get(i) + particle.velocity.get(i));
            if (particle.position.get(i) < -10) {
                particle.position.set(i, -10);
            } else if (particle.position.get(i) > 10) {
                particle.position.set(i, 10);
            }
        }
    }

    static List<Object> optimize(PSOSettings settings) {
        List<Particle> population = new ArrayList<>();
        for (int i = 0; i < settings.population_size; i++) {
            population.add(new Particle(settings.dimensions, -10, 10));
        }

        List<Double> global_best = new ArrayList<>();
        for (int i = 0; i < settings.dimensions; i++) {
            global_best.add(0.0);
        }
        double global_best_fitness = Double.POSITIVE_INFINITY;

        for (int iteration = 0; iteration < settings.max_iterations; iteration++) {
            for (Particle particle : population) {
                double current_fitness = fitness(particle.position);
                if (current_fitness < particle.best_fitness) {
                    particle.best_fitness = current_fitness;
                    particle.best_position = new ArrayList<>(particle.position);
                }
                if (current_fitness < global_best_fitness) {
                    global_best_fitness = current_fitness;
                    global_best = new ArrayList<>(particle.position);
                }
            }
            for (Particle particle : population) {
                updateVelocity(particle, global_best, settings);
                updatePosition(particle, settings);
            }
        }
        return List.of(global_best, global_best_fitness);
    }

    public static void main(String[] args) {
        PSOSettings settings = new PSOSettings(2, 30, 100);
        List<Object> result = optimize(settings);
        List<Double> best_position = (List<Double>) result.get(0);
        double best_fitness = (double) result.get(1);

        System.out.println("Best position: " + best_position);
        System.out.println("Best fitness: " + best_fitness);
    }
}