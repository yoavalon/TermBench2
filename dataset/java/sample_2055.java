import java.util.Random;

public class sample_2055 {
    static class Particle {
        double[] position;
        double[] velocity;
        double[] best_position;
        double best_score;

        Particle(int dimensions) {
            position = new double[dimensions];
            velocity = new double[dimensions];
            best_position = new double[dimensions];
            best_score = Double.POSITIVE_INFINITY;
            Random rand = new Random();
            for (int i = 0; i < dimensions; i++) {
                position[i] = rand.nextDouble() * 20 - 10;
                velocity[i] = rand.nextDouble() * 2 - 1;
                best_position[i] = position[i];
            }
        }
    }

    static class Swarm {
        Particle[] particles;
        double[] global_best_position;
        double global_best_score;

        Swarm(int num_particles, int dimensions) {
            particles = new Particle[num_particles];
            global_best_position = new double[dimensions];
            global_best_score = Double.POSITIVE_INFINITY;
            for (int i = 0; i < num_particles; i++) {
                particles[i] = new Particle(dimensions);
            }
        }

        void update_global_best() {
            for (Particle particle : particles) {
                double score = evaluate(particle.position);
                if (score < global_best_score) {
                    global_best_score = score;
                    for (int i = 0; i < particle.position.length; i++) {
                        global_best_position[i] = particle.position[i];
                    }
                }
            }
        }

        double evaluate(double[] position) {
            double sum = 0;
            for (double x : position) {
                sum += x * x;
            }
            return sum;
        }

        void update_particles(double w, double c1, double c2) {
            Random rand = new Random();
            for (Particle particle : particles) {
                for (int i = 0; i < particle.position.length; i++) {
                    double r1 = rand.nextDouble();
                    double r2 = rand.nextDouble();
                    particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (global_best_position[i] - particle.position[i]);
                    particle.position[i] += particle.velocity[i];
                    double current_score = evaluate(particle.position);
                    if (current_score < particle.best_score) {
                        particle.best_score = current_score;
                        for (int j = 0; j < particle.position.length; j++) {
                            particle.best_position[j] = particle.position[j];
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int dimensions = 30;
        int num_particles = 30;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 100;
        Swarm swarm = new Swarm(num_particles, dimensions);
        for (int i = 0; i < iterations; i++) {
            swarm.update_global_best();
            swarm.update_particles(w, c1, c2);
        }
        System.out.println("Best score: " + swarm.global_best_score);
    }
}