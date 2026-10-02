import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_score;

    public Particle(int dimensions, double[][] bounds, Random random) {
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        best_score = Double.POSITIVE_INFINITY;

        for (int i = 0; i < dimensions; i++) {
            position[i] = random.nextDouble() * (bounds[i][1] - bounds[i][0]) + bounds[i][0];
            velocity[i] = random.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
    }

    public void update_velocity(double[] global_best, double w, double c1, double c2, Random random) {
        for (int i = 0; i < velocity.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    public void update_position(double[][] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], position[i]));
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] best_position;
    double best_score;
    double[][] bounds;
    int dimensions;
    Random random;

    public Swarm(int num_particles, int dimensions, double[][] bounds, double[][] bounds2, Random random) {
        this.random = random;
        this.dimensions = dimensions;
        this.bounds = bounds;
        particles = new Particle[num_particles];
        best_position = new double[dimensions];
        best_score = Double.POSITIVE_INFINITY;

        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dimensions, bounds2, random);
        }
    }

    public void optimize(int max_iterations, double w, double c1, double c2) {
        for (int iter = 0; iter < max_iterations; iter++) {
            for (Particle particle : particles) {
                double score = objective_function(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_position = particle.position.clone();
                }
                if (score < best_score) {
                    best_score = score;
                    best_position = particle.position.clone();
                }
            }
            for (Particle particle : particles) {
                particle.update_velocity(best_position, w, c1, c2, random);
                particle.update_position(bounds);
            }
        }
    }
}

public class sample_0856 {
    public static void main(String[] args) {
        Random random = new Random();
        int dimensions = 3;
        double[][] bounds = { {-10, 10}, {-10, 10}, {-10, 10} };
        int num_particles = 20;
        int max_iterations = 100;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;

        Swarm swarm = new Swarm(num_particles, dimensions, bounds, bounds, random);
        swarm.optimize(max_iterations, w, c1, c2);
        System.out.println(java.util.Arrays.toString(swarm.best_position) + " " + swarm.best_score);
    }

    public static double objective_function(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += Math.pow(xi - 2, 2);
        }
        return sum;
    }
}