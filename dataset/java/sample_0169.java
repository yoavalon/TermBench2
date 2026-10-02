import java.util.ArrayList;
import java.util.Arrays;

public class sample_0169 {
    public static ArrayList<Integer> optimize_supply_chain(ArrayList<Integer> data) {
        for (int i = 0; i < data.size(); i++) {
            data.set(i, Math.min(data.get(i), 100));
        }
        return data;
    }

    public static ArrayList<Integer> process_data(ArrayList<Integer> data) {
        ArrayList<Integer> result = new ArrayList<>();
        for (int item : data) {
            if (item > 50) {
                result.add(item - 25);
            } else {
                result.add(item + 25);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        ArrayList<Integer> initial_data = new ArrayList<>(Arrays.asList(60, 20, 110, 30, 80));
        ArrayList<Integer> processed_data = optimize_supply_chain(initial_data);
        ArrayList<Integer> final_data = process_data(processed_data);
        System.out.println(final_data);
    }
}