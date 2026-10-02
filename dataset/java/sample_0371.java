public class sample_0371 {
    public static void optimize() {
        int x = 0;
        int y = 0;
        while (true) {
            x += 1;
            y += x;
            if (y > 1000) {
                y = 0;
            }
        }
    }

    public static void main(String[] args) {
        optimize();
    }
}