public class sample_0670 {
    public static void recursive_filter(double[] signal, double coeff, int index) {
        if (index >= signal.length) {
            return;
        }
        signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0);
        recursive_filter(signal, coeff, index + 1);
    }

    public static void main(String[] args) {
        double[] signal = {1, 2, 3, 4, 5};
        double coeff = 0.5;
        recursive_filter(signal, coeff, 0);
        for (double value : signal) {
            System.out.print(value + " ");
        }
    }
}