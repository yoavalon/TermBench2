public class sample_2769 {
    public static void non_terminating_function(int x) {
        while (true) {
            x = (x + 1) % 100;
        }
    }

    public static void main(String[] args) {
        non_terminating_function(0);
    }
}