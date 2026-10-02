import java.util.ArrayList;
import java.util.List;

public class sample_0825 {

    public static class Swarm {
        List<Particle> particles;
        Particle best_position;

        public Swarm(int size, int dimensions) {
            this.particles = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.particles.add(new Particle(dimensions));
            }
            this.best_position = null;
        }

        public void update_best_position() {
            if (this.best_position == null) {
                this.best_position = this.particles.get(0);
            } else {
                for (Particle particle : this.particles) {
                    if (particle.fitness > this.best_position.fitness) {
                        this.best_position = particle;
                    }
                }
            }
        }

        public void update_particles(int iterations) {
            if (iterations > 0) {
                for (Particle particle : this.particles) {
                    particle.update_velocity(this.best_position.position);
                    particle.update_position();
                }
                this.update_best_position();
                this.update_particles(iterations - 1);
            }
        }
    }

    public static class Particle {
        double[] position;
        double[] velocity;
        double fitness;

        public Particle(int dimensions) {
            this.position = new double[dimensions];
            this.velocity = new double[dimensions];
            this.fitness = 0.0;
        }

        public void update_velocity(double[] best_position) {
            double w = 0.7, c1 = 1.5, c2 = 1.5;
            for (int i = 0; i < this.position.length; i++) {
                double r1 = 0.5, r2 = 0.5;
                double cognitive = c1 * r1 * (best_position[i] - this.position[i]);
                double social = c2 * r2 * (this.best_position.position[i] - this.position[i]);
                this.velocity[i] = w * this.velocity[i] + cognitive + social;
            }
        }

        public void update_position() {
            for (int i = 0; i < this.position.length; i++) {
                this.position[i] += this.velocity[i];
            }
            this.fitness = this.calculate_fitness();
        }

        public double calculate_fitness() {
            double sum = 0.0;
            for (double x : this.position) {
                sum += Math.pow(x, 2);
            }
            return sum;
        }
    }

    public static void optimize(Swarm swarm, int iterations) {
        swarm.update_particles(iterations);
    }

    public static void main(String[] args) {
        int dimensions = 2;
        int swarm_size = 10;
        int iterations = 50;
        Swarm swarm = new Swarm(swarm_size, dimensions);
        optimize(swarm, iterations);
    }
}