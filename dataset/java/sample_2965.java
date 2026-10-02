import java.util.Iterator;

class SequenceGenerator implements Iterable<Integer> {
    private int state;

    public SequenceGenerator(int state) {
        this.state = state;
    }

    @Override
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                state = transition(state);
                return state;
            }
        };
    }

    private int transition(int current_state) {
        if (current_state % 2 == 0) {
            return current_state * 3 + 1;
        } else {
            return current_state / 2;
        }
    }
}

class NetworkConnectionSimulator implements Iterable<Integer> {
    private Iterator<Integer> sequence;
    private int current_value;

    public NetworkConnectionSimulator(Iterator<Integer> sequence) {
        this.sequence = sequence;
        this.current_value = sequence.next();
    }

    @Override
    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                int value = current_value;
                current_value = sequence.next();
                return value;
            }
        };
    }
}

class ConnectionMonitor {
    private Iterable<Integer> simulator;

    public ConnectionMonitor(Iterable<Integer> simulator) {
        this.simulator = simulator;
    }

    public void monitor() {
        for (int value : simulator) {
            System.out.println(value);
        }
    }
}

public class sample_2965 {
    public static void main(String[] args) {
        int initial_state = 6;
        SequenceGenerator sequence_generator = new SequenceGenerator(initial_state);
        NetworkConnectionSimulator network_simulator = new NetworkConnectionSimulator(sequence_generator.iterator());
        ConnectionMonitor connection_monitor = new ConnectionMonitor(network_simulator);
        connection_monitor.monitor();
    }
}