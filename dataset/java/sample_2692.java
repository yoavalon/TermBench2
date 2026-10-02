public class sample_2692 {
    static class Particle {
        double[] position;
        double[] velocity;
        double[] pbest;
        double pbest_value;

        Particle(int dim) {
            position = new double[dim];
            velocity = new double[dim];
            pbest = new double[dim];
            pbest_value = Double.POSITIVE_INFINITY;
        }

        void update_velocity(double[] gbest, double w, double c1, double c2) {
            for (int i = 0; i < position.length; i++) {
                double r1 = 0.5, r2 = 0.5;
                velocity[i] = w * velocity[i] + c1 * r1 * (pbest[i] - position[i]) + c2 * r2 * (gbest[i] - position[i]);
            }
        }

        void update_position(double[][] bounds) {
            for (int i = 0; i < position.length; i++) {
                position[i] += velocity[i];
                position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], position[i]));
            }
        }

        void update_pbest(double value) {
            if (value < pbest_value) {
                pbest = position.clone();
                pbest_value = value;
            }
        }
    }

    static class Swarm {
        Particle[] particles;
        double[] gbest;
        double gbest_value;
        double[][] bounds;

        Swarm(int num_particles, int dim, double[][] bounds) {
            particles = new Particle[num_particles];
            for (int i = 0; i < num_particles; i++) {
                particles[i] = new Particle(dim);
            }
            gbest = new double[dim];
            gbest_value = Double.POSITIVE_INFINITY;
            this.bounds = bounds;
        }

        void update_gbest() {
            for (Particle particle : particles) {
                if (particle.pbest_value < gbest_value) {
                    gbest = particle.pbest.clone();
                    gbest_value = particle.pbest_value;
                }
            }
        }

        void iterate() {
            for (Particle particle : particles) {
                particle.update_velocity(gbest, 0.7, 1.5, 1.5);
                particle.update_position(bounds);
                particle.update_pbest(objective_function(particle.position));
            }
        }
    }

    static double objective_function(double[] x) {
        double sum = 0.0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static double[] optimize(int num_particles, int dim, int max_iterations, double[][] bounds) {
        Swarm swarm = new Swarm(num_particles, dim, bounds);
        for (int i = 0; i < max_iterations; i++) {
            swarm.iterate();
            swarm.update_gbest();
        }
        return new double[]{swarm.gbest_value};
    }

    public static void main(String[] args) {
        int num_particles = 30;
        int dim = 2;
        int max_iterations = 100;
        double[][] bounds = new double[dim][2];
        for (int i = 0; i < dim; i++) {
            bounds[i][0] = -10;
            bounds[i][1] = 10;
        }
        double[] result = optimize(num_particles, dim, max_iterations, bounds);
        System.out.println('Best position: ' + result[0]);
        System.out.println('Best value: ' + result[1]);
    }
}