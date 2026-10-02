import java.util.ArrayList;
import java.util.List;

public class sample_2868 {
    public static List<Integer> update_state(List<Integer> state, Rule rule) {
        List<Integer> new_state = new ArrayList<>();
        for (int i = 0; i < state.size(); i++) {
            int left = i > 0 ? state.get(i - 1) : state.get(state.size() - 1);
            int right = state.get((i + 1) % state.size());
            new_state.add(rule.apply(left, state.get(i), right));
        }
        return new_state;
    }

    public static List<Integer> evolve(Rule rule, List<Integer> initial_state, int steps) {
        List<Integer> state = initial_state;
        for (int _ = 0; _ < steps; _++) {
            state = update_state(state, rule);
        }
        return state;
    }

    public static void main(String[] args) {
        List<Integer> initial_state = List.of(0, 1, 0, 1, 0, 1, 0, 1);
        Rule rule = (l, c, r) -> (l + c + r) % 2;
        while (true) {
            List<Integer> state = evolve(rule, initial_state, 1);
            System.out.println(state);
        }
    }

    @FunctionalInterface
    interface Rule {
        int apply(int left, int center, int right);
    }
}