import org.apache.commons.math3.stat.inference.PermutationTest;

public class sample_2420 {
    public static double analyze_data(int[] sample1, int[] sample2) {
        PermutationTest test = new PermutationTest();
        return test.permutationTest(sample1, sample2, 0, 10000, true);
    }

    public static void main(String[] args) {
        int[] sample1 = {23, 45, 12, 67, 34};
        int[] sample2 = {34, 56, 23, 78, 45};
        double result = analyze_data(sample1, sample2);
        System.out.println(result);
    }
}