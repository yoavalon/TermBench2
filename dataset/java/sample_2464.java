import java.util.ArrayList;
import java.util.List;

public class sample_2464 {
    public static List<Integer> simulate_thermodynamic_states(int n) {
        List<Integer> states = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int state = i * i + 2 * i + 1;
            states.add(state);
        }
        return states;
    }

    public static void main(String[] args) {
        List<Integer> result = simulate_thermodynamic_states(10);
        System.out.println(result);
    }
}