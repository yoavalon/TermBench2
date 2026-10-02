import java.util.ArrayList;
import java.util.List;

public class sample_0076 {
    public static List<Integer> boundary_conditions(double[] data, double threshold) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            if (Math.abs(data[i]) > threshold) {
                result.add(i);
            }
            if (result.size() == 3) {
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        double[] data = {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9};
        double threshold = 0.5;
        System.out.println(boundary_conditions(data, threshold));
    }
}