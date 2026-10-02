public class sample_0807 {

    static class SignalProcessor {
        int[] data;
        int threshold;

        SignalProcessor(int[] data, int threshold) {
            this.data = data;
            this.threshold = threshold;
        }

        int[] filter_data(int index) {
            if (index >= data.length) {
                return new int[0];
            }
            if (Math.abs(data[index]) > threshold) {
                int[] rest = filter_data(index + 1);
                int[] result = new int[rest.length + 1];
                result[0] = data[index];
                System.arraycopy(rest, 0, result, 1, rest.length);
                return result;
            }
            return filter_data(index + 1);
        }
    }

    static class DataAnalyzer {
        int[] processed_data;

        DataAnalyzer(int[] processed_data) {
            this.processed_data = processed_data;
        }

        double compute_average(int index, double total) {
            if (index >= processed_data.length) {
                return total / processed_data.length;
            }
            return compute_average(index + 1, total + processed_data[index]);
        }

        int find_max(int index, Integer current_max) {
            if (current_max == null) {
                current_max = processed_data[index];
            }
            if (index >= processed_data.length) {
                return current_max;
            }
            if (processed_data[index] > current_max) {
                current_max = processed_data[index];
            }
            return find_max(index + 1, current_max);
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 3, -5, 7, -9, 11, -13, 15, -17, 19};
        int threshold = 10;
        SignalProcessor processor = new SignalProcessor(data, threshold);
        int[] filtered_data = processor.filter_data(0);
        DataAnalyzer analyzer = new DataAnalyzer(filtered_data);
        double average = analyzer.compute_average(0, 0);
        int max_value = analyzer.find_max(0, null);
        System.out.println("Average: " + average);
        System.out.println("Max Value: " + max_value);
    }
}