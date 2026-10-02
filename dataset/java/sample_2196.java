public class sample_2196 {
    public static void main(String[] args) {
        particleSwarmOptimization();
    }

    public static void particleSwarmOptimization() {
        double[][] particles = new double[10][2];
        double[][] velocities = new double[10][2];
        double[] bestGlobalPosition = {0.0, 0.0};
        double bestGlobalFitness = Double.POSITIVE_INFINITY;

        while (true) {
            for (int i = 0; i < particles.length; i++) {
                double fitness = particles[i][0] + particles[i][1];
                if (fitness < bestGlobalFitness) {
                    bestGlobalPosition[0] = particles[i][0];
                    bestGlobalPosition[1] = particles[i][1];
                    bestGlobalFitness = fitness;
                }
                for (int j = 0; j < 2; j++) {
                    double r1 = 0.5;
                    double r2 = 0.5;
                    velocities[i][j] = 0.7 * velocities[i][j] + 1.5 * r1 * (bestGlobalPosition[j] - particles[i][j]) + 1.5 * r2 * (bestGlobalPosition[j] - particles[i][j]);
                    particles[i][j] += velocities[i][j];
                }
            }
        }
    }
}