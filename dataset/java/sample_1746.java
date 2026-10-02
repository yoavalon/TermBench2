import java.util.Random;
import java.util.Arrays;

class Particle {
    double[] position;
    double[] velocity;
    double[] bestPosition;
    double bestScore;

    Particle(int dimensions) {
        Random rand = new Random();
        position = new double[dimensions];
        velocity = new double[dimensions];
        bestPosition = new double[dimensions];
        for (int i = 0; i < dimensions; i++) {
            position[i] = rand.nextDouble() * 20 - 10;
            velocity[i] = rand.nextDouble() * 2 - 1;
        }
        bestPosition = Arrays.copyOf(position, position.length);
        bestScore = Double.POSITIVE_INFINITY;
    }

    void updateVelocity(double[] globalBestPosition, double w, double c1, double c2) {
        Random rand = new Random();
        for (int i = 0; i < velocity.length; i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double cognitive = c1 * r1 * (bestPosition[i] - position[i]);
            double social = c2 * r2 * (globalBestPosition[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    void updatePosition() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
        }
    }

    void evaluate(double[] costFunction) {
        double score = 0;
        for (double x : position) {
            score += x * x;
        }
        if (score < bestScore) {
            bestScore = score;
            bestPosition = Arrays.copyOf(position, position.length);
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] globalBestPosition;
    double globalBestScore;

    Swarm(int size, int dimensions) {
        particles = new Particle[size];
        for (int i = 0; i < size; i++) {
            particles[i] = new Particle(dimensions);
        }
        globalBestPosition = null;
        globalBestScore = Double.POSITIVE_INFINITY;
    }

    void updateGlobalBest() {
        for (Particle particle : particles) {
            if (particle.bestScore < globalBestScore) {
                globalBestScore = particle.bestScore;
                globalBestPosition = Arrays.copyOf(particle.bestPosition, particle.bestPosition.length);
            }
        }
    }

    void updateSwarm() {
        for (Particle particle : particles) {
            particle.updateVelocity(globalBestPosition, 0.7, 1.5, 1.5);
            particle.updatePosition();
        }
    }
}

public class sample_1746 {
    public static void main(String[] args) {
        int dimensions = 10;
        int swarmSize = 20;
        Swarm swarm = new Swarm(swarmSize, dimensions);
        while (true) {
            for (Particle particle : swarm.particles) {
                particle.evaluate(particle.position);
            }
            swarm.updateGlobalBest();
            swarm.updateSwarm();
        }
    }
}