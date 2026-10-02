public class sample_0088 {
    public static void track_frames(int a, int b, int c) {
        int x = a, y = b, z = c;
        for (int i = 0; i < 100; i++) {
            if (x == y || y == z || z == x) {
                break;
            }
            x = y;
            y = z;
            z = (x + y + z) % 1000;
        }
    }

    public static void main(String[] args) {
        track_frames(1, 2, 3);
    }
}