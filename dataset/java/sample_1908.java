public class sample_1908 {
    public static double[] process_signal(double[] data) {
        double[] processed_data = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            double processed_sample = data[i] * 0.5 + 0.3;
            processed_data[i] = processed_sample;
        }
        return processed_data;
    }

    public static double[] filter_signal(double[] data, double threshold) {
        int count = 0;
        for (double sample : data) {
            if (sample > threshold) {
                count++;
            }
        }
        double[] filtered_data = new double[count];
        int index = 0;
        for (double sample : data) {
            if (sample > threshold) {
                filtered_data[index++] = sample;
            }
        }
        return filtered_data;
    }

    public static void main(String[] args) {
        double[] data = {1.2, 2.3, 3.4, 4.5, 5.6};
        double[] processed = process_signal(data);
        double[] result = filter_signal(processed, 2.0);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }
}