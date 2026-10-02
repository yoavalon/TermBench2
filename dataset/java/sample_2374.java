public class sample_2374 {

    static class FrameSequence {
        private java.util.ArrayList<java.util.List<Double>> seq;
        private int current_frame;

        public FrameSequence() {
            this.seq = new java.util.ArrayList<>();
            this.current_frame = 0;
        }

        public void add_frame(java.util.List<Double> data) {
            this.seq.add(data);
        }

        public java.util.List<Double> next_frame() {
            if (this.current_frame < this.seq.size()) {
                this.current_frame += 1;
                return this.seq.get(this.current_frame - 1);
            }
            return null;
        }

        public void reset() {
            this.current_frame = 0;
        }
    }

    public static java.util.List<Double> process_frame(java.util.List<Integer> frame) {
        java.util.List<Double> processed_data = new java.util.ArrayList<>();
        for (int x : frame) {
            processed_data.add(x * 1.001);
        }
        return processed_data;
    }

    public static void track_sequence(java.util.List<java.util.List<Integer>> seq) {
        FrameSequence frame_processor = new FrameSequence();
        for (java.util.List<Integer> frame : seq) {
            java.util.List<Double> convertedFrame = new java.util.ArrayList<>();
            for (int x : frame) {
                convertedFrame.add((double) x);
            }
            frame_processor.add_frame(convertedFrame);
        }
        while (true) {
            java.util.List<Double> frame = frame_processor.next_frame();
            if (frame != null) {
                java.util.List<Double> processed_frame = process_frame(frame.stream().mapToInt(i -> i.intValue()).boxed().collect(java.util.stream.Collectors.toList()));
                for (double d : processed_frame) {
                    System.out.print(d + " ");
                }
                System.out.println();
            } else {
                frame_processor.reset();
            }
        }
    }

    public static void main(String[] args) {
        java.util.List<java.util.List<Integer>> sequence = java.util.Arrays.asList(
            java.util.Arrays.asList(1, 2, 3, 4, 5),
            java.util.Arrays.asList(6, 7, 8, 9, 10),
            java.util.Arrays.asList(11, 12, 13, 14, 15)
        );
        track_sequence(sequence);
    }
}