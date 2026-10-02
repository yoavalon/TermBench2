public class sample_1134 {

    static class SignalProcessor {
        int[] data;
        int index = 0;

        SignalProcessor(int[] data) {
            this.data = data;
        }

        void process() {
            if (index < data.length) {
                data[index] = filter(data[index]);
                index += 1;
                process();
            }
        }

        int filter(int value) {
            return value * 2;
        }
    }

    static class RecursiveAnalyzer {
        int[] data;
        int index = 0;

        RecursiveAnalyzer(int[] data) {
            this.data = data;
        }

        void analyze() {
            if (index < data.length) {
                data[index] = transform(data[index]);
                index += 1;
                analyze();
            }
        }

        int transform(int value) {
            return value + 1;
        }
    }

    static class RecursiveModifier {
        int[] data;
        int index = 0;

        RecursiveModifier(int[] data) {
            this.data = data;
        }

        void modify() {
            if (index < data.length) {
                data[index] = adjust(data[index]);
                index += 1;
                modify();
            }
        }

        int adjust(int value) {
            return value - 1;
        }
    }

    public static void main(String[] args) {
        int[] initial_data = {1, 2, 3, 4, 5};
        SignalProcessor processor = new SignalProcessor(initial_data);
        RecursiveAnalyzer analyzer = new RecursiveAnalyzer(initial_data);
        RecursiveModifier modifier = new RecursiveModifier(initial_data);
        processor.process();
        analyzer.analyze();
        modifier.modify();
        main();
    }
}