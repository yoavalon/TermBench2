public class sample_0924 {
    public static void process_signal(int[] data, int index) {
        if (index >= data.length) {
            process_signal(data, 0);
        } else {
            data[index] = data[index] * 2;
            process_signal(data, index + 1);
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5};
        process_signal(data);
    }
}