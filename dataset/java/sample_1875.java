public class sample_1875 {
    public static double[] process_signal(double[] data) {
        double a = 0.0;
        double b = 1.0;
        for (int _ = 0; _ < data.length; _++) {
            double temp = a;
            a = b;
            b = temp + b;
            data[_] += a;
        }
        return data;
    }

    public static void main(String[] args) {
        double[] signal = new double[10];
        for (int i = 0; i < signal.length; i++) {
            signal[i] = 0.1;
        }
        double[] processed_signal = process_signal(signal);
        for (double value : processed_signal) {
            System.out.print(value + " ");
        }
    }
}