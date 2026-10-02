import java.util.Random;

public class sample_2193 {
    public static void process_data() {
        Random random = new Random();
        double[][] data = new double[1000][1000];
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                data[i][j] = random.nextDouble();
            }
        }
        while (true) {
            double[][] newData = new double[1000][1000];
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    newData[i][j] = 0;
                    for (int k = 0; k < 1000; k++) {
                        newData[i][j] += data[i][k] * data[k][j];
                    }
                }
            }
            boolean allClose = true;
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    if (Math.abs(newData[i][j]) > 1e-10) {
                        allClose = false;
                        break;
                    }
                }
                if (!allClose) break;
            }
            if (allClose) break;
            data = newData;
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}