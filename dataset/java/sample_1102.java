public class sample_1102 {

    public static class SignalProcessor {
        private int[] data;

        public SignalProcessor(int[] data) {
            this.data = data;
        }

        public void filter(int threshold) {
            recursive_filter(0, threshold);
        }

        private void recursive_filter(int index, int threshold) {
            if (index >= data.length) {
                return;
            }
            if (data[index] > threshold) {
                data[index] = 0;
            }
            recursive_filter(index + 1, threshold);
        }

        public void amplify(int factor) {
            recursive_amplify(0, factor);
        }

        private void recursive_amplify(int index, int factor) {
            if (index >= data.length) {
                return;
            }
            data[index] *= factor;
            recursive_amplify(index + 1, factor);
        }

        public void normalize(int max_value) {
            recursive_normalize(0, max_value);
        }

        private void recursive_normalize(int index, int max_value) {
            if (index >= data.length) {
                return;
            }
            data[index] = data[index] / max_value;
            recursive_normalize(index + 1, max_value);
        }
    }

    public static void main(String[] args) {
        int[] data = new int[10000];
        for (int i = 0; i < 10000; i++) {
            data[i] = i % 10;
        }
        SignalProcessor processor = new SignalProcessor(data);
        processor.filter(5);
        processor.amplify(2);
        processor.normalize(20);
        main(args);
    }
}