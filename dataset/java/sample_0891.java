import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    private List<Double> position;
    private List<Double> velocity;
    private List<Double> bestPosition;
    private double bestFitness;

    public Particle(int dimensions) {
        position = new ArrayList<>(dimensions);
        velocity = new ArrayList<>(dimensions);
        bestPosition = new ArrayList<>(dimensions);
        Random random = new Random();
        for (int i = 0; i < dimensions; i++) {
            position.add(random.nextDouble() * 20 - 10);
            velocity.add(random.nextDouble() * 2 - 1);
        }
        bestPosition.addAll(position);
        bestFitness = Double.MAX_VALUE;
    }

    public void updateVelocity(List<Double> globalBest, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < velocity.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (bestPosition.get(i) - position.get(i));
            double social = c2 * r2 * (globalBest.get(i) - position.get(i));
            velocity.set(i, w * velocity.get(i) + cognitive + social);
        }
    }

    public void updatePosition() {
        for (int i = 0; i < position.size(); i++) {
            position.set(i, position.get(i) + velocity.get(i));
        }
    }

    public void evaluateFitness(Function<List<Double>, Double> fitnessFunction) {
        bestFitness = fitnessFunction.apply(position);
        if (bestFitness < fitnessFunction.apply(bestPosition)) {
            bestPosition.clear();
            bestPosition.addAll(position);
        }
    }
}

class Swarm {
    private List<Particle> particles;
    private List<Double> globalBestPosition;
    private double globalBestFitness;

    public Swarm(int dimensions, int numParticles) {
        particles = new ArrayList<>(numParticles);
        for (int i = 0; i < numParticles; i++) {
            particles.add(new Particle(dimensions));
        }
        globalBestPosition = null;
        globalBestFitness = Double.MAX_VALUE;
    }

    public void updateGlobalBest(Function<List<Double>, Double> fitnessFunction) {
        for (Particle particle : particles) {
            particle.evaluateFitness(fitnessFunction);
            if (particle.bestFitness < globalBestFitness) {
                globalBestFitness = particle.bestFitness;
                globalBestPosition = new ArrayList<>(particle.bestPosition);
            }
        }
    }

    public void optimize(Function<List<Double>, Double> fitnessFunction, double w, double c1, double c2, int iterations) {
        for (int i = 0; i < iterations; i++) {
            updateGlobalBest(fitnessFunction);
            for (Particle particle : particles) {
                particle.updateVelocity(globalBestPosition, w, c1, c2);
                particle.updatePosition();
            }
        }
    }
}

@FunctionalInterface
interface Function<T, R> {
    R apply(T t);
}

public class sample_0891 {
    public static double sphereFunction(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    public static void main(String[] args) {
        int dimensions = 3;
        int numParticles = 10;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 100;
        Swarm swarm = new Swarm(dimensions, numParticles);
        swarm.optimize(sample_0891::sphereFunction, w, c1, c2, iterations);
        System.out.println("Global Best Position: " + swarm.globalBestPosition);
        System.out.println("Global Best Fitness: " + swarm.globalBestFitness);
    }
}