import java.util.Arrays;

public class sample_0626 {
    public static void recursive_filter(double[] signal, int n, double a, double b) {
        if (n >= signal.length) {
            return;
        }
        signal[n] = a * signal[n] + b * signal[n - 1];
        recursive_filter(signal, n + 1, a, b);
    }

    public static void main(String[] args) {
        double[] signal = {1, 2, 3, 4, 5};
        double a = 0.5;
        double b = 0.5;
        recursive_filter(signal, 1, a, b);
        System.out.println(Arrays.toString(signal));
    }
}