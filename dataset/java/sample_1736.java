import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    private List<Double> position;
    private List<Double> velocity;
    private List<Double> bestPosition;
    private Random random;

    public Particle(int dimensions) {
        this.random = new Random();
        this.position = new ArrayList<>();
        this.velocity = new ArrayList<>();
        this.bestPosition = new ArrayList<>();
        for (int i = 0; i < dimensions; i++) {
            position.add(random.nextDouble() * 20 - 10);
            velocity.add(random.nextDouble() * 2 - 1);
            bestPosition.add(position.get(i));
        }
    }

    public void updateVelocity(List<Double> globalBest, double inertia, double cognitive, double social) {
        for (int i = 0; i < velocity.size(); i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            velocity.set(i, inertia * velocity.get(i) + cognitive * r1 * (bestPosition.get(i) - position.get(i)) + social * r2 * (globalBest.get(i) - position.get(i)));
        }
    }

    public void updatePosition() {
        for (int i = 0; i < position.size(); i++) {
            position.set(i, position.get(i) + velocity.get(i));
        }
    }

    public void updateBestPosition(ObjectiveFunction objectiveFunction) {
        double currentFitness = objectiveFunction.evaluate(position);
        double bestFitness = objectiveFunction.evaluate(bestPosition);
        if (currentFitness < bestFitness) {
            bestPosition = new ArrayList<>(position);
        }
    }
}

class Swarm {
    private List<Particle> particles;
    private List<Double> globalBest;
    private ObjectiveFunction objectiveFunction;
    private Random random;

    public Swarm(int dimensions, int numParticles, ObjectiveFunction objectiveFunction) {
        this.random = new Random();
        this.particles = new ArrayList<>();
        for (int i = 0; i < numParticles; i++) {
            particles.add(new Particle(dimensions));
        }
        globalBest = new ArrayList<>(particles.get(0).getPosition());
        this.objectiveFunction = objectiveFunction;
    }

    public void updateGlobalBest() {
        for (Particle particle : particles) {
            double currentFitness = objectiveFunction.evaluate(particle.getPosition());
            double globalBestFitness = objectiveFunction.evaluate(globalBest);
            if (currentFitness < globalBestFitness) {
                globalBest = new ArrayList<>(particle.getPosition());
            }
        }
    }

    public void optimize(double inertia, double cognitive, double social) {
        while (true) {
            for (Particle particle : particles) {
                particle.updateVelocity(globalBest, inertia, cognitive, social);
                particle.updatePosition();
                particle.updateBestPosition(objectiveFunction);
            }
            updateGlobalBest();
        }
    }
}

interface ObjectiveFunction {
    double evaluate(List<Double> x);
}

class QuadraticObjectiveFunction implements ObjectiveFunction {
    public double evaluate(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }
}

public class sample_1736 {
    public static void main(String[] args) {
        int dimensions = 2;
        int numParticles = 30;
        double inertia = 0.7;
        double cognitive = 1.5;
        double social = 1.5;
        ObjectiveFunction objectiveFunction = new QuadraticObjectiveFunction();
        Swarm swarm = new Swarm(dimensions, numParticles, objectiveFunction);
        swarm.optimize(inertia, cognitive, social);
    }
}