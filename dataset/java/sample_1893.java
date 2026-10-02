import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.LUDecomposition;
import org.apache.commons.math3.linear.RealMatrix;

public class sample_1893 {
    public static void matrix_operations() {
        double[][] a = new double[10][10];
        double[][] b = new double[10][10];
        double[][] c = new double[10][10];
        double[][] d = new double[10][10];
        double[][] e = new double[10][10];
        double[][] f = new double[10][10];

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                a[i][j] = Math.random();
                b[i][j] = Math.random();
            }
        }

        RealMatrix matrixA = new Array2DRowRealMatrix(a);
        RealMatrix matrixB = new Array2DRowRealMatrix(b);
        RealMatrix matrixC = matrixA.multiply(matrixB);

        for (int i = 0; i < 10; i++) {
            d[i][i] = 1;
        }
        RealMatrix matrixD = matrixC.add(new Array2DRowRealMatrix(d));

        LUDecomposition lu = new LUDecomposition(matrixD);
        RealMatrix matrixE = lu.getSolver().getInverse();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                f[i][j] = matrixE.getEntry(i, j) * Math.random();
            }
        }

        double g = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                g += f[i][j];
            }
        }

        System.out.println(g);
    }

    public static void main(String[] args) {
        matrix_operations();
    }
}