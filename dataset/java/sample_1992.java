import java.util.Random;

public class sample_1992 {
    public static double fitness_function(double x) {
        return x * x;
    }

    public static double[] update_position(double position, double velocity, double w, double c1, double c2, double pbest, double gbest) {
        Random random = new Random();
        double r1 = random.nextDouble();
        double r2 = random.nextDouble();
        velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position);
        position = position + velocity;
        return new double[]{position, velocity};
    }

    public static double optimize(int iterations, double w, double c1, double c2, double[] bounds) {
        double[] particles = new double[30];
        double[] velocities = new double[30];
        double[] pbests = new double[30];
        Random random = new Random();
        for (int i = 0; i < 30; i++) {
            particles[i] = random.nextDouble() * (bounds[1] - bounds[0]) + bounds[0];
            velocities[i] = 0;
            pbests[i] = particles[i];
        }
        double gbest = findMin(particles);

        for (int iter = 0; iter < iterations; iter++) {
            for (int i = 0; i < 30; i++) {
                double[] result = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest);
                particles[i] = result[0];
                velocities[i] = result[1];
                if (fitness_function(particles[i]) < fitness_function(pbests[i])) {
                    pbests[i] = particles[i];
                }
            }
            gbest = findMin(particles);
        }
        return gbest;
    }

    private static double findMin(double[] array) {
        double min = array[0];
        for (double value : array) {
            if (fitness_function(value) < fitness_function(min)) {
                min = value;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int iterations = 100;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        double[] bounds = {-10, 10};
        double result = optimize(iterations, w, c1, c2, bounds);
        System.out.println(result);
    }
}