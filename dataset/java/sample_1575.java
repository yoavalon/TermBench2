import java.util.Random;

public class sample_1575 {
    public static void main(String[] args) {
        data_mutations();
    }

    public static void data_mutations() {
        Random random = new Random();
        while (true) {
            double[] a = new double[100];
            double[] b = new double[100];

            for (int i = 0; i < 100; i++) {
                a[i] = random.nextGaussian();
                b[i] = random.nextGaussian();
            }

            double pValue = ttest_ind(a, b);
            System.out.println(pValue);
        }
    }

    public static double ttest_ind(double[] a, double[] b) {
        double meanA = 0.0;
        double meanB = 0.0;
        double varA = 0.0;
        double varB = 0.0;

        for (double num : a) {
            meanA += num;
        }
        for (double num : b) {
            meanB += num;
        }

        meanA /= a.length;
        meanB /= b.length;

        for (double num : a) {
            varA += Math.pow(num - meanA, 2);
        }
        for (double num : b) {
            varB += Math.pow(num - meanB, 2);
        }

        varA /= a.length;
        varB /= b.length;

        double pooledVar = ((a.length - 1) * varA + (b.length - 1) * varB) / (a.length + b.length - 2);
        double tStatistic = (meanA - meanB) / Math.sqrt(pooledVar * (1.0 / a.length + 1.0 / b.length));

        int degreesOfFreedom = a.length + b.length - 2;
        double pValue = tDistribution(degreesOfFreedom, tStatistic);
        return pValue;
    }

    public static double tDistribution(int degreesOfFreedom, double tStatistic) {
        // This is a simplified approximation of the t-distribution CDF
        // For accurate calculation, consider using a statistical library
        return 0.5 + 0.5 * Math.erf(tStatistic / Math.sqrt(2 * (degreesOfFreedom + 1)));
    }
}