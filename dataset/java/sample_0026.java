import java.util.Arrays;

public class sample_0026 {
    public static double[] boundary_conditions(double[] x, double[] lb, double[] ub) {
        for (int i = 0; i < x.length; i++) {
            if (x[i] < lb[i]) {
                x[i] = lb[i];
            } else if (x[i] > ub[i]) {
                x[i] = ub[i];
            }
        }
        return x;
    }

    public static void main(String[] args) {
        double[] x = {1.5, -2.0, 3.0};
        double[] lb = {0.0, -1.0, 2.0};
        double[] ub = {2.0, 0.0, 4.0};
        double[] result = boundary_conditions(x, lb, ub);
        System.out.println(Arrays.toString(result));
    }
}