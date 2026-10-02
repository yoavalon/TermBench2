public class sample_1169 {

    static class Swarm {
        Particle[] particles;
        Particle gbest;

        Swarm(int size, int dimensions) {
            this.particles = new Particle[size];
            for (int i = 0; i < size; i++) {
                this.particles[i] = new Particle(dimensions);
            }
            this.gbest = this.particles[0];
        }

        void update_gbest() {
            for (Particle particle : this.particles) {
                if (particle.fitness < this.gbest.fitness) {
                    this.gbest = particle;
                }
            }
        }

        void optimize() {
            while (true) {
                for (Particle particle : this.particles) {
                    particle.update_velocity(this.gbest);
                    particle.update_position();
                }
                this.update_gbest();
            }
        }
    }

    static class Particle {
        double[] position;
        double[] velocity;
        double[] best_position;
        double fitness;

        Particle(int dimensions) {
            this.position = new double[dimensions];
            this.velocity = new double[dimensions];
            this.best_position = new double[dimensions];
            for (int i = 0; i < dimensions; i++) {
                this.position[i] = 0.0;
                this.velocity[i] = 0.0;
                this.best_position[i] = this.position[i];
            }
            this.fitness = Double.POSITIVE_INFINITY;
        }

        void update_velocity(Particle gbest) {
            double r1 = 0.5;
            double r2 = 0.5;
            double inertia = 0.7;
            for (int i = 0; i < this.position.length; i++) {
                this.velocity[i] = inertia * this.velocity[i] + r1 * (this.best_position[i] - this.position[i]) + r2 * (gbest.position[i] - this.position[i]);
            }
        }

        void update_position() {
            for (int i = 0; i < this.position.length; i++) {
                this.position[i] += this.velocity[i];
                if (this.fitness > this.calculate_fitness()) {
                    for (int j = 0; j < this.position.length; j++) {
                        this.best_position[j] = this.position[j];
                    }
                    this.fitness = this.calculate_fitness();
                }
            }
        }

        double calculate_fitness() {
            double sum = 0.0;
            for (double x : this.position) {
                sum += x * x;
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        Swarm swarm = new Swarm(10, 2);
        swarm.optimize();
    }
}