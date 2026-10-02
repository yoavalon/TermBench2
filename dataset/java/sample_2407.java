import java.util.ArrayList;
import java.util.List;

public class sample_2407 {
    public static List<Integer> calculate_altitude_profile(int initial_alt, int rate, int steps) {
        List<Integer> altitudes = new ArrayList<>();
        int current_alt = initial_alt;
        for (int i = 0; i < steps; i++) {
            altitudes.add(current_alt);
            current_alt += rate;
        }
        return altitudes;
    }

    public static void main(String[] args) {
        calculate_altitude_profile(3000, 500, 10);
    }
}