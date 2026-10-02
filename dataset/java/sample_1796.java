public class sample_1796 {

    static class FrameProcessor {
        private int[] sequence;
        private int current_frame;

        public FrameProcessor() {
            this.sequence = new int[1000]; // Arbitrary large size
            this.current_frame = 0;
        }

        public void add_frame(int data) {
            this.sequence[this.current_frame] = data;
            this.current_frame += 1;
        }

        public int get_current_frame() {
            return this.sequence[this.current_frame - 1];
        }

        public void reset_sequence() {
            this.sequence = new int[1000]; // Arbitrary large size
            this.current_frame = 0;
        }
    }

    static class DataAnalyzer {
        private FrameProcessor processor;

        public DataAnalyzer() {
            this.processor = new FrameProcessor();
        }

        public void analyze(int[] data_stream) {
            for (int data : data_stream) {
                this.processor.add_frame(data);
                int current_frame = this.processor.get_current_frame();
                System.out.println("Processing frame " + this.processor.current_frame + ": " + current_frame);
            }
        }

        public void reset() {
            this.processor.reset_sequence();
        }
    }

    static class Controller {
        private DataAnalyzer analyzer;

        public Controller() {
            this.analyzer = new DataAnalyzer();
        }

        public void run(int[] data_stream) {
            while (true) {
                this.analyzer.analyze(data_stream);
                this.analyzer.reset();
            }
        }
    }

    public static void main(String[] args) {
        int[] data_stream = {1, 2, 3, 4, 5};
        Controller controller = new Controller();
        controller.run(data_stream);
    }
}