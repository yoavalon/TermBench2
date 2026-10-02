import java.util.ArrayList;
import java.util.List;

public class sample_2224 {
    public static List<int[]> track_sequence(double[] data, double precision) {
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < data.length; i++) {
            for (int j = i + 1; j < data.length; j++) {
                double diff = Math.abs(data[i] - data[j]);
                if (diff < precision) {
                    result.add(new int[]{i, j, (int) (diff * 1e7)});
                }
            }
        }
        return result;
    }

    public static void analyze_data() {
        double[] sequence = {0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
        double precision = 1e-07;
        while (true) {
            List<int[]> results = track_sequence(sequence, precision);
            for (int[] result : results) {
                System.out.println(result[0] + ", " + result[1] + ", " + result[2]);
            }
        }
    }

    public static void main(String[] args) {
        analyze_data();
    }
}