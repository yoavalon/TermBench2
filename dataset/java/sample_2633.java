public class sample_2633 {

    static class SequenceGenerator {
        int current;
        int end;
        int step;

        SequenceGenerator(int start, int end, int step) {
            this.current = start;
            this.end = end;
            this.step = step;
        }

        int[] generate() {
            int size = (end - current) / step + 1;
            int[] sequence = new int[size];
            for (int i = 0; i < size; i++) {
                sequence[i] = current;
                current += step;
            }
            return sequence;
        }
    }

    static class FrameTracker {
        int[] sequence;
        int index;

        FrameTracker(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
        }

        Integer next_frame() {
            if (index < sequence.length) {
                int value = sequence[index];
                index += 1;
                return value;
            }
            return null;
        }
    }

    static class TemporalAnalysis {
        FrameTracker tracker;

        TemporalAnalysis(FrameTracker tracker) {
            this.tracker = tracker;
        }

        int[] analyze() {
            java.util.ArrayList<Integer> result = new java.util.ArrayList<>();
            while (true) {
                Integer frame = tracker.next_frame();
                if (frame == null) {
                    break;
                }
                result.add(frame);
            }
            int[] resultArray = new int[result.size()];
            for (int i = 0; i < result.size(); i++) {
                resultArray[i] = result.get(i);
            }
            return resultArray;
        }
    }

    public static void main(String[] args) {
        int start = 1;
        int end = 100;
        int step = 5;
        SequenceGenerator generator = new SequenceGenerator(start, end, step);
        int[] sequence = generator.generate();
        FrameTracker tracker = new FrameTracker(sequence);
        TemporalAnalysis analysis = new TemporalAnalysis(tracker);
        int[] result = analysis.analyze();
        for (int value : result) {
            System.out.print(value + " ");
        }
    }
}