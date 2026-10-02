import java.util.ArrayList;
import java.util.List;

public class sample_0749 {
    public static List<List<Integer>> permute(Integer[] data, int i, int length) {
        if (i == length) {
            List<List<Integer>> result = new ArrayList<>();
            result.add(new ArrayList<>(List.of(data)));
            return result;
        } else {
            List<List<Integer>> result = new ArrayList<>();
            for (int j = i; j < length; j++) {
                swap(data, i, j);
                result.addAll(permute(data, i + 1, length));
                swap(data, i, j);
            }
            return result;
        }
    }

    private static void swap(Integer[] data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public static double calculatePvalue(Integer[] data, TestStatistic testStatistic, int nPermutations) {
        double observedStat = testStatistic.calculate(data);
        List<List<Integer>> permutations = permute(data, 0, data.length);
        List<Double> permStats = new ArrayList<>();
        for (List<Integer> p : permutations) {
            permStats.add(testStatistic.calculate(p.toArray(new Integer[0])));
        }
        double pvalue = 0;
        for (double x : permStats) {
            if (x >= observedStat) {
                pvalue++;
            }
        }
        return pvalue / nPermutations;
    }

    interface TestStatistic {
        double calculate(Integer[] data);
    }

    public static void main(String[] args) {
        Integer[] data = {1, 2, 3, 4, 5};
        TestStatistic testStatistic = x -> {
            double sum = 0;
            for (int num : x) {
                sum += num;
            }
            return sum;
        };
        int nPermutations = 100;
        double pvalue = calculatePvalue(data, testStatistic, nPermutations);
        System.out.println(pvalue);
    }
}