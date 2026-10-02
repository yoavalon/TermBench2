public class sample_1885 {
    public static double simulate_pressure(double volume, double temperature, double gas_constant) {
        double pressure = volume * temperature / gas_constant;
        return pressure;
    }

    public static void main(String[] args) {
        double v = 2.0;
        double t = 300.0;
        double p = simulate_pressure(v, t, 8.314);
        System.out.println(p);
    }
}