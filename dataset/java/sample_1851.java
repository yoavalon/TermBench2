import java.util.Random;

public class sample_1851 {
    public static double[][] forward_pass(double[][] weights, double[][] inputs) {
        int rows = weights.length;
        int cols = inputs[0].length;
        double[][] activations = new double[rows][cols];
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                activations[i][j] = 0;
                for (int k = 0; k < inputs.length; k++) {
                    activations[i][j] += weights[i][k] * inputs[k][j];
                }
            }
        }
        
        return activations;
    }

    public static void main(String[] args) {
        Random rand = new Random();
        double[][] a = new double[10][5];
        double[][] b = new double[5][3];
        
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = rand.nextDouble();
            }
        }
        
        for (int i = 0; i < b.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                b[i][j] = rand.nextDouble();
            }
        }
        
        double[][] c = forward_pass(a, b);
        
        for (double[] row : c) {
            for (double value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}