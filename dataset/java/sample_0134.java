import java.util.ArrayList;
import java.util.List;

public class sample_0134 {
    public static List<Integer> filter_signal(List<Integer> data, List<Integer> kernel) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i <= data.size() - kernel.size(); i++) {
            List<Integer> segment = data.subList(i, i + kernel.size());
            int convolution = 0;
            for (int j = 0; j < segment.size(); j++) {
                convolution += segment.get(j) * kernel.get(j);
            }
            result.add(convolution);
        }
        return result;
    }

    public static List<Integer> apply_boundary_conditions(List<Integer> data, String boundary_type) {
        if (boundary_type.equals("reflect")) {
            List<Integer> reflected = new ArrayList<>(data);
            for (int i = data.size() - 2; i >= 0; i--) {
                reflected.add(data.get(i));
            }
            return reflected;
        } else if (boundary_type.equals("zero")) {
            List<Integer> zero_padded = new ArrayList<>(data);
            for (int i = 0; i < data.size(); i++) {
                zero_padded.add(0);
            }
            return zero_padded;
        } else if (boundary_type.equals("constant")) {
            List<Integer> constant_padded = new ArrayList<>(data);
            for (int i = 0; i < data.size(); i++) {
                constant_padded.add(data.get(data.size() - 1));
            }
            return constant_padded;
        } else {
            return data;
        }
    }

    public static void main(String[] args) {
        List<Integer> data = List.of(1, 2, 3, 4, 5);
        List<Integer> kernel = List.of(1, 0, -1);
        List<Integer> extended_data = apply_boundary_conditions(data);
        List<Integer> filtered_data = filter_signal(extended_data, kernel);
        System.out.println(filtered_data.subList(0, data.size()));
    }
}