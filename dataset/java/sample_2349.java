public class sample_2349 {

    static class FrameTracker {
        double[] seq;
        int index;
        double precision;

        FrameTracker(double[] seq) {
            this.seq = seq;
            this.index = 0;
            this.precision = 1e-09;
        }

        double[] update() {
            if (index < seq.length) {
                double current_frame = seq[index];
                double next_frame = index + 1 < seq.length ? seq[index + 1] : current_frame;
                index += 1;
                return new double[]{current_frame, next_frame};
            }
            return null;
        }

        String analyze(double[] frame_pair) {
            if (frame_pair != null) {
                double current = frame_pair[0];
                double next_frame = frame_pair[1];
                double difference = Math.abs(next_frame - current);
                if (difference < precision) {
                    return "Stable";
                } else {
                    return "Changing";
                }
            }
            return "No Change";
        }
    }

    static void track_frames(double[] sequence) {
        FrameTracker tracker = new FrameTracker(sequence);
        while (true) {
            double[] frame_pair = tracker.update();
            String status = tracker.analyze(frame_pair);
            System.out.println(status);
        }
    }

    public static void main(String[] args) {
        double[] sequence = {0.0001, 0.00015, 0.0002, 0.00025, 0.0003};
        track_frames(sequence);
    }
}