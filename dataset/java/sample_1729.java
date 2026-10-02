import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1729 {

    static class Swarm {
        List<Particle> particles;
        Particle best;

        Swarm(int size) {
            particles = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                particles.add(new Particle());
            }
            best = findBestParticle();
        }

        void update() {
            for (Particle particle : particles) {
                particle.updateVelocity(best);
                particle.move();
            }
            best = findBestParticle();
        }

        Particle findBestParticle() {
            Particle best = particles.get(0);
            for (Particle particle : particles) {
                if (particle.evaluate() < best.evaluate()) {
                    best = particle;
                }
            }
            return best;
        }
    }

    static class Particle {
        double[] position;
        double[] velocity;
        double[] best;

        Particle() {
            position = new double[]{random.nextDouble() * 2 - 1, random.nextDouble() * 2 - 1};
            velocity = new double[]{random.nextDouble() * 0.2 - 0.1, random.nextDouble() * 0.2 - 0.1};
            best = position.clone();
        }

        double evaluate() {
            return -(position[0] * position[0] + position[1] * position[1]);
        }

        void updateVelocity(Particle globalBest) {
            double inertia = 0.7;
            double cognitive = 1.5;
            double social = 1.5;
            for (int i = 0; i < velocity.length; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitiveComponent = cognitive * r1 * (best[i] - position[i]);
                double socialComponent = social * r2 * (globalBest.position[i] - position[i]);
                velocity[i] = inertia * velocity[i] + cognitiveComponent + socialComponent;
            }
        }

        void move() {
            for (int i = 0; i < position.length; i++) {
                position[i] += velocity[i];
                position[i] = Math.max(-1, Math.min(1, position[i]));
            }
            if (evaluate() < best[0]) {
                best = position.clone();
            }
        }
    }

    static Random random = new Random();

    public static void run() {
        int swarmSize = 30;
        Swarm swarm = new Swarm(swarmSize);
        while (true) {
            swarm.update();
        }
    }

    public static void main(String[] args) {
        run();
    }
}