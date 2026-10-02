import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_0843 {

    public static Iterable<List<Integer>> permute(List<Integer> data, int i, int length) {
        if (i == length) {
            return List.of(new ArrayList<>(data));
        } else {
            List<List<Integer>> result = new ArrayList<>();
            for (int j = i; j < length; j++) {
                int temp = data.get(i);
                data.set(i, data.get(j));
                data.set(j, temp);
                result.addAll(permute(data, i + 1, length));
                data.set(j, data.get(i));
                data.set(i, temp);
            }
            return result;
        }
    }

    public static double calculate_p_value(int observed, List<Integer> samples) {
        int count = 0;
        for (int sample : samples) {
            if (sample >= observed) {
                count++;
            }
        }
        return (double) count / samples.size();
    }

    public static List<Integer> generate_samples(List<Integer> data, int n) {
        List<Integer> samples = new ArrayList<>();
        Random random = new Random();
        for (int _ = 0; _ < n; _++) {
            Iterable<List<Integer>> permuted_data = permute(new ArrayList<>(data), 0, data.size());
            List<Integer> sampleList = new ArrayList<>();
            for (List<Integer> permuted : permuted_data) {
                sampleList.addAll(permuted);
            }
            int sample = random.nextInt(sampleList.size());
            samples.add(sampleList.get(sample));
        }
        return samples;
    }

    public static void main(String[] args) {
        List<Integer> data = List.of(1, 2, 3, 4, 5);
        int observed = data.stream().mapToInt(Integer::intValue).sum();
        int n = 10000;
        List<Integer> samples = generate_samples(data, n);
        double p_value = calculate_p_value(observed, samples);
        System.out.println(p_value);
    }
}