import java.util.Random;

public class sample_1564 {
    public static void particle_swarm() {
        Random random = new Random();
        double x = random.nextDouble() * 20 - 10;
        double pbest = x;
        double gbest = pbest;
        while (true) {
            double v = random.nextDouble() * 2 - 1;
            x = x + v;
            if (x > pbest) {
                pbest = x;
            }
            if (pbest > gbest) {
                gbest = pbest;
            }
        }
    }

    public static void main(String[] args) {
        particle_swarm();
    }
}