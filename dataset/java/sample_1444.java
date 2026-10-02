import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] bestPosition;
    double bestScore;

    public Particle(int dimensions, double[] bounds) {
        Random random = new Random();
        position = new double[dimensions];
        velocity = new double[dimensions];
        bestPosition = new double[dimensions];
        bestScore = Double.POSITIVE_INFINITY;

        for (int i = 0; i < dimensions; i++) {
            position[i] = random.nextDouble() * (bounds[1] - bounds[0]) + bounds[0];
            velocity[i] = random.nextDouble() * 2 - 1;
            bestPosition[i] = position[i];
        }
    }

    public void updateVelocity(double[] globalBest, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < velocity.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            velocity[i] = w * velocity[i] + c1 * r1 * (bestPosition[i] - position[i]) + c2 * r2 * (globalBest[i] - position[i]);
        }
    }

    public void updatePosition(double[] bounds) {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            position[i] = Math.max(bounds[0], Math.min(bounds[1], position[i]));
        }
    }

    public void evaluate(ObjectiveFunction objectiveFunction) {
        double score = objectiveFunction.call(position);
        if (score < bestScore) {
            bestScore = score;
            bestPosition = position.clone();
        }
    }
}

class Swarm {
    List<Particle> particles;
    double[] globalBestPosition;
    double globalBestScore;

    public Swarm(int numParticles, int dimensions, double[] bounds) {
        particles = new ArrayList<>();
        for (int i = 0; i < numParticles; i++) {
            particles.add(new Particle(dimensions, bounds));
        }
        globalBestPosition = particles.get(0).bestPosition.clone();
        globalBestScore = particles.get(0).bestScore;
    }

    public void updateGlobalBest() {
        for (Particle particle : particles) {
            if (particle.bestScore < globalBestScore) {
                globalBestScore = particle.bestScore;
                globalBestPosition = particle.bestPosition.clone();
            }
        }
    }

    public void iterate(ObjectiveFunction objectiveFunction) {
        for (Particle particle : particles) {
            particle.updateVelocity(globalBestPosition, 0.7, 1.5, 1.5);
            particle.updatePosition(objectiveFunction.bounds);
            particle.evaluate(objectiveFunction);
        }
        updateGlobalBest();
    }
}

class ObjectiveFunction {
    double[] bounds;

    public ObjectiveFunction(double[] bounds) {
        this.bounds = bounds;
    }

    public double call(double[] position) {
        double x = position[0];
        double y = position[1];
        return Math.pow(x * x + y - 11, 2) + Math.pow(x + y * y - 7, 2);
    }
}

public class sample_1444 {
    public static void main(String[] args) {
        int dimensions = 2;
        int numParticles = 30;
        double[] bounds = {-5, 5};
        ObjectiveFunction objectiveFunction = new ObjectiveFunction(bounds);
        Swarm swarm = new Swarm(numParticles, dimensions, bounds);
        for (int i = 0; i < 100; i++) {
            swarm.iterate(objectiveFunction);
            if (swarm.globalBestScore < 1e-06) {
                break;
            }
        }
        System.out.println("Best position: " + java.util.Arrays.toString(swarm.globalBestPosition));
        System.out.println("Best score: " + swarm.globalBestScore);
    }
}