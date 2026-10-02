import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_value;

    Particle(int dimensions) {
        Random random = new Random();
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        best_position = new ArrayList<>();
        for (int i = 0; i < dimensions; i++) {
            position.add(random.nextDouble() * 2 - 1);
            velocity.add(random.nextDouble() * 2 - 1);
            best_position.add(position.get(i));
        }
        best_value = Double.POSITIVE_INFINITY;
    }

    void update_velocity(List<Double> global_best, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < position.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position.get(i) - position.get(i));
            double social = c2 * r2 * (global_best.get(i) - position.get(i));
            velocity.set(i, w * velocity.get(i) + cognitive + social);
        }
    }

    void update_position() {
        for (int i = 0; i < position.size(); i++) {
            position.set(i, position.get(i) + velocity.get(i));
        }
    }

    void evaluate(ObjectiveFunction objective_function) {
        best_value = objective_function.evaluate(position);
        if (best_value < best_value) {
            best_position = new ArrayList<>(position);
        }
    }
}

class Swarm {
    List<Particle> particles;
    List<Double> global_best;
    double global_best_value;

    Swarm(int dimensions, int num_particles) {
        particles = new ArrayList<>();
        global_best = new ArrayList<>();
        for (int i = 0; i < dimensions; i++) {
            global_best.add(Double.POSITIVE_INFINITY);
        }
        global_best_value = Double.POSITIVE_INFINITY;
        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(dimensions));
        }
    }

    void update_global_best() {
        for (Particle particle : particles) {
            if (particle.best_value < global_best_value) {
                global_best_value = particle.best_value;
                global_best = new ArrayList<>(particle.best_position);
            }
        }
    }

    void iterate(ObjectiveFunction objective_function) {
        for (Particle particle : particles) {
            particle.update_velocity(global_best, 0.7, 1.5, 1.5);
            particle.update_position();
            particle.evaluate(objective_function);
        }
        update_global_best();
    }
}

interface ObjectiveFunction {
    double evaluate(List<Double> x);
}

class ObjectiveFunctionImpl implements ObjectiveFunction {
    public double evaluate(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }
}

public class sample_2054 {
    public static void main(String[] args) {
        int dimensions = 10;
        int num_particles = 20;
        int max_iterations = 100;
        List<Double> best_solution = optimize(dimensions, num_particles, max_iterations);
        System.out.println("Best solution: " + best_solution);
    }

    public static List<Double> optimize(int dimensions, int num_particles, int max_iterations) {
        Swarm swarm = new Swarm(dimensions, num_particles);
        ObjectiveFunction objective_function = new ObjectiveFunctionImpl();
        for (int i = 0; i < max_iterations; i++) {
            swarm.iterate(objective_function);
        }
        return swarm.global_best;
    }
}