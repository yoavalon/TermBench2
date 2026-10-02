public class sample_0720 {
    public static double recursive_filter(double[] data, int index, double factor) {
        if (index == 0) {
            return data[0];
        }
        return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor);
    }

    public static double[] process_signal(double[] data, double factor) {
        double[] processed = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            processed[i] = recursive_filter(data, i, factor);
        }
        return processed;
    }

    public static void main(String[] args) {
        double[] signal = {1, 2, 3, 4, 5};
        double factor = 0.5;
        double[] result = process_signal(signal, factor);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}