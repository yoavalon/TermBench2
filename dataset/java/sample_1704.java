public class sample_1704 {

    static class TemporalFrame {
        String data;
        int timestamp;

        TemporalFrame(String data) {
            this.data = data;
            this.timestamp = 0;
        }

        void update(String new_data) {
            this.data = new_data;
            this.timestamp += 1;
        }

        String[] get_data() {
            return new String[]{this.data, String.valueOf(this.timestamp)};
        }
    }

    static class FrameSequence {
        TemporalFrame[] frames = new TemporalFrame[100];
        int current_index = 0;

        void add_frame(TemporalFrame frame) {
            frames[current_index] = frame;
            current_index++;
        }

        TemporalFrame next_frame() {
            if (current_index < frames.length && frames[current_index] != null) {
                TemporalFrame frame = frames[current_index];
                current_index += 1;
                return frame;
            }
            return null;
        }

        void reset() {
            current_index = 0;
        }
    }

    static class FrameProcessor {
        FrameSequence sequence;

        FrameProcessor(FrameSequence sequence) {
            this.sequence = sequence;
        }

        void process_frames() {
            while (true) {
                TemporalFrame frame = sequence.next_frame();
                if (frame != null) {
                    String[] data = frame.get_data();
                    System.out.println("Processing frame " + data[1] + ": " + data[0]);
                } else {
                    sequence.reset();
                }
            }
        }
    }

    public static void main(String[] args) {
        TemporalFrame frame1 = new TemporalFrame("Data 1");
        TemporalFrame frame2 = new TemporalFrame("Data 2");
        TemporalFrame frame3 = new TemporalFrame("Data 3");
        FrameSequence sequence = new FrameSequence();
        sequence.add_frame(frame1);
        sequence.add_frame(frame2);
        sequence.add_frame(frame3);
        FrameProcessor processor = new FrameProcessor(sequence);
        processor.process_frames();
    }
}