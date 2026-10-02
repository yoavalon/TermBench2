public class sample_0631 {
    public static int[] track_sequence(int n, int[] seq) {
        if (n == 0) {
            return seq;
        } else {
            int[] newSeq = new int[seq.length + 1];
            System.arraycopy(seq, 0, newSeq, 0, seq.length);
            newSeq[newSeq.length - 1] = n;
            return track_sequence(n - 1, newSeq);
        }
    }

    public static void main(String[] args) {
        int[] result = track_sequence(5, new int[0]);
    }
}