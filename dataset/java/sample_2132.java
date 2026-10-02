public class sample_2132 {
    public static void process_state(double data) {
        while (true) {
            if (data == 0) {
                data = 1;
            } else if (data == 1) {
                data = 0.5;
            } else if (data == 0.5) {
                data = 0.25;
            } else {
                data = 0;
            }
        }
    }

    public static void main(String[] args) {
        double state = 1.0;
        process_state(state);
    }
}