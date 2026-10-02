import java.util.HashMap;
import java.util.Map;

public class sample_2658 {

    static class Automaton {
        int size;
        Map<String, Integer> rule;
        int[] state;

        Automaton(int size, Map<String, Integer> rule) {
            this.size = size;
            this.rule = rule;
            this.state = new int[size];
            this.state[size / 2] = 1;
        }

        void evolve() {
            int[] new_state = new int[size];
            for (int i = 1; i < size - 1; i++) {
                String pattern = (state[i - 1] + "," + state[i] + "," + state[i + 1]);
                new_state[i] = rule.get(pattern);
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

    static Map<String, Integer> generate_rule(int number) {
        Map<String, Integer> rule = new HashMap<>();
        for (int i = 0; i < 8; i++) {
            String pattern = ((i / 4) + "," + (i / 2 % 2) + "," + (i % 2));
            rule.put(pattern, (number >> i) & 1);
        }
        return rule;
    }

    public static void main(String[] args) {
        int size = 31;
        int rule_number = 30;
        Map<String, Integer> rule = generate_rule(rule_number);
        Automaton automaton = new Automaton(size, rule);
        int iterations = 10;
        for (int _ = 0; _ < iterations; _++) {
            System.out.println(automaton.display());
            automaton.evolve();
        }
    }
}