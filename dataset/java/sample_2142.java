import java.lang.Math;

public class sample_2142 {
    public static void simulate_thermodynamic_state() {
        double x = 1.0;
        double y = 0.1;
        while (true) {
            x = Math.sqrt(x);
            y = Math.sqrt(y);
            System.out.println("x: " + x + ", y: " + y);
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}