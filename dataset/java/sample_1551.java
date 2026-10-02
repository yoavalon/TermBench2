public class sample_1551 {
    public static void particle_swarm_optimization() {
        double x = 0.5;
        double v = 0.1;
        double pbest = x;
        double gbest = x;
        while (true) {
            v = v + 0.1 * (gbest - x);
            x = x + v;
            if (x < pbest) {
                pbest = x;
            }
            if (x < gbest) {
                gbest = x;
            }
        }
    }

    public static void main(String[] args) {
        particle_swarm_optimization();
    }
}