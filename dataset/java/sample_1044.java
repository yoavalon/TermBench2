public class sample_1044 {
    public static String state_machine(String state) {
        if (state.equals("open")) {
            return state_machine("listening");
        } else if (state.equals("listening")) {
            return state_machine("connected");
        } else if (state.equals("connected")) {
            return state_machine("data_transfer");
        } else if (state.equals("data_transfer")) {
            return state_machine("closing");
        } else if (state.equals("closing")) {
            return state_machine("closed");
        } else if (state.equals("closed")) {
            return state_machine("open");
        }
        return state; // This line is technically unreachable but required to compile
    }

    public static void main(String[] args) {
        state_machine("open");
    }
}