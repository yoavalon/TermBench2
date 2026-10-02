import java.util.ArrayList;
import java.util.List;

public class sample_2574 {
    public static List<Integer> update_state(List<Integer> state, Rule rule) {
        List<Integer> new_state = new ArrayList<>();
        for (int i = 0; i < state.size(); i++) {
            int left = i > 0 ? state.get(i - 1) : state.get(state.size() - 1);
            int right = state.get((i + 1) % state.size());
            new_state.add(rule.apply(left, state.get(i), right));
        }
        return new_state;
    }

    public static List<Integer> cellular_automaton(int steps, List<Integer> initial, Rule rule) {
        List<Integer> state = initial;
        for (int _ = 0; _ < steps; _++) {
            state = update_state(state, rule);
        }
        return state;
    }

    @FunctionalInterface
    interface Rule {
        int apply(int left, int center, int right);
    }

    public static int rule_conway(int left, int center, int right) {
        int count = left + center + right;
        return count == 3 ? 1 : count == 2 ? 0 : center;
    }

    public static void main(String[] args) {
        List<Integer> initial_state = List.of(0, 1, 0, 1, 0, 1, 0, 1, 0, 1);
        int steps = 5;
        List<Integer> final_state = cellular_automaton(steps, initial_state, sample_2574::rule_conway);
        System.out.println(final_state);
    }
}