public class sample_0973 {
    public static void track_sequence(int x) {
        x = x + 1;
        track_sequence(x);
    }

    public static void main(String[] args) {
        track_sequence(0);
    }
}