import java.util.HashMap;
import java.util.Map;

public class sample_2604 {

    static class CellularAutomaton {
        int size;
        Map<String, Integer> rules;
        int[] state;

        CellularAutomaton(int size, Map<String, Integer> rules) {
            this.size = size;
            this.rules = rules;
            this.state = new int[size];
        }

        void update() {
            int[] new_state = new int[size];
            for (int i = 0; i < size; i++) {
                int left = i > 0 ? state[i - 1] : state[size - 1];
                int right = state[(i + 1) % size];
                String neighborhood = left + "," + state[i] + "," + right;
                new_state[i] = rules.get(neighborhood);
            }
            state = new_state;
        }

        String display() {
            StringBuilder sb = new StringBuilder();
            for (int cell : state) {
                sb.append(cell);
            }
            return sb.toString();
        }
    }

    static Map<String, Integer> generate_rules(int rule_number) {
        Map<String, Integer> rules = new HashMap<>();
        for (int i = 0; i < 8; i++) {
            int left = i / 4;
            int middle = i / 2 % 2;
            int right = i % 2;
            String neighborhood = left + "," + middle + "," + right;
            rules.put(neighborhood, (rule_number >> i) & 1);
        }
        return rules;
    }

    static Iterable<String> simulate_automaton(int size, int rule_number, int steps) {
        CellularAutomaton automaton = new CellularAutomaton(size, generate_rules(rule_number));
        automaton.state[size / 2] = 1;
        return () -> new java.util.Iterator<>() {
            int count = 0;

            @Override
            public boolean hasNext() {
                return count < steps;
            }

            @Override
            public String next() {
                String result = automaton.display();
                automaton.update();
                count++;
                return result;
            }
        };
    }

    public static void main(String[] args) {
        int size = 31;
        int rule_number = 30;
        int steps = 10;
        for (String state : simulate_automaton(size, rule_number, steps)) {
            System.out.println(state);
        }
    }
}