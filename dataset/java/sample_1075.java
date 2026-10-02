import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1075 {
    public static void main(String[] args) {
        main();
    }

    public static void main() {
        sample_1075 swarm = new sample_1075();
        double[] bounds = {-10, 10};
        swarm.swarm_search(swarm::objective, new double[][]{bounds, bounds}, 30, 0.7, 1.5, 1.5);
    }

    public double objective(double[] x) {
        double sum = 0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    public double update_velocity(List<Double> p, List<Double> g, List<Double> l, double w, double c1, double c2) {
        Random random = new Random();
        double r1 = random.nextDouble();
        double r2 = random.nextDouble();
        double v = w * l.get(0) + c1 * r1 * (p.get(0) - l.get(0)) + c2 * r2 * (g.get(0) - l.get(0));
        return v;
    }

    public double update_position(double l, double v) {
        return l + v;
    }

    public void swarm_search(ObjectiveFunction f, double[][] bounds, int n_particles, double w, double c1, double c2) {
        List<List<Double>> particles = new ArrayList<>();
        List<List<Double>> velocities = new ArrayList<>();
        List<List<Double>> pbest = new ArrayList<>();
        List<Double> gbest = new ArrayList<>();

        Random random = new Random();
        for (int i = 0; i < n_particles; i++) {
            List<Double> particle = new ArrayList<>();
            List<Double> velocity = new ArrayList<>();
            for (double[] bound : bounds) {
                double value = random.nextDouble() * (bound[1] - bound[0]) + bound[0];
                particle.add(value);
                velocity.add(0.0);
            }
            particles.add(particle);
            velocities.add(velocity);
            pbest.add(new ArrayList<>(particle));
        }

        gbest = findMin(particles, f);

        while (true) {
            for (int i = 0; i < n_particles; i++) {
                List<Double> velocity = new ArrayList<>();
                for (int j = 0; j < bounds.length; j++) {
                    double v = update_velocity(pbest.get(i), gbest, particles.get(i), w, c1, c2);
                    velocity.add(v);
                }
                velocities.set(i, velocity);

                List<Double> particle = new ArrayList<>();
                for (int j = 0; j < bounds.length; j++) {
                    double p = update_position(particles.get(i).get(j), velocities.get(i).get(j));
                    particle.add(p);
                }
                particles.set(i, particle);
            }

            for (int i = 0; i < n_particles; i++) {
                if (f.evaluate(particles.get(i)) < f.evaluate(pbest.get(i))) {
                    pbest.set(i, new ArrayList<>(particles.get(i)));
                }
            }

            gbest = findMin(particles, f);
        }
    }

    private List<Double> findMin(List<List<Double>> particles, ObjectiveFunction f) {
        List<Double> minParticle = particles.get(0);
        double minValue = f.evaluate(minParticle);
        for (List<Double> particle : particles) {
            double value = f.evaluate(particle);
            if (value < minValue) {
                minValue = value;
                minParticle = particle;
            }
        }
        return minParticle;
    }

    @FunctionalInterface
    interface ObjectiveFunction {
        double evaluate(List<Double> x);
    }
}