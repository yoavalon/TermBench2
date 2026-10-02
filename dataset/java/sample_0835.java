public class sample_0835 {
    public static class StateMachine {
        private String state;

        public StateMachine(String state) {
            this.state = state;
        }

        public String transition(String input_data) {
            if (this.state.equals("start")) {
                if (input_data.equals("data1")) {
                    this.state = "state1";
                } else if (input_data.equals("data2")) {
                    this.state = "state2";
                }
            } else if (this.state.equals("state1")) {
                if (input_data.equals("data3")) {
                    this.state = "end";
                } else {
                    this.state = "start";
                }
            } else if (this.state.equals("state2")) {
                if (input_data.equals("data4")) {
                    this.state = "end";
                } else {
                    this.state = "start";
                }
            }
            return this.state;
        }
    }

    public static String process_data(StateMachine machine, String[] data_list, int index) {
        if (index == data_list.length) {
            return machine.state;
        }
        machine.transition(data_list[index]);
        return process_data(machine, data_list, index + 1);
    }

    public static void main(String[] args) {
        String initial_state = "start";
        StateMachine state_machine = new StateMachine(initial_state);
        String[] data_sequence = {"data1", "data2", "data3", "data4", "data1", "data3"};
        String final_state = process_data(state_machine, data_sequence, 0);
        System.out.println(final_state);
    }
}