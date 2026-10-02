import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> bestPosition;
    double bestScore;

    public Particle(int dimensions) {
        Random rand = new Random();
        this.position = new ArrayList<>();
        this.velocity = new ArrayList<>();
        this.bestPosition = new ArrayList<>();
        this.bestScore = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            double pos = rand.nextDouble() * 2 - 1;
            double vel = rand.nextDouble() * 2 - 1;
            position.add(pos);
            velocity.add(vel);
            bestPosition.add(pos);
        }
    }

    public void updateVelocity(List<Double> globalBest, double inertia, double cognitive, double social) {
        Random rand = new Random();
        for (int i = 0; i < position.size(); i++) {
            double r1 = rand.nextDouble();
            double r2 = rand.nextDouble();
            double newVelocity = inertia * velocity.get(i) + cognitive * r1 * (bestPosition.get(i) - position.get(i)) + social * r2 * (globalBest.get(i) - position.get(i));
            velocity.set(i, newVelocity);
        }
    }

    public void updatePosition() {
        for (int i = 0; i < position.size(); i++) {
            double newPosition = position.get(i) + velocity.get(i);
            position.set(i, newPosition);
        }
    }

    public void evaluate(double fitnessFunction(List<Double> x)) {
        double score = fitnessFunction(position);
        if (score < bestScore) {
            bestScore = score;
            bestPosition.clear();
            bestPosition.addAll(position);
        }
    }
}

class Swarm {
    List<Particle> particles;
    double globalBestScore;
    List<Double> globalBest;
    double inertia;
    double cognitive;
    double social;
    int maxIterations;

    public Swarm(int size, int dimensions, double fitnessFunction(List<Double> x), int maxIterations, double inertia, double cognitive, double social) {
        this.particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            particles.add(new Particle(dimensions));
        }
        this.globalBestScore = Double.POSITIVE_INFINITY;
        this.globalBest = new ArrayList<>();
        this.maxIterations = maxIterations;
        this.inertia = inertia;
        this.cognitive = cognitive;
        this.social = social;
    }

    public void updateGlobalBest() {
        for (Particle particle : particles) {
            if (particle.bestScore < globalBestScore) {
                globalBestScore = particle.bestScore;
                globalBest.clear();
                globalBest.addAll(particle.bestPosition);
            }
        }
    }

    public void optimize() {
        for (int i = 0; i < maxIterations; i++) {
            for (Particle particle : particles) {
                particle.updateVelocity(globalBest, inertia, cognitive, social);
                particle.updatePosition();
                particle.evaluate(this::sphereFunction);
            }
            updateGlobalBest();
        }
    }

    public double sphereFunction(List<Double> x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }
}

public class sample_0855 {
    public static void main(String[] args) {
        int dimensions = 2;
        int size = 30;
        int maxIterations = 100;
        double inertia = 0.5;
        double cognitive = 1.5;
        double social = 1.5;
        Swarm swarm = new Swarm(size, dimensions, Swarm::sphereFunction, maxIterations, inertia, cognitive, social);
        swarm.optimize();
        System.out.println("Best position: " + swarm.globalBest);
        System.out.println("Best score: " + swarm.globalBestScore);
    }
}