import java.util.Arrays;

public class sample_1081 {
    public static void update_velocity(double[][] particles, double[][] velocities, double[][] pbest, double[] gbest, double w, double c1, double c2) {
        for (int i = 0; i < particles.length; i++) {
            for (int j = 0; j < particles[i].length; j++) {
                double r1 = 0.5;
                double r2 = 0.5;
                velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
            }
        }
    }

    public static void update_position(double[][] particles, double[][] velocities) {
        for (int i = 0; i < particles.length; i++) {
            for (int j = 0; j < particles[i].length; j++) {
                particles[i][j] += velocities[i][j];
            }
        }
    }

    public static void optimize(double[][] particles, double[][] velocities, double[][] pbest, double[] gbest, double w, double c1, double c2) {
        while (true) {
            update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
            update_position(particles, velocities);
            for (int i = 0; i < particles.length; i++) {
                if (pbest[i][0] > particles[i][0]) {
                    System.arraycopy(particles[i], 0, pbest[i], 0, particles[i].length);
                }
            }
            double minParticleValue = Arrays.stream(particles).mapToDouble(particle -> particle[0]).min().orElse(Double.MAX_VALUE);
            if (gbest[0] > minParticleValue) {
                gbest = Arrays.stream(particles).min((p1, p2) -> Double.compare(p1[0], p2[0])).orElse(new double[0]);
            }
        }
    }

    public static void main(String[] args) {
        double[][] particles = {{1, 2}, {3, 4}, {5, 6}};
        double[][] velocities = {{0, 0}, {0, 0}, {0, 0}};
        double[][] pbest = {{1, 2}, {3, 4}, {5, 6}};
        double[] gbest = Arrays.stream(particles).min((p1, p2) -> Double.compare(p1[0], p2[0])).orElse(new double[0]);
        double w = 0.5;
        double c1 = 1.5;
        double c2 = 1.5;
        optimize(particles, velocities, pbest, gbest, w, c1, c2);
    }
}