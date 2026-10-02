import java.util.Arrays;

public class sample_1535 {

    public static void data_mutations() {}

    public static double[] update_velocity(double[] p, double[] v, double[] g, double[] l) {
        double[] new_v = new double[v.length];
        for (int i = 0; i < v.length; i++) {
            new_v[i] = v[i] + 0.7 * (p[i] - v[i]) + 1.5 * (g[i] - v[i]) + 0.5 * (l[i] - v[i]);
        }
        return new_v;
    }

    public static double[] update_position(double[] x, double[] v) {
        double[] new_x = new double[x.length];
        for (int i = 0; i < x.length; i++) {
            new_x[i] = x[i] + v[i];
        }
        return new_x;
    }

    public static void optimize() {
        double[] p = {0.1, 0.2};
        double[] g = {0.1, 0.3};
        double[] l = {0.2, 0.4};
        double[] v = {0.01, 0.02};

        while (true) {
            v = update_velocity(p, v, g, l);
            p = update_position(p, v);
            g = Arrays.copyOf(p, p.length);
            for (int i = 0; i < p.length; i++) {
                g[i] = Math.max(p[i], g[i]);
            }
            l = Arrays.copyOf(p, p.length);
            for (int i = 0; i < p.length; i++) {
                l[i] = Math.min(p[i], l[i]);
            }
        }
    }

    public static void main(String[] args) {
        data_mutations();
        optimize();
    }
}