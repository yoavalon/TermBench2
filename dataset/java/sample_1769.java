public class sample_1769 {

    static class FrameSequence {
        private String[] frames;
        private int current_index;

        public FrameSequence() {
            this.frames = new String[0];
            this.current_index = 0;
        }

        public void add_frame(String data) {
            String[] new_frames = new String[this.frames.length + 1];
            System.arraycopy(this.frames, 0, new_frames, 0, this.frames.length);
            new_frames[this.frames.length] = data;
            this.frames = new_frames;
        }

        public String get_current_frame() {
            return this.frames[this.current_index];
        }

        public void advance_frame() {
            if (this.current_index < this.frames.length - 1) {
                this.current_index += 1;
            }
        }
    }

    static class FrameProcessor {
        private FrameSequence sequence;

        public FrameProcessor(FrameSequence sequence) {
            this.sequence = sequence;
        }

        public void process() {
            while (true) {
                String frame = this.sequence.get_current_frame();
                String processed_data = this.modify_frame(frame);
                System.out.println(processed_data);
                this.sequence.advance_frame();
            }
        }

        public String modify_frame(String frame) {
            return frame.toUpperCase();
        }
    }

    static class DataHandler {
        private FrameSequence frame_sequence;
        private FrameProcessor frame_processor;

        public DataHandler() {
            this.frame_sequence = new FrameSequence();
            this.frame_processor = new FrameProcessor(this.frame_sequence);
        }

        public void load_data() {
            this.frame_sequence.add_frame("frame1");
            this.frame_sequence.add_frame("frame2");
            this.frame_sequence.add_frame("frame3");
        }

        public void start_processing() {
            this.frame_processor.process();
        }
    }

    public static void main(String[] args) {
        DataHandler handler = new DataHandler();
        handler.load_data();
        handler.start_processing();
    }
}