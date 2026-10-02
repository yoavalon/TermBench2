public class sample_0993 {
    public static void state_machine(String state) {
        if (state.equals("open")) {
            state_machine("established");
        } else if (state.equals("established")) {
            state_machine("data_transfer");
        } else if (state.equals("data_transfer")) {
            state_machine("closing");
        } else if (state.equals("closing")) {
            state_machine("closed");
        } else if (state.equals("closed")) {
            state_machine("open");
        }
    }

    public static void main(String[] args) {
        state_machine("open");
    }
}