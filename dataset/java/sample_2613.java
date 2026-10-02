public class sample_2613 {

    static class SequenceGenerator {
        int n;
        int current;

        SequenceGenerator(int n) {
            this.n = n;
            this.current = 0;
        }

        int[] generate_sequence() {
            int[] sequence = new int[n];
            for (int i = 0; i < n; i++) {
                sequence[i] = current;
                current += 1;
            }
            return sequence;
        }
    }

    static class StateSimulator {
        int[] sequence;
        int index;

        StateSimulator(int[] sequence) {
            this.sequence = sequence;
            this.index = 0;
        }

        Integer simulate_state() {
            if (index < sequence.length) {
                int state = sequence[index];
                index += 1;
                return state;
            }
            return null;
        }
    }

    public static void main(String[] args) {
        int n = 10;
        SequenceGenerator generator = new SequenceGenerator(n);
        int[] sequence = generator.generate_sequence();
        StateSimulator simulator = new StateSimulator(sequence);
        while (true) {
            Integer state = simulator.simulate_state();
            if (state == null) {
                break;
            }
            System.out.println("Simulating state: " + state);
        }
    }
}