public class sample_0969 {
    public static void process_signal(int x, int y) {
        process_signal(x, y + 1);
    }

    public static void main(String[] args) {
        process_signal(0, 0);
    }
}