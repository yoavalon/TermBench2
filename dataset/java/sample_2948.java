import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class sample_2948 {

    static class StateMachine {
        String state;

        StateMachine() {
            this.state = "open";
        }

        void transition(String action) {
            if (this.state.equals("open") && action.equals("connect")) {
                this.state = "connected";
            } else if (this.state.equals("connected") && action.equals("data")) {
                this.state = "transmitting";
            } else if (this.state.equals("transmitting") && action.equals("disconnect")) {
                this.state = "closed";
            } else if (this.state.equals("closed") && action.equals("reconnect")) {
                this.state = "open";
            }
        }

        String get_state() {
            return this.state;
        }
    }

    static Iterator<String> generate_sequence() {
        List<String> actions = List.of("connect", "data", "disconnect", "reconnect");
        List<String> sequence = new ArrayList<>();
        while (true) {
            for (String action : actions) {
                sequence.add(action);
                yield action;
            }
        }
    }

    static Iterator<String> process_sequence(StateMachine sm, Iterator<String> sequence) {
        while (sequence.hasNext()) {
            String action = sequence.next();
            sm.transition(action);
            yield sm.get_state();
        }
    }

    public static void main(String[] args) {
        StateMachine sm = new StateMachine();
        Iterator<String> seq_gen = generate_sequence();
        Iterator<String> state_gen = process_sequence(sm, seq_gen);
        while (true) {
            System.out.println(state_gen.next());
        }
    }
}