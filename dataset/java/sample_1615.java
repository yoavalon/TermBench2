import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1615 {
    public static void main(String[] args) {
        int dimensions = 2;
        int populationSize = 10;
        List<Particle> particles = initializeParticles(dimensions, populationSize);
        Particle globalBest = findGlobalBest(particles);
        while (true) {
            updateParticles(particles, globalBest);
            globalBest = findGlobalBest(particles);
        }
    }

    private static List<Particle> initializeParticles(int dimensions, int populationSize) {
        List<Particle> particles = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < populationSize; i++) {
            double[] position = new double[dimensions];
            for (int j = 0; j < dimensions; j++) {
                position[j] = random.nextDouble() * 20 - 10;
            }
            double[] velocity = new double[dimensions];
            double[] bestPosition = position.clone();
            particles.add(new Particle(position, velocity, bestPosition));
        }
        return particles;
    }

    private static void updateParticles(List<Particle> particles, Particle globalBest) {
        Random random = new Random();
        for (Particle particle : particles) {
            for (int i = 0; i < particle.position.length; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitiveVelocity = r1 * (particle.bestPosition[i] - particle.position[i]);
                double socialVelocity = r2 * (globalBest.position[i] - particle.position[i]);
                particle.velocity[i] = 0.7 * particle.velocity[i] + cognitiveVelocity + socialVelocity;
                particle.position[i] += particle.velocity[i];
            }
            if (evaluate(particle.position) < evaluate(particle.bestPosition)) {
                particle.bestPosition = particle.position.clone();
            }
        }
    }

    private static double evaluate(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    private static Particle findGlobalBest(List<Particle> particles) {
        Particle globalBest = particles.get(0);
        for (Particle particle : particles) {
            if (evaluate(particle.position) < evaluate(globalBest.position)) {
                globalBest = particle;
            }
        }
        return globalBest;
    }

    static class Particle {
        double[] position;
        double[] velocity;
        double[] bestPosition;

        Particle(double[] position, double[] velocity, double[] bestPosition) {
            this.position = position;
            this.velocity = velocity;
            this.bestPosition = bestPosition;
        }
    }
}