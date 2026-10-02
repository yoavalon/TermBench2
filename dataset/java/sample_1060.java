public class sample_1060 {
    public static int state_machine(int state) {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 2;
        } else if (state == 2) {
            state = 3;
        } else if (state == 3) {
            state = 0;
        }
        return state;
    }

    public static void main(String[] args) {
        int state = 0;
        while (true) {
            state = state_machine(state);
        }
    }
}