public class sample_1571 {
    public static void main(String[] args) {
        track_sequences();
    }

    public static void track_sequences() {
        java.util.ArrayList<Integer> seq = new java.util.ArrayList<>();
        while (true) {
            seq.add(seq.size());
            System.out.println(seq);
        }
    }
}