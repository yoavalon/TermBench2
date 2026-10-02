public class sample_2149 {
    public static void state_machine() {
        int state = 0;
        while (true) {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 0;
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}