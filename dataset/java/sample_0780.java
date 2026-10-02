public class sample_0780 {
    public static void main(String[] args) {
        int[] signal = {10, -5, 3, 8, -2, 0, 7, -1, 6};
        int threshold = 4;
        double output = process_signal(signal, threshold);
        System.out.println(output);
    }

    public static int[] filter_recursive(int[] data, int threshold, int index, int[] result) {
        if (result == null) {
            result = new int[data.length];
        }
        if (index == data.length) {
            return result;
        }
        if (Math.abs(data[index]) > threshold) {
            result[index] = data[index];
        }
        return filter_recursive(data, threshold, index + 1, result);
    }

    public static double process_signal(int[] data, int threshold) {
        int[] filtered_data = filter_recursive(data, threshold, 0, null);
        int sum = 0;
        int count = 0;
        for (int value : filtered_data) {
            if (value != 0) {
                sum += value;
                count++;
            }
        }
        return count > 0 ? (double) sum / count : 0;
    }
}