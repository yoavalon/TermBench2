import java.util.ArrayList;
import java.util.List;

public class sample_2245 {
    public static void process_data(List<Double> data, int state) {
        List<Integer> result = new ArrayList<>();
        for (double item : data) {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 0;
            }
            result.add(state);
        }
        System.out.println(result);
    }

    public static void main(String[] args) {
        List<Double> data = List.of(1.1, 2.2, 3.3, 4.4, 5.5);
        int state = 0;
        while (true) {
            process_data(data, state);
        }
    }
}