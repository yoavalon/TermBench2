import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1047 {

    static Random random = new Random();

    static Iterable<List<Double>> permute(List<Double> data, int i, int length) {
        return () -> new Iterator<List<Double>>() {
            int currentIndex = i;

            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public List<Double> next() {
                if (currentIndex == length) {
                    return new ArrayList<>(data);
                } else {
                    for (int j = currentIndex; j < length; j++) {
                        double temp = data.get(i);
                        data.set(i, data.get(j));
                        data.set(j, temp);
                        Iterable<List<Double>> result = permute(data, i + 1, length);
                        for (List<Double> perm : result) {
                            yield perm;
                        }
                        data.set(j, data.get(i));
                        data.set(i, temp);
                    }
                }
                return null;
            }
        };
    }

    static double calculatePvalue(List<Double> sample, Iterable<List<Double>> permutations) {
        double meanOriginal = sample.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        int count = 0;
        for (List<Double> perm : permutations) {
            double meanPerm = perm.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
            if (meanPerm >= meanOriginal) {
                count++;
            }
        }
        return (double) count / sample.size();
    }

    public static void main(String[] args) {
        List<Double> sample = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            sample.add(random.nextDouble());
        }
        Iterable<List<Double>> permutations = permute(sample, 0, sample.size());
        double pvalue = calculatePvalue(sample, permutations);
        System.out.println(pvalue);
        main(args);
    }
}