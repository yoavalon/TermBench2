import java.util.Random;

public class sample_2067 {

    static class Particle {
        double[] position;
        double[] velocity;
        double[] best_pos;
        double best_score;

        Particle(int dim) {
            position = new double[dim];
            velocity = new double[dim];
            best_pos = new double[dim];
            best_score = Double.POSITIVE_INFINITY;
        }

        void update_velocity(double[] global_best, double w, double c1, double c2) {
            Random random = new Random();
            for (int i = 0; i < position.length; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                velocity[i] = w * velocity[i] + c1 * r1 * (best_pos[i] - position[i]) + c2 * r2 * (global_best[i] - position[i]);
            }
        }

        void update_position(double[][] bounds) {
            for (int i = 0; i < position.length; i++) {
                position[i] += velocity[i];
                position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], position[i]));
            }
        }
    }

    static class Swarm {
        Particle[] particles;
        double[] best_global_pos;
        double best_global_score;

        Swarm(int num_particles, int dim, double[][] bounds) {
            particles = new Particle[num_particles];
            for (int i = 0; i < num_particles; i++) {
                particles[i] = new Particle(dim);
            }
            best_global_pos = new double[dim];
            best_global_score = Double.POSITIVE_INFINITY;
        }

        void update_global_best() {
            for (Particle particle : particles) {
                if (particle.best_score < best_global_score) {
                    best_global_score = particle.best_score;
                    for (int i = 0; i < best_global_pos.length; i++) {
                        best_global_pos[i] = particle.best_pos[i];
                    }
                }
            }
        }

        void optimize(double[][] bounds, int max_iter, double w, double c1, double c2) {
            for (int iter = 0; iter < max_iter; iter++) {
                for (Particle particle : particles) {
                    particle.update_velocity(best_global_pos, w, c1, c2);
                    particle.update_position(bounds);
                    double score = fitness_function(particle.position);
                    if (score < particle.best_score) {
                        particle.best_score = score;
                        for (int i = 0; i < particle.position.length; i++) {
                            particle.best_pos[i] = particle.position[i];
                        }
                    }
                }
                update_global_best();
            }
        }
    }

    static double fitness_function(double[] position) {
        double sum = 0.0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    public static void main(String[] args) {
        int num_particles = 30;
        int dim = 2;
        double[][] bounds = {{0.0, 0.0}, {10.0, 10.0}};
        int max_iter = 100;
        double w = 0.7;
        double c1 = 2.0;
        double c2 = 2.0;
        Swarm swarm = new Swarm(num_particles, dim, bounds);
        swarm.optimize(bounds, max_iter, w, c1, c2);
        System.out.println(java.util.Arrays.toString(swarm.best_global_pos) + " " + swarm.best_global_score);
    }
}