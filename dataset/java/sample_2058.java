import java.util.Arrays;
import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] bestPosition;
    double bestScore;

    public Particle(int dimensions) {
        Random random = new Random();
        this.position = new double[dimensions];
        this.velocity = new double[dimensions];
        this.bestPosition = new double[dimensions];
        this.bestScore = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            position[i] = random.nextDouble() * 20 - 10;
            velocity[i] = random.nextDouble() * 2 - 1;
            bestPosition[i] = position[i];
        }
    }

    public void updateVelocity(double[] globalBest, double w, double c1, double c2) {
        Random random = new Random();
        for (int i = 0; i < position.length; i++) {
            double r1 = random.nextDouble();
            double r2 = random.nextDouble();
            double cognitive = c1 * r1 * (bestPosition[i] - position[i]);
            double social = c2 * r2 * (globalBest[i] - position[i]);
            velocity[i] = w * velocity[i] + cognitive + social;
        }
    }

    public void updatePosition() {
        for (int i = 0; i < position.length; i++) {
            position[i] += velocity[i];
            if (position[i] < -10) {
                position[i] = -10;
            } else if (position[i] > 10) {
                position[i] = 10;
            }
        }
    }
}

class Swarm {
    Particle[] particles;
    double[] globalBest;
    double globalBestScore;

    public Swarm(int numParticles, int dimensions) {
        this.particles = new Particle[numParticles];
        for (int i = 0; i < numParticles; i++) {
            particles[i] = new Particle(dimensions);
        }
        this.globalBest = new double[dimensions];
        this.globalBestScore = Double.POSITIVE_INFINITY;
    }

    public void updateGlobalBest() {
        for (Particle particle : particles) {
            if (particle.bestScore < globalBestScore) {
                globalBest = Arrays.copyOf(particle.bestPosition, particle.bestPosition.length);
                globalBestScore = particle.bestScore;
            }
        }
    }

    public void optimize(int iterations, double w, double c1, double c2) {
        for (int i = 0; i < iterations; i++) {
            updateGlobalBest();
            for (Particle particle : particles) {
                particle.updateVelocity(globalBest, w, c1, c2);
                particle.updatePosition();
            }
        }
    }
}

class sample_2058 {
    public static double objectiveFunction(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    public static void main(String[] args) {
        int dimensions = 30;
        int numParticles = 30;
        int iterations = 100;
        double w = 0.7;
        double c1 = 2.0;
        double c2 = 2.0;
        Swarm swarm = new Swarm(numParticles, dimensions);
        for (Particle particle : swarm.particles) {
            double score = objectiveFunction(particle.position);
            if (score < particle.bestScore) {
                particle.bestScore = score;
            }
        }
        swarm.optimize(iterations, w, c1, c2);
        double bestScore = swarm.globalBestScore;
        System.out.println("Best Score: " + bestScore);
    }
}