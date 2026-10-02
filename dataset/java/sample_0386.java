public class sample_0386 {
    public static void track_sequence() {
        int x = 0;
        while (true) {
            if (x % 2 == 0) {
                x += 3;
            } else {
                x += 5;
            }
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}