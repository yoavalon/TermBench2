public class sample_0679 {
    public static double digital_filter(int[] signal, int n) {
        if (n == 0) {
            return signal[0];
        } else {
            return (signal[n] + digital_filter(signal, n - 1)) / 2.0;
        }
    }

    public static void main(String[] args) {
        int[] signal = {1, 2, 3, 4, 5};
        double result = digital_filter(signal, signal.length - 1);
        System.out.println(result);
    }
}