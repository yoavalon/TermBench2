import java.util.Iterator;
import java.util.List;

public class sample_0474 {

    static Iterator<Integer> state_machine(List<String> data) {
        int state = 0;
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public Integer next() {
                if (state == 0) {
                    state = data.contains("SYN") ? 1 : state;
                } else if (state == 1) {
                    state = data.contains("ACK") ? 2 : state;
                } else if (state == 2) {
                    state = data.contains("SYN") ? 3 : state;
                } else if (state == 3) {
                    state = data.contains("ACK") ? 4 : state;
                }
                return state;
            }
        };
    }

    static void process_data() {
        List<String> data_stream = List.of("SYN", "ACK", "SYN", "ACK", "DATA", "ACK", "FIN", "ACK");
        Iterator<Integer> machine = state_machine(data_stream);
        while (machine.hasNext()) {
            int state = machine.next();
            System.out.println("Current State: " + state);
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}