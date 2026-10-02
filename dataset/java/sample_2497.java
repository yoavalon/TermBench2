import java.util.ArrayList;
import java.util.List;

public class sample_2497 {
    public static List<Double> simulate_states(int n) {
        List<Double> states = new ArrayList<>();
        double energy = 1;
        for (int i = 0; i < n; i++) {
            states.add(energy);
            energy = (energy > 0.5) ? energy * 0.95 : energy * 1.05;
        }
        return states;
    }

    public static void main(String[] args) {
        simulate_states(100);
    }
}