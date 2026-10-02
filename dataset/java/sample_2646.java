import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_score;

    public Particle(int dimensions, double[] search_space) {
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        Random rand = new Random();
        for (int i = 0; i < dimensions; i++) {
            position[i] = rand.nextDouble() * (search_space[1] - search_space[0]) + search_space[0];
            velocity[i] = 0.0;
            best_position[i] = position[i];
        }
        best_score = Double.MAX_VALUE;
    }

    public void update_velocity(double[] global_best) {
        double inertia = 0.5;
        double cognitive_factor = 1.5;
        double social_factor = 1.5;
        Random rand = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = cognitive_factor * r1 * (best_position[i] - position[i]);
            double social = social_factor * r2 * (global_best[i] - position[i]);
            velocity[i] = inertia * velocity[i] + cognitive + social;
        }
    }

    public void move() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
        }
    }

    public void evaluate() {
        double score = objective_function();
        if (score < best_score) {
            best_score = score;
            best_position = position.clone();
        }
    }

    public double objective_function() {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }
}

class Swarm {
    int size;
    int dimensions;
    double[] search_space;
    List<Particle> particles;
    double[] best_position;
    double best_score;

    public Swarm(int size, int dimensions, double[] search_space) {
        this.size = size;
        this.dimensions = dimensions;
        this.search_space = search_space;
        particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            particles.add(new Particle(dimensions, search_space));
        }
        Random rand = new Random();
        best_position = particles.get(rand.nextInt(size)).position.clone();
        best_score = Double.MAX_VALUE;
    }

    public void update_best_position() {
        for (Particle particle : particles) {
            if (particle.best_score < best_score) {
                best_score = particle.best_score;
                best_position = particle.best_position.clone();
            }
        }
    }

    public void iterate() {
        for (Particle particle : particles) {
            particle.update_velocity(best_position);
            particle.move();
            particle.evaluate();
        }
    }

    public void run(int iterations) {
        for (int i = 0; i < iterations; i++) {
            iterate();
            update_best_position();
        }
    }
}

public class sample_2646 {
    public static void main(String[] args) {
        int swarm_size = 30;
        int dimensions = 2;
        double[] search_space = {-10, 10};
        int iterations = 100;
        Swarm swarm = new Swarm(swarm_size, dimensions, search_space);
        swarm.run(iterations);
        System.out.println("Best position: " + java.util.Arrays.toString(swarm.best_position));
        System.out.println("Best score: " + swarm.best_score);
    }
}