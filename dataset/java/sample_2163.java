import java.util.Random;

public class sample_2163 {
    static void simulate_thermodynamic_state() {
        Random rand = new Random();
        double x = rand.nextDouble();
        while (x > 0.0001) {
            double y = Math.sin(x) + Math.cos(x);
            double z = Math.exp(-x);
            x = y * z;
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}