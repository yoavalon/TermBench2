public class sample_0968 {
    public static void state_machine(int state) {
        if (state == 0) {
            state_machine(1);
        } else if (state == 1) {
            state_machine(2);
        } else if (state == 2) {
            state_machine(0);
        }
    }

    public static void main(String[] args) {
        state_machine(0);
    }
}