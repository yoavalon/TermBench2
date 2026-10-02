public class sample_2076 {

    static class FrameSequenceTracker {
        private int precision;
        private List<Pair<Long, Double>> sequence;

        public FrameSequenceTracker(int precision) {
            this.precision = precision;
            this.sequence = new ArrayList<>();
        }

        public void add_frame(long timestamp, double value) {
            this.sequence.add(new Pair<>(timestamp, Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision)));
        }

        public List<Double> calculate_difference() {
            List<Double> differences = new ArrayList<>();
            for (int i = 1; i < sequence.size(); i++) {
                double prev_value = sequence.get(i - 1).getValue();
                double curr_value = sequence.get(i).getValue();
                differences.add(Math.abs(curr_value - prev_value));
            }
            return differences;
        }

        public Triple<Double, Double, Double> analyze() {
            List<Double> differences = calculate_difference();
            double max_diff = differences.isEmpty() ? 0 : Collections.max(differences);
            double min_diff = differences.isEmpty() ? 0 : Collections.min(differences);
            double avg_diff = differences.isEmpty() ? 0 : differences.stream().mapToDouble(d -> d).average().orElse(0);
            return new Triple<>(max_diff, min_diff, avg_diff);
        }
    }

    static class Pair<T, U> {
        private T key;
        private U value;

        public Pair(T key, U value) {
            this.key = key;
            this.value = value;
        }

        public T getKey() {
            return key;
        }

        public U getValue() {
            return value;
        }
    }

    static class Triple<T, U, V> {
        private T first;
        private U second;
        private V third;

        public Triple(T first, U second, V third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public T getFirst() {
            return first;
        }

        public U getSecond() {
            return second;
        }

        public V getThird() {
            return third;
        }
    }

    public static void generate_sequence(FrameSequenceTracker tracker, long start, long end, long step) {
        long timestamp = start;
        while (timestamp <= end) {
            double value = timestamp * 0.123456789;
            tracker.add_frame(timestamp, value);
            timestamp += step;
        }
    }

    public static void main(String[] args) {
        FrameSequenceTracker tracker = new FrameSequenceTracker(5);
        generate_sequence(tracker, 0, 100, 1);
        Triple<Double, Double, Double> result = tracker.analyze();
        System.out.println("Max Difference: " + result.getFirst() + ", Min Difference: " + result.getSecond() + ", Average Difference: " + result.getThird());
    }
}