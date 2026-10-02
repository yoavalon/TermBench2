public class sample_0085 {
    public static void main(String[] args) {
        optimize(100, 20, 3);
    }

    public static double[] optimize(int iterations, int particles, int dimensions) {
        double[][] velocity = new double[particles][dimensions];
        double[][] position = new double[particles][dimensions];
        double[][] best_position = new double[particles][dimensions];
        double[] global_best = new double[dimensions];
        for (int _ = 0; _ < iterations; _++) {
            for (int i = 0; i < particles; i++) {
                for (int j = 0; j < dimensions; j++) {
                    velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j]);
                    position[i][j] += velocity[i][j];
                }
            }
        }
        return global_best;
    }
}