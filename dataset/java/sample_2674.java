import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> bestPosition;
    double bestValue;

    Particle(int dimensions) {
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        bestPosition = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < dimensions; i++) {
            position.add(random.nextDouble() * 20 - 10);
            velocity.add(random.nextDouble() * 2 - 1);
            bestPosition.add(position.get(i));
        }
        bestValue = calculateValue();
    }

    double calculateValue() {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void update(List<Double> globalBest) {
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        Random random = new Random();
        for (int i = 0; i < position.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            velocity.set(i, w * velocity.get(i) + c1 * r1 * (bestPosition.get(i) - position.get(i)) + c2 * r2 * (globalBest.get(i) - position.get(i)));
            position.set(i, position.get(i) + velocity.get(i));
        }
        bestValue = calculateValue();
        if (bestValue < bestValue) {
            bestValue = bestValue;
            bestPosition = new ArrayList<>(position);
        }
    }
}

class Swarm {
    int size;
    int dimensions;
    List<Particle> particles;
    List<Double> bestPosition;
    double bestValue;

    Swarm(int size, int dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            particles.add(new Particle(dimensions));
        }
        bestPosition = null;
        bestValue = Double.MAX_VALUE;
    }

    void updateBest() {
        for (Particle particle : particles) {
            if (particle.bestValue < bestValue) {
                bestValue = particle.bestValue;
                bestPosition = new ArrayList<>(particle.bestPosition);
            }
        }
    }

    void optimize(int iterations) {
        for (int i = 0; i < iterations; i++) {
            for (Particle particle : particles) {
                particle.update(bestPosition);
            }
            updateBest();
        }
    }
}

public class sample_2674 {
    public static void main(String[] args) {
        int dimensions = 2;
        int swarmSize = 30;
        int iterations = 100;
        Swarm swarm = new Swarm(swarmSize, dimensions);
        swarm.optimize(iterations);
        System.out.println('Best position: ' + swarm.bestPosition);
        System.out.println('Best value: ' + swarm.bestValue);
    }
}