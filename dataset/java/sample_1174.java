import java.util.Arrays;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_score;

    Particle(int dimensions) {
        this.position = new double[dimensions];
        this.velocity = new double[dimensions];
        this.best_position = new double[dimensions];
        this.best_score = Double.POSITIVE_INFINITY;
    }

    void update_velocity(double[] global_best, double w, double c1, double c2) {
        for (int i = 0; i < position.length; i++) {
            double r1 = 0.5;
            double r2 = 0.5;
            double cognitive = c1 * r1 * (best_position[i] - position[i]);
            double social = c2 * r2 * (global_best[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void update_position(double[][] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(bounds[i][0], Math.min(position[i], bounds[i][1]));
        }
    }

    void evaluate(double[] score_function) {
        best_score = score_function(position);
        if (best_score < score_function(best_position)) {
            best_position = position.clone();
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] global_best;
    double global_best_score;
    double[][] bounds;
    double w;
    double c1;
    double c2;

    Swarm(int dimensions, int num_particles, double[][] bounds, double w, double c1, double c2) {
        this.particles = new Particle[num_particles];
        for (int i = 0; i < num_particles; i++) {
            particles[i] = new Particle(dimensions);
        }
        this.global_best = new double[dimensions];
        this.global_best_score = Double.POSITIVE_INFINITY;
        this.bounds = bounds;
        this.w = w;
        this.c1 = c1;
        this.c2 = c2;
    }

    void update_global_best() {
        for (Particle particle : particles) {
            if (particle.best_score < global_best_score) {
                global_best_score = particle.best_score;
                global_best = particle.best_position.clone();
            }
        }
    }

    void iterate(double[] score_function) {
        for (Particle particle : particles) {
            particle.update_velocity(global_best, w, c1, c2);
            particle.update_position(bounds);
            particle.evaluate(score_function);
        }
        update_global_best();
    }
}

public class sample_1174 {
    public static void main(String[] args) {
        int dimensions = 2;
        int num_particles = 10;
        double[][] bounds = { {-10, 10}, {-10, 10} };
        double w = 0.7;
        double c1 = 2.0;
        double c2 = 2.0;

        double[] score_function = (position) -> {
            double sum = 0;
            for (double x : position) {
                sum += x * x;
            }
            return sum;
        };

        Swarm swarm = new Swarm(dimensions, num_particles, bounds, w, c1, c2);
        while (true) {
            swarm.iterate(score_function);
        }
    }
}