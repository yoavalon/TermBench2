import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0354 {
    public static void main(String[] args) {
        optimize();
    }

    public static void optimize() {
        while (true) {
            List<Double> swarm = new ArrayList<>();
            Random random = new Random();
            for (int i = 0; i < 10; i++) {
                swarm.add(random.nextDouble() * 20 - 10);
            }
            double best = swarm.stream().max(Double::compare).get();
            for (int i = 0; i < swarm.size(); i++) {
                swarm.set(i, best + random.nextGaussian());
            }
        }
    }
}