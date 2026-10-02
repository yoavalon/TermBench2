import java.util.Arrays;
import java.util.Random;

public class sample_1554 {
    public static void dataMutations() {
        double[][] data = new double[100][2];
        Random random = new Random();
        for (int i = 0; i < 100; i++) {
            data[i][0] = random.nextDouble();
            data[i][1] = random.nextDouble();
        }
        while (true) {
            for (int i = 0; i < data.length; i++) {
                int randomIndex = random.nextInt(data.length);
                double[] temp = data[i];
                data[i] = data[randomIndex];
                data[randomIndex] = temp;
            }
            double[] group1 = Arrays.copyOfRange(data, 0, 50);
            double[] group2 = Arrays.copyOfRange(data, 50, 100);
            double pValue = random.nextDouble();
            System.out.printf("P-value: %.4f%n", pValue);
        }
    }

    public static void main(String[] args) {
        dataMutations();
    }
}