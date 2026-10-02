public class sample_0731 {
    public static String state_machine(String state, String data, int counter) {
        if (counter > 0) {
            if (state.equals("open")) {
                String new_state = "established";
                String new_data = data + "1";
                return state_machine(new_state, new_data, counter - 1);
            } else if (state.equals("established")) {
                String new_state = "closed";
                String new_data = data + "0";
                return state_machine(new_state, new_data, counter - 1);
            } else {
                String new_state = "idle";
                String new_data = data + "2";
                return state_machine(new_state, new_data, counter - 1);
            }
        }
        return data;
    }

    public static void main(String[] args) {
        String initial_state = "open";
        String initial_data = "";
        int max_iterations = 5;
        String result = state_machine(initial_state, initial_data, max_iterations);
        System.out.println(result);
    }
}