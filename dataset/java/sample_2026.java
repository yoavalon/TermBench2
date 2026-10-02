import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_2026 {

    public static void main(String[] args) {
        main();
    }

    public static void main() {
        Random random = new Random();
        int dimensions = 30;
        int size = 30;
        int iterations = 100;
        double[] bounds = {-10, 10};
        double[] result = optimize(sphereFunction, dimensions, size, iterations, bounds);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }

    public static double[] initializeParticles(int size, int dimensions, Random random) {
        List<Particle> particles = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            double[] position = new double[dimensions];
            double[] velocity = new double[dimensions];
            double[] pbestPosition = new double[dimensions];
            for (int j = 0; j < dimensions; j++) {
                position[j] = random.nextDouble() * 20 - 10;
                velocity[j] = random.nextDouble() * 2 - 1;
                pbestPosition[j] = position[j];
            }
            particles.add(new Particle(position, velocity, pbestPosition, Double.MAX_VALUE));
        }
        return findGBest(particles);
    }

    public static void updateVelocity(List<Particle> particles, double[] gbestPosition, double w, double c1, double c2, Random random) {
        for (Particle particle : particles) {
            for (int i = 0; i < particle.position.length; i++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                double cognitive = c1 * r1 * (particle.pbestPosition[i] - particle.position[i]);
                double social = c2 * r2 * (gbestPosition[i] - particle.position[i]);
                particle.velocity[i] = w * particle.velocity[i] + cognitive + social;
            }
        }
    }

    public static void updatePosition(List<Particle> particles, double[] bounds) {
        for (Particle particle : particles) {
            for (int i = 0; i < particle.position.length; i++) {
                particle.position[i] += particle.velocity[i];
                particle.position[i] = Math.max(bounds[0], Math.min(particle.position[i], bounds[1]));
            }
        }
    }

    public static void evaluate(List<Particle> particles, ObjectiveFunction objectiveFunction) {
        for (Particle particle : particles) {
            double value = objectiveFunction.evaluate(particle.position);
            if (value < particle.pbestValue) {
                particle.pbestValue = value;
                particle.pbestPosition = particle.position.clone();
            }
        }
    }

    public static double[] findGBest(List<Particle> particles) {
        double gbestValue = Double.MAX_VALUE;
        double[] gbestPosition = new double[particles.get(0).position.length];
        for (Particle particle : particles) {
            if (particle.pbestValue < gbestValue) {
                gbestValue = particle.pbestValue;
                gbestPosition = particle.pbestPosition.clone();
            }
        }
        return gbestPosition;
    }

    public static double[] optimize(ObjectiveFunction objectiveFunction, int dimensions, int size, int iterations, double[] bounds) {
        List<Particle> particles = new ArrayList<>();
        Random random = new Random();
        particles.add(new Particle(new double[dimensions], new double[dimensions], new double[dimensions], Double.MAX_VALUE));
        double[] gbestPosition = initializeParticles(size, dimensions, random);
        for (int i = 0; i < iterations; i++) {
            updateVelocity(particles, gbestPosition, 0.7, 1.5, 1.5, random);
            updatePosition(particles, bounds);
            evaluate(particles, objectiveFunction);
            gbestPosition = findGBest(particles);
        }
        return gbestPosition;
    }

    public static double sphereFunction(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static class Particle {
        double[] position;
        double[] velocity;
        double[] pbestPosition;
        double pbestValue;

        Particle(double[] position, double[] velocity, double[] pbestPosition, double pbestValue) {
            this.position = position;
            this.velocity = velocity;
            this.pbestPosition = pbestPosition;
            this.pbestValue = pbestValue;
        }
    }

    interface ObjectiveFunction {
        double evaluate(double[] x);
    }
}