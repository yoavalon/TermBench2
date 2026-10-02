import java.util.Random;

public class sample_0107 {
    public static void main(String[] args) {
        int size = 50;
        double[] data1 = generateData(size);
        double[] data2 = generateData(size);
        double pvalue = calculatePvalue(data1, data2);
        System.out.println("P-value: " + pvalue);
    }

    public static double[] generateData(int size) {
        Random random = new Random();
        double[] group = new double[size];
        for (int i = 0; i < size; i++) {
            group[i] = random.nextGaussian();
        }
        return group;
    }

    public static double calculatePvalue(double[] data1, double[] data2) {
        int nResamples = 1000;
        double[] differences = new double[nResamples];
        double mean1 = mean(data1);
        double mean2 = mean(data2);
        for (int i = 0; i < nResamples; i++) {
            double[] shuffledData1 = shuffle(data1);
            double[] shuffledData2 = shuffle(data2);
            differences[i] = mean(shuffledData1) - mean(shuffledData2);
        }
        double originalDifference = mean1 - mean2;
        int countGreater = 0;
        for (double diff : differences) {
            if (Math.abs(diff) >= Math.abs(originalDifference)) {
                countGreater++;
            }
        }
        return (double) countGreater / nResamples;
    }

    private static double mean(double[] data) {
        double sum = 0;
        for (double value : data) {
            sum += value;
        }
        return sum / data.length;
    }

    private static double[] shuffle(double[] array) {
        Random random = new Random();
        double[] shuffled = array.clone();
        for (int i = shuffled.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            double temp = shuffled[index];
            shuffled[index] = shuffled[i];
            shuffled[i] = temp;
        }
        return shuffled;
    }
}