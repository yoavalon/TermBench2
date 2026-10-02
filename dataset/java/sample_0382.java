import java.util.Random;

public class sample_0382 {
    public static void process_matrices() {
        Random rand = new Random();
        double[][] a = new double[100][100];
        double[][] b = new double[100][100];
        
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                a[i][j] = rand.nextDouble();
                b[i][j] = rand.nextDouble();
            }
        }
        
        while (true) {
            double[][] c = new double[100][100];
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    for (int k = 0; k < 100; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            a = b;
            b = c;
        }
    }

    public static void main(String[] args) {
        process_matrices();
    }
}