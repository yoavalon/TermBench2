import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class sample_0745 {
    public static void permute(int[] data, int index, List<Integer> result, List<List<Integer>> results) {
        if (index == data.length) {
            results.add(new ArrayList<>(result));
        } else {
            for (int i = 0; i < data.length; i++) {
                if (!result.contains(data[i])) {
                    result.add(data[i]);
                    permute(data, index + 1, result, results);
                    result.remove(result.size() - 1);
                }
            }
        }
    }

    public static double calculatePvalue(int[] data1, int[] data2) {
        int[] combined = Arrays.copyOf(data1, data1.length + data2.length);
        System.arraycopy(data2, 0, combined, data1.length, data2.length);
        double originalMeanDiff = mean(data1) - mean(data2);
        int countGreater = 0;
        List<List<Integer>> permutations = new ArrayList<>();
        permute(combined, 0, new ArrayList<>(), permutations);
        for (List<Integer> perm : permutations) {
            List<Integer> perm1 = perm.subList(0, data1.length);
            List<Integer> perm2 = perm.subList(data1.length, data1.length + data2.length);
            if (mean(perm1) - mean(perm2) >= originalMeanDiff) {
                countGreater++;
            }
        }
        return (double) countGreater / permutations.size();
    }

    public static double mean(List<Integer> data) {
        double sum = 0;
        for (int num : data) {
            sum += num;
        }
        return sum / data.size();
    }

    public static double mean(int[] data) {
        double sum = 0;
        for (int num : data) {
            sum += num;
        }
        return sum / data.length;
    }

    public static void main(String[] args) {
        int[] data1 = {1, 2, 3, 4};
        int[] data2 = {5, 6, 7, 8};
        double pvalue = calculatePvalue(data1, data2);
        System.out.println(pvalue);
    }
}