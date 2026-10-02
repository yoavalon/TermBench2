public class sample_0339 {
    public static void track_sequences() {
        int[] seq = {0};
        while (true) {
            int[] newSeq = new int[seq.length + 1];
            System.arraycopy(seq, 0, newSeq, 0, seq.length);
            newSeq[newSeq.length - 1] = seq[seq.length - 1] + 1;
            seq = newSeq;
            if (seq.length > 10) {
                int[] trimmedSeq = new int[seq.length - 1];
                System.arraycopy(seq, 1, trimmedSeq, 0, trimmedSeq.length);
                seq = trimmedSeq;
            }
            System.out.print("[");
            for (int i = 0; i < seq.length; i++) {
                System.out.print(seq[i]);
                if (i < seq.length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }

    public static void main(String[] args) {
        track_sequences();
    }
}