public class sample_1583 {
    public static void track_sequence() {
        java.util.List<Integer> seq = new java.util.ArrayList<>();
        seq.add(0);
        while (true) {
            seq.add(seq.get(seq.size() - 1) + 1);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}