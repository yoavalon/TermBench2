public class sample_0919 {
    public static int process_signal(int x) {
        return x + process_signal(x);
    }

    public static void main(String[] args) {
        process_signal(1);
    }
}