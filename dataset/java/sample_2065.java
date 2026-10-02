import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_score;

    public Particle(int dimensions) {
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        best_position = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < dimensions; i++) {
            position.add(random.nextDouble() * 20 - 10);
            velocity.add(random.nextDouble() * 2 - 1);
            best_position.add(position.get(i));
        }
        best_score = Double.MAX_VALUE;
    }

    public void update_velocity(List<Double> global_best_position, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < velocity.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position.get(i) - position.get(i));
            double social = c2 * r2 * (global_best_position.get(i) - position.get(i));
            velocity.set(i, w * velocity.get(i) + cognitive + social);
        }
    }

    public void update_position() {
        for (int i = 0; i < position.size(); i++) {
            position.set(i, position.get(i) + velocity.get(i));
            if (position.get(i) < -10) {
                position.set(i, -10);
            } else if (position.get(i) > 10) {
                position.set(i, 10);
            }
        }
    }

    public void evaluate(double[] objective_function) {
        double score = 0;
        for (double xi : position) {
            score += xi * xi;
        }
        if (score < best_score) {
            best_score = score;
            best_position.clear();
            best_position.addAll(position);
        }
    }
}

class Swarm {
    List<Particle> particles;
    List<Double> global_best_position;
    double global_best_score;

    public Swarm(int num_particles, int dimensions) {
        particles = new ArrayList<>();
        global_best_position = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < dimensions; i++) {
            global_best_position.add(random.nextDouble() * 20 - 10);
        }
        global_best_score = Double.MAX_VALUE;
        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(dimensions));
        }
    }

    public void update_global_best() {
        for (Particle particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best_position.clear();
                global_best_position.addAll(particle.best_position);
            }
        }
    }

    public void optimize(double[] objective_function, double w, double c1, double c2, int iterations) {
        for (int _ = 0; _ < iterations; _++) {
            for (Particle particle : particles) {
                particle.update_velocity(global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate(objective_function);
            }
            update_global_best();
        }
    }
}

public class sample_2065 {
    public static void main(String[] args) {
        int dimensions = 3;
        int num_particles = 10;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 50;
        Swarm swarm = new Swarm(num_particles, dimensions);
        swarm.optimize(new double[dimensions], w, c1, c2, iterations);
        System.out.println("Best position: " + swarm.global_best_position);
        System.out.println("Best score: " + swarm.global_best_score);
    }
}