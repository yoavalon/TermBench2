import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_score;

    Particle(int dimensions) {
        Random rand = new Random();
        position = new double[dimensions];
        velocity = new double[dimensions];
        best_position = new double[dimensions];
        best_score = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            position[i] = rand.nextDouble() * 20 - 10;
            velocity[i] = rand.nextDouble() * 2 - 1;
            best_position[i] = position[i];
        }
    }

    void update_velocity(double[] global_best_position, double w, double c1, double c2) {
        Random rand = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best_position[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
        }
    }

    double evaluate() {
        best_score = fitness_function(position);
        return best_score;
    }
}

class Swarm {
    Particle[] particles;
    double[] global_best_position;
    double global_best_score;

    Swarm(int num_particles, int dimensions) {
        particles = new Particle[num_particles];
        Random rand = new Random();
        global_best_position = new double[dimensions];
        global_best_score = Double.POSITIVE_INFINITY;
        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dimensions);
        }
        for (int i = 0; i < dimensions; i++) {
            global_best_position[i] = rand.nextDouble() * 20 - 10;
        }
    }

    void update_global_best() {
        for (Particle particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                for (int i = 0; i < global_best_position.length; i++) {
                    global_best_position[i] = particle.best_position[i];
                }
            }
        }
    }
}

class sample_0864 {
    static double fitness_function(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static double[] optimize(Swarm swarm, double w, double c1, double c2, int iterations) {
        for (int i = 0; i < iterations; i++) {
            for (Particle particle : swarm.particles) {
                particle.update_velocity(swarm.global_best_position, w, c1, c2);
                particle.update_position();
                particle.evaluate();
            }
            swarm.update_global_best();
        }
        return new double[]{swarm.global_best_position, swarm.global_best_score};
    }

    public static void main(String[] args) {
        int dimensions = 10;
        int num_particles = 20;
        double w = 0.7;
        double c1 = 2.0;
        double c2 = 2.0;
        int iterations = 100;
        Swarm swarm = new Swarm(num_particles, dimensions);
        double[] best_position = optimize(swarm, w, c1, c2, iterations);
        System.out.println("Best position: " + best_position[0]);
        System.out.println("Best score: " + best_position[1]);
    }
}