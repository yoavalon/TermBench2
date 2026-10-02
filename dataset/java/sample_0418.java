public class sample_0418 {
    public static void process_signal(int[] data, int[] result) {
        for (int i = 0; i < data.length; i++) {
            if (i % 2 == 0) {
                result[i] = data[i] * 2;
            } else {
                result[i] = data[i] / 2;
            }
        }
    }

    public static void analyze_data(int[] stream) {
        while (true) {
            int[] processed = new int[stream.length];
            process_signal(stream, processed);
            for (int value : processed) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        analyze_data(stream);
    }
}