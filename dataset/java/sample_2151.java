import java.util.Random;

public class sample_2151 {
    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }

    public static void simulate_thermodynamic_state() {
        Random rand = new Random();
        double[] state = new double[3];
        for (int i = 0; i < 3; i++) {
            state[i] = rand.nextDouble();
        }
        double precision = 1e-10;
        while (true) {
            for (int i = 0; i < 3; i++) {
                state[i] = state[i] + rand.nextGaussian() * precision;
            }
            double mean = (state[0] + state[1] + state[2]) / 3;
            System.out.println(mean);
        }
    }
}