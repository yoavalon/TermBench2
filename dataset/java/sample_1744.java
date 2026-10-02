public class sample_1744 {

    public static void main(String[] args) {
        int dimensions = 5;
        int swarm_size = 10;
        Swarm swarm = new Swarm(swarm_size, dimensions);
        double[] global_best = new double[dimensions];
        while (true) {
            for (Particle particle : swarm.particles) {
                if (objective_function(particle.position) < objective_function(global_best)) {
                    global_best = particle.position.clone();
                }
            }
            swarm.update(global_best);
        }
    }

    public static double objective_function(double[] x) {
        double sum = 0.0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static class Swarm {
        int size;
        int dimensions;
        Particle[] particles;

        Swarm(int size, int dimensions) {
            this.size = size;
            this.dimensions = dimensions;
            this.particles = new Particle[size];
            for (int i = 0; i < size; i++) {
                particles[i] = new Particle(dimensions);
            }
        }

        void update(double[] global_best) {
            for (Particle particle : particles) {
                particle.update(global_best);
            }
        }
    }

    static class Particle {
        double[] position;
        double[] velocity;
        double[] best_position;

        Particle(int dimensions) {
            this.position = new double[dimensions];
            this.velocity = new double[dimensions];
            this.best_position = position.clone();
        }

        void update(double[] global_best) {
            double w = 0.7;
            double c1 = 1.5;
            double c2 = 1.5;
            for (int i = 0; i < position.length; i++) {
                double r1 = 0.6;
                double r2 = 0.3;
                double velocity_component_1 = w * velocity[i];
                double velocity_component_2 = c1 * r1 * (best_position[i] - position[i]);
                double velocity_component_3 = c2 * r2 * (global_best[i] - position[i]);
                velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3;
                position[i] += velocity[i];
                if (position[i] < -10 || position[i] > 10) {
                    position[i] = best_position[i];
                }
            }
        }
    }
}