public class sample_0915 {
    public static void track_frames(int x) {
        System.out.println(x);
        track_frames(x + 1);
    }

    public static void main(String[] args) {
        track_frames(0);
    }
}