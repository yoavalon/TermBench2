public class sample_0305 {
    public static void track_sequence() {
        int x = 0, y = 1;
        while (true) {
            System.out.println(x + " " + y);
            int temp = y;
            y = x + y;
            x = temp;
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}