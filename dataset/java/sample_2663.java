import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Swarm {

    int size;
    int dimensions;
    List<Particle> particles;
    Particle global_best;

    Swarm(int size, int dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            particles.add(new Particle(dimensions));
        }
        this.global_best = null;
    }

    void update_global_best() {
        for (Particle particle : particles) {
            if (global_best == null || particle.best_score < global_best.best_score) {
                global_best = particle;
            }
        }
    }

    void update_particles() {
        for (Particle particle : particles) {
            particle.update_velocity(global_best);
            particle.update_position();
        }
    }
}

class Particle {

    double[] position;
    double[] velocity;
    double[] best_position;
    double best_score;

    Particle(int dimensions) {
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        Random random = new Random();
        for (int i = 0; i < dimensions; i++) {
            position[i] = random.nextDouble() * 20 - 10;
            velocity[i] = random.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
        best_score = Double.POSITIVE_INFINITY;
    }

    void update_velocity(Particle global_best) {
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        Random random = new Random();
        for (int i = 0; i < velocity.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best.best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(-10, Math.min(10, position[i]));
        }
    }

    void evaluate(double[] objective_function) {
        best_score = calculate_objective_function(position);
        if (best_score < best_score) {
            for (int i = 0; i < position.length; i++) {
                best_position[i] = position[i];
            }
        }
    }

    double calculate_objective_function(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }
}

public class sample_2663 {

    public static void main(String[] args) {
        int swarm_size = 30;
        int dimensions = 2;
        Swarm swarm = new Swarm(swarm_size, dimensions);
        for (int i = 0; i < 100; i++) {
            swarm.update_global_best();
            for (Particle particle : swarm.particles) {
                particle.evaluate(particle.position);
            }
            swarm.update_particles();
        }
        System.out.println(swarm.global_best.best_score + " " + String.join(" ", swarm.global_best.best_position));
    }
}