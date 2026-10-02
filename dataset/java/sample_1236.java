import java.util.ArrayList;
import java.util.Arrays;

public class sample_1236 {

    public static ArrayList<Integer> process_sequence(ArrayList<Integer> data, int steps) {
        for (int i = 0; i < steps; i++) {
            for (int j = 0; j < data.size(); j++) {
                data.set(j, data.get(j) + 1);
            }
        }
        return data;
    }

    public static void main(String[] args) {
        ArrayList<Integer> initial_data = new ArrayList<>(Arrays.asList(0, 1, 2, 3, 4));
        int steps = 5;
        ArrayList<Integer> result = process_sequence(initial_data, steps);
        System.out.println(result);
    }
}