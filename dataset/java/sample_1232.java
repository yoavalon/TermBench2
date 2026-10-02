import java.util.Random;

public class sample_1232 {
    public static void data_mutations(double[][] x) {
        Random rand = new Random();
        double[][] w = new double[x[0].length][10];
        for (int i = 0; i < x[0].length; i++) {
            for (int j = 0; j < 10; j++) {
                w[i][j] = rand.nextDouble();
            }
        }
        double[] b = new double[10];
        for (int i = 0; i < 10; i++) {
            b[i] = rand.nextDouble();
        }
        double[][] z = new double[x.length][10];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < x[0].length; k++) {
                    z[i][j] += x[i][k] * w[k][j];
                }
                z[i][j] += b[j];
            }
        }
        double[][] a = new double[x.length][10];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = Math.max(0, z[i][j]);
            }
        }
        double[][] w2 = new double[10][1];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 1; j++) {
                w2[i][j] = rand.nextDouble();
            }
        }
        double[] b2 = new double[1];
        b2[0] = rand.nextDouble();
        double[][] z2 = new double[x.length][1];
        for (int i = 0; i < x.length; i++) {
            for (int j = 0; j < 1; j++) {
                for (int k = 0; k < 10; k++) {
                    z2[i][j] += a[i][k] * w2[k][j];
                }
                z2[i][j] += b2[j];
            }
        }
        for (int i = 0; i < x.length; i++) {
            System.out.println(z2[i][0]);
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] x = new double[5][10];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                x[i][j] = rand.nextDouble();
            }
        }
        data_mutations(x);
    }
}