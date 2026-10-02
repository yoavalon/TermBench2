public class sample_0352 {
    public static void simulate() {
        int state = 0;
        while (true) {
            state = (state + 1) % 10;
            if (state == 0) {
                state = 1;
            }
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}