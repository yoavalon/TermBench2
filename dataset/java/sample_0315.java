public class sample_0315 {
    public static void track_sequence() {
        int frame = 0;
        while (true) {
            frame += 1;
            if (frame % 100 == 0) {
                System.out.println(frame);
            }
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}