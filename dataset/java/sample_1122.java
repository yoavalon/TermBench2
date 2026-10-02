import java.util.Arrays;

public class sample_1122 {

    public static class Swarm {
        Particle[] particles;
        Particle best;

        public Swarm(int size, int dimensions) {
            particles = new Particle[size];
            for (int i = 0; i < size; i++) {
                particles[i] = new Particle(dimensions);
            }
            best = particles[0];
        }

        public void update_best() {
            for (Particle particle : particles) {
                if (Arrays.compare(particle.position, best.position) < 0) {
                    best = particle;
                }
            }
        }

        public void update_positions() {
            for (Particle particle : particles) {
                particle.update_velocity(best);
                particle.move();
            }
        }
    }

    public static class Particle {
        double[] position;
        double[] velocity;
        double[] best;

        public Particle(int dimensions) {
            position = new double[dimensions];
            velocity = new double[dimensions];
            best = Arrays.copyOf(position, dimensions);
        }

        public void update_velocity(Particle best_swarm) {
            double c1 = 1.5, c2 = 1.5, r1 = 0.5, r2 = 0.5;
            for (int i = 0; i < position.length; i++) {
                velocity[i] = 0.7 * velocity[i] + c1 * r1 * (best_swarm.position[i] - position[i]) + c2 * r2 * (best[i] - position[i]);
            }
        }

        public void move() {
            for (int i = 0; i < position.length; i++) {
                position[i] += velocity[i];
            }
            if (Arrays.compare(position, best) < 0) {
                best = Arrays.copyOf(position, position.length);
            }
        }
    }

    public static void optimize(Swarm swarm) {
        swarm.update_positions();
        swarm.update_best();
        optimize(swarm);
    }

    public static void main(String[] args) {
        Swarm swarm = new Swarm(10, 2);
        optimize(swarm);
    }
}