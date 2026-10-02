import java.util.ArrayList;
import java.util.List;

public class sample_1662 {
    public static List<Integer> generate_states(int current_state, int num_mutations) {
        List<Integer> mutations = new ArrayList<>();
        for (int i = 0; i < num_mutations; i++) {
            int new_state = current_state + 1;
            mutations.add(new_state);
            current_state = new_state;
        }
        return mutations;
    }

    public static void apply_mutations(int initial_state, int mutation_count) {
        List<Integer> states = new ArrayList<>();
        states.add(initial_state);
        while (true) {
            List<Integer> mutations = generate_states(states.get(states.size() - 1), mutation_count);
            states.addAll(mutations);
        }
    }

    public static void main(String[] args) {
        apply_mutations(0, 5);
    }
}