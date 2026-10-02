import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1073 {
    public static void main(String[] args) {
        optimize();
    }

    public static double[] update_position(double position, double velocity, double p_best, double g_best) {
        Random random = new Random();
        double r1 = random.nextDouble();
        double r2 = random.nextDouble();
        double c1 = 1.5;
        double c2 = 1.5;
        double new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position);
        double new_position = position + new_velocity;
        return new double[]{new_position, new_velocity};
    }

    public static void optimize() {
        List<Particle> particles = new ArrayList<>();
        particles.add(new Particle(random.uniform(-10, 10), random.uniform(-1, 1), null));
        double g_best = particles.get(0).position;

        while (true) {
            for (Particle particle : particles) {
                if (particle.p_best == null) {
                    particle.p_best = particle.position;
                } else if (particle.position < particle.p_best) {
                    particle.p_best = particle.position;
                }
                if (particle.position < g_best) {
                    g_best = particle.position;
                }
            }
            for (Particle particle : particles) {
                double[] result = update_position(particle.position, particle.velocity, particle.p_best, g_best);
                particle.position = result[0];
                particle.velocity = result[1];
            }
        }
    }

    static class Particle {
        double position;
        double velocity;
        Double p_best;

        Particle(double position, double velocity, Double p_best) {
            this.position = position;
            this.velocity = velocity;
            this.p_best = p_best;
        }
    }

    public static double uniform(double min, double max) {
        return min + (Math.random() * (max - min));
    }
}